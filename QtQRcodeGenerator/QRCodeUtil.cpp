#include "QRCodeUtil.h"
#include "qrencode.h"
#include <QImage>
#include <QPixmap>
#include <QColor>
#include <QDebug>

// BMP defines
typedef unsigned short	WORD;
typedef unsigned long	DWORD;
typedef signed long		LONG;

#define BI_RGB			0L

#pragma pack(push, 2)

typedef struct  
{
	WORD    bfType;
	DWORD   bfSize;
	WORD    bfReserved1;
	WORD    bfReserved2;
	DWORD   bfOffBits;
} BITMAPFILEHEADER;

typedef struct 
{
	DWORD      biSize;
	LONG       biWidth;
	LONG       biHeight;
	WORD       biPlanes;
	WORD       biBitCount;
	DWORD      biCompression;
	DWORD      biSizeImage;
	LONG       biXPelsPerMeter;
	LONG       biYPelsPerMeter;
	DWORD      biClrUsed;
	DWORD      biClrImportant;
} BITMAPINFOHEADER;

#pragma pack(pop)
//	-------------------------------------------------------

bool QRCodeUtil::getQRImage(QImage &qrImage, const QByteArray &text, int preScaler, const QColor &codeColor)
{
	const char*     szSourceSring = text.constData();
	unsigned int	unWidth, x, y, l, n, unWidthAdjusted, unDataBytes;
	unsigned char*	pRGBData, *pSourceData, *pDestData, *pBmpData;
	QRcode*			pQRC;

	// Compute QRCode
	if (pQRC = QRcode_encodeString(szSourceSring, 0, QR_ECLEVEL_M, QR_MODE_8, 1))
	{
		unWidth = pQRC->width;
		unWidthAdjusted = unWidth * preScaler * 3;
		if (unWidthAdjusted % 4)
			unWidthAdjusted = (unWidthAdjusted / 4 + 1) * 4;
		unDataBytes = unWidthAdjusted * unWidth * preScaler;

		// Allocate pixels buffer
		if (!(pRGBData = (unsigned char*)malloc(unDataBytes)))
		{
			qWarning() << "rgb data out of memory";
			QRcode_free(pQRC);
			return false;
		}

		// Preset to white
		memset(pRGBData, 0xff, unDataBytes);

		// Prepare bmp headers
		BITMAPFILEHEADER kFileHeader;
		kFileHeader.bfType = 0x4d42;  // "BM"
		kFileHeader.bfSize =	sizeof(BITMAPFILEHEADER) +
			sizeof(BITMAPINFOHEADER) +
			unDataBytes;
		kFileHeader.bfReserved1 = 0;
		kFileHeader.bfReserved2 = 0;
		kFileHeader.bfOffBits =	sizeof(BITMAPFILEHEADER) +
			sizeof(BITMAPINFOHEADER);

		BITMAPINFOHEADER kInfoHeader;
		kInfoHeader.biSize = sizeof(BITMAPINFOHEADER);
		kInfoHeader.biWidth = unWidth * preScaler;
		kInfoHeader.biHeight = -((int)unWidth * preScaler);
		kInfoHeader.biPlanes = 1;
		kInfoHeader.biBitCount = 24;
		kInfoHeader.biCompression = BI_RGB;
		kInfoHeader.biSizeImage = 0;
		kInfoHeader.biXPelsPerMeter = 0;
		kInfoHeader.biYPelsPerMeter = 0;
		kInfoHeader.biClrUsed = 0;
		kInfoHeader.biClrImportant = 0;

		// Convert QrCode bits to bmp pixels
		pSourceData = pQRC->data;
		for(y = 0; y < unWidth; y++)
		{
			pDestData = pRGBData + unWidthAdjusted * y * preScaler;
			for(x = 0; x < unWidth; x++)
			{
				if (*pSourceData & 1)
				{
					for(l = 0; l < preScaler; l++)
					{
						for(n = 0; n < preScaler; n++)
						{
							*(pDestData +		n * 3 + unWidthAdjusted * l) =	codeColor.blue();
							*(pDestData + 1 +	n * 3 + unWidthAdjusted * l) =	codeColor.green();
							*(pDestData + 2 +	n * 3 + unWidthAdjusted * l) =	codeColor.red();
						}
					}
				}
				pDestData += 3 * preScaler;
				pSourceData++;
			}
		}

		// Allocate bmp file buffer
		if (!(pBmpData = (unsigned char*)malloc(sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER)+unDataBytes)))
		{
			qWarning() << "bmp file out of memory";
			free(pRGBData);
			QRcode_free(pQRC);
			return false;
		}

		// Output the bmp data
		memcpy(pBmpData, &kFileHeader, sizeof(BITMAPFILEHEADER));
		memcpy(pBmpData+sizeof(BITMAPFILEHEADER), &kInfoHeader, sizeof(BITMAPINFOHEADER));
		memcpy(pBmpData+sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER), pRGBData, unDataBytes);

		// change to QImage
		QImage image = QImage::fromData(pBmpData, sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER)+unDataBytes, "BMP");
		qrImage = image;

		// Free data
		free(pRGBData);
		free(pBmpData);
		QRcode_free(pQRC);

		if (image.isNull())
		{
			qWarning() << "load bmp failed.";
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		qWarning() << "QR code encode failed.";
		return false;
	}
}
