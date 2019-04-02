#include "imagepainter.h"

#include "QRCodeUtil.h"

#include <QPainter>
#include <QDir>
#include <QPixmap>

ImagePainter::ImagePainter(QObject *parent)
	: QObject(parent), m_backgroudImage(0)
{
	generateBGImage();
	makeLogoIamge();
}

ImagePainter::~ImagePainter()
{

}

void ImagePainter::setSourceQRcodeImage(const QImage &sourceImage)
{
	m_sourceImage = sourceImage;
}

bool ImagePainter::makeQRcodeImage()
{
	QString base64Data = m_id.toLatin1().toBase64();
	m_data = QString("edu#patrol#");
	m_data.append(base64Data);
	QRCodeUtil::getQRImage(m_sourceImage, m_data.toUtf8(), 10, QColor("#000000"));

	if (m_sourceImage.isNull())
	{
		return false;
	}
	else
	{
		return true;
	}
}

void ImagePainter::makeQRcodeImageWithData(const QString &data)
{
	QRCodeUtil::getQRImage(m_sourceImage, data.toUtf8(), 10, QColor("#000000"));
	m_sourceImage.save("origine.png");
}

bool ImagePainter::makeLogoIamge()
{
	// create white background curtain
	QImage bgImage = QImage(QSize(70, 70), QImage::Format_RGBA8888);
	bgImage.fill(Qt::transparent);

	QPainter painter(&bgImage);
	
	painter.setPen(Qt::NoPen);
	painter.setBrush(Qt::white);
	painter.drawRoundedRect(bgImage.rect().adjusted(1, 1, -1, -1), 5, 5);

	QImage logoImage(":/images/logo.png");
	logoImage = logoImage.scaled(QSize(60, 60), Qt::KeepAspectRatio, Qt::SmoothTransformation);
	
	//draw logoImage on BG
	painter.drawImage(5,5, logoImage);

	m_logoImage = new QImage(bgImage);

	bgImage.save("temp.png");
	return true;
}

QString ImagePainter::data() const
{
	return m_data;
}

void ImagePainter::setId(const QString &id)
{
	m_id = id;
}

void ImagePainter::setSavingPath(const QString &path)
{
	if (path.isEmpty())
	{
		return;
	}

	m_savingPath = path;
}

bool ImagePainter::isSavingPathExist(const QString path)
{
	QDir dir(path);
	if (dir.exists())
	{
		return true;
	}
	else 
	{
		return false;
	}
}

void ImagePainter::generateBGImage(const QSize &imageSize, const QColor &color)
{
	m_backgroudImage = new QImage(imageSize, QImage::Format_RGBA8888);// 颜色支持透明度
	m_backgroudImage->fill(color);
}

void ImagePainter::drawQRcode()
{
	int padder = 10;
	QPainter painter(m_backgroudImage);
	QSize targetSize = m_backgroudImage->size();
	QSize scaledSize;

	// target image's height is larger.
	scaledSize.setWidth(targetSize.width() - padder * 2);
	scaledSize.setHeight(scaledSize.width());

	m_sourceImage = m_sourceImage.scaled(scaledSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

	QRect sourceRect(0, 0, scaledSize.width(), scaledSize.height());
	QRect targetRect(padder, padder, padder + scaledSize.width(), padder + scaledSize.height());
	
	painter.drawImage(QPoint(padder, padder), m_sourceImage);

	// darw logo on QRcode image
	int halfSourceWidth = m_backgroudImage->width()/2;
	int halfSourceHeight = m_backgroudImage->height()/2;
	painter.drawImage(halfSourceWidth - 35, halfSourceHeight - 35, *m_logoImage);

	QSize size = m_logoImage->size();
}

void ImagePainter::drawText()
{
	int padder = 10;
	QPainter painter(m_backgroudImage);

	QPen pen = painter.pen();
	pen.setColor(Qt::black);

	QFont font = painter.font();

	font.setBold(true);
	font.setPixelSize(20);

	painter.setPen(pen);
	painter.setFont(font);

	QRect rectText(padder, padder * 2 + m_sourceImage.height(), m_sourceImage.width(), 20);
	painter.drawText(rectText, Qt::AlignCenter, m_id);
}

bool ImagePainter::saveImage()
{
	if (!isSavingPathExist(m_savingPath))
	{
		return false;
	}

	QString name = m_id;
	if (name.isEmpty())
	{
		name = "temp";
	}

	QString filePath = m_savingPath;
	filePath.append("/");
	filePath.append(name);
	filePath.append(".png");
	return m_backgroudImage->save(filePath);
}