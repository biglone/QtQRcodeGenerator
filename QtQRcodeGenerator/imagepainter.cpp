#include "imagepainter.h"

#include "QRCodeUtil.h"

#include <QPainter>
#include <QDir>
#include <QPixmap>
#include <QFontMetrics>

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

void ImagePainter::drawLogoOnQRCode()
{
	QPainter painter(&m_sourceImage);
	QSize sourceIamgeSize = m_sourceImage.size();
	QSize logSize = m_logoImage->size();

	QPoint startPoint;
	startPoint.setX((sourceIamgeSize.width() - logSize.width()) / 2); 
	startPoint.setY((sourceIamgeSize.height() - logSize.height()) / 2);
	painter.drawImage(startPoint, *m_logoImage);

	//m_sourceImage.save("qrcode.png");
}

void ImagePainter::setQRCodeImageSize(const QSize &size)
{
	m_sourceImage = m_sourceImage.scaled(size, Qt::KeepAspectRatio, Qt::SmoothTransformation);
}

void ImagePainter::drawNewPlateQRcode(const QPoint &startPoint)
{
	QPainter painter(m_backgroudImage);
	painter.drawImage(startPoint, m_sourceImage);
	//m_backgroudImage->save("step1.png");
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

int ImagePainter::drawSchoolName(const QString &name)
{
	// set text font and size
	QFont font("Microsoft YaHei", 12);
	font.setBold(true);
	QPainter painter(m_backgroudImage);
	painter.setFont(font);

	QFontMetrics fontMetrics(font);
	
	int flags = Qt::TextWordWrap | Qt::AlignCenter;

	QRect textRect = fontMetrics.boundingRect(10, 330, 300, 0, flags, name);
	//textRect.adjust(0, 0, 0, 10);
	painter.drawText(textRect, flags, name);

	//m_backgroudImage->save("step2.png");

	return textRect.bottom();
}

void ImagePainter::drawDescriptionInfo(int currentHeight)
{
	QString info = tr("patrol description");
	QFont font("Microsoft YaHei", 12);
	font.setBold(true);
	QPainter painter(m_backgroudImage);
	painter.setFont(font);

	QFontMetrics fontMetrics(font);

	int flags = Qt::AlignLeft | Qt::TextWordWrap;
	QRect textRect = fontMetrics.boundingRect(10, currentHeight + 10, m_backgroudImage->width() - 20, 0, flags, info);

	painter.drawText(textRect, flags, info);

	//m_backgroudImage->save("step3.png");
}

void ImagePainter::drawPatrolInfo(const PatrolInfo &info)
{
	int currentHeight = drawPatrolName(info.patrolName());
	currentHeight = drawPatrolPoepleInCharge(info.peopleInCharge(), currentHeight);
	currentHeight = drawPatrolTimePeriod(info.startTime(), info.endTime(), currentHeight);
	currentHeight = drawPatrolWeekDays(info.weekDays(), currentHeight);
	currentHeight = drawPatrolTimesPerDay(info.patrolTimesPerDay(), currentHeight);
}

int ImagePainter::drawPatrolName(const QString &name)
{
	QString patrolPoint = tr("patrolPoint: ");
	patrolPoint.append(name);

	QFont font("Microsoft YaHei", 12);
	font.setBold(true);
	QPainter painter(m_backgroudImage);
	painter.setFont(font);

	QFontMetrics fontMetrics(font);

	int flags = Qt::AlignLeft | Qt::TextWordWrap;
	QRect textRect = fontMetrics.boundingRect(10 + 300 + 10, 10, m_backgroudImage->width() - 20 - 300, 0, flags, patrolPoint);
	
	painter.drawText(textRect, flags, patrolPoint);

	//m_backgroudImage->save("step4.png");

	int currentHeight = textRect.bottom();
	return currentHeight;
}

int ImagePainter::drawPatrolPoepleInCharge(const QString &peopleInCharge, int height)
{
	QString nameOfPeopleInCharge = tr("people in charge: ");
	nameOfPeopleInCharge.append(peopleInCharge);

	QFont font("Microsoft YaHei", 12);
	font.setBold(true);
	QPainter painter(m_backgroudImage);
	painter.setFont(font);

	QFontMetrics fontMetrics(font);

	int flags = Qt::AlignLeft | Qt::TextWordWrap;
	QRect textRect = fontMetrics.boundingRect(10 + 300 + 10, height + 10, m_backgroudImage->width() - 20 - 300, 0, flags, nameOfPeopleInCharge);

	painter.drawText(textRect, flags, nameOfPeopleInCharge);

	//m_backgroudImage->save("step5.png");

	int currentHeight = textRect.bottom();
	return currentHeight;
}

int ImagePainter::drawPatrolTimePeriod(const QString &startTime, const QString &endTime, int height)
{
	QString timePeriod = tr("time period: ");
	timePeriod.append(startTime);
	timePeriod.append("-");
	timePeriod.append(endTime);

	QFont font("Microsoft YaHei", 12);
	font.setBold(true);
	QPainter painter(m_backgroudImage);
	painter.setFont(font);

	QFontMetrics fontMetrics(font);

	int flags = Qt::AlignLeft | Qt::TextWordWrap;
	QRect textRect = fontMetrics.boundingRect(10 + 300 + 10, height + 10, m_backgroudImage->width() - 20 - 300, 0, flags, timePeriod);

	painter.drawText(textRect, flags, timePeriod);

	//m_backgroudImage->save("step6.png");
	int currentHeight = textRect.bottom();
	return currentHeight;
}

int ImagePainter::drawPatrolWeekDays(const QString &weekDays,  int height)
{
	QString patrolWeekDays = tr("patrol cycle: ");
	QStringList numberDays = weekDays.split(",");
	QStringList weekDaysChinese;

	if (5 == numberDays.count())
	{
		patrolWeekDays.append(tr("Monday to Friday"));
	}
	else
	{
		foreach(QString day, numberDays)
		{
			if (QStringLiteral("1") == day)
			{
				weekDaysChinese.append(tr("Monday"));
			}
			else if (QStringLiteral("2") == day)
			{
				weekDaysChinese.append(tr("Tuesday"));
			}
			else if (QStringLiteral("3") == day)
			{
				weekDaysChinese.append(tr("Wednesday"));
			}
			else if	(QStringLiteral("4") == day)
			{
				weekDaysChinese.append(tr("Thursday"));
			}
			else if (QStringLiteral("5") == day)
			{
				weekDaysChinese.append(tr("Friday"));
			}
		}

		patrolWeekDays.append(weekDaysChinese.join(", "));
	}

	QFont font("Microsoft YaHei", 12);
	font.setBold(true);
	QPainter painter(m_backgroudImage);
	painter.setFont(font);

	QFontMetrics fontMetrics(font);

	int flags = Qt::AlignLeft | Qt::TextWordWrap;
	QRect textRect = fontMetrics.boundingRect(10 + 300 + 10, height + 10, m_backgroudImage->width() - 20 - 300, 0, flags, patrolWeekDays);

	painter.drawText(textRect, flags, patrolWeekDays);

	//m_backgroudImage->save("step7.png");
	int currentHeight = textRect.bottom();
	return currentHeight;
}

int ImagePainter::drawPatrolTimesPerDay(const QString &timesPerDay, int height)
{
	QString patrolTimesPerDay = tr("patrol times per day: ");
	patrolTimesPerDay.append(timesPerDay);
	patrolTimesPerDay.append(tr("times"));

	QFont font("Microsoft YaHei", 12);
	font.setBold(true);
	QPainter painter(m_backgroudImage);
	painter.setFont(font);

	QFontMetrics fontMetrics(font);

	int flags = Qt::AlignLeft | Qt::TextWordWrap;
	QRect textRect = fontMetrics.boundingRect(10 + 300 + 10, height + 10, m_backgroudImage->width() - 20 - 300, 0, flags, patrolTimesPerDay);

	painter.drawText(textRect, flags, patrolTimesPerDay);

	//m_backgroudImage->save("step8.png");
	int currentHeight = textRect.bottom();
	return currentHeight;
}

