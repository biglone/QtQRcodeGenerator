#ifndef __QRCODEUTIL_H__
#define __QRCODEUTIL_H__

class QImage;
class QByteArray;
class QColor;

class QRCodeUtil
{
public:
	static bool getQRImage(QImage &qrImage, const QByteArray &text, int preScaler, const QColor &codeColor);
};

#endif // __QRCODEUTIL_H__
