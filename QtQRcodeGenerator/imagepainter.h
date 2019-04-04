#ifndef IMAGEPAINTER_H
#define IMAGEPAINTER_H

#include "patrolinfo.h"

#include <QObject>
#include <QImage>
#include <QColor>
#include <QFont>

class ImagePainter : public QObject
{
	Q_OBJECT

public:
	ImagePainter(QObject *parent = 0);
	~ImagePainter();

	void setSourceQRcodeImage(const QImage &sourceImage);

	bool makeQRcodeImage();

	void makeQRcodeImageWithData(const QString &data);

	bool makeLogoIamge(); // 60x60 with 5px space 

	void setId(const QString &id);

	void setSavingPath(const QString &path);

	bool isSavingPathExist(const QString path);

	void generateBGImage(const QSize &imageSize = QSize(300, 300), const QColor &color = QColor(255, 255, 255));

	void drawQRcode();

	void drawNewPlateQRcode();

	void drawLogoOnQRCode();

	void setQRCodeImageSize(const QSize &size);

	void drawText();

	bool saveImage();

	QString data() const;

	int drawSchoolName(const QString &name);

	void drawDescriptionInfo(int currentHeight);

	void drawPatrolInfo(const PatrolInfo &info);

	void setPaddings(int padding, int textPadding, int lineSpacing);

	void setDepartNameFont(const QFont &font);
	void setDescriptionFont(const QFont &font);
	void setPatrolInfoFont(const QFont &font);

private:
	int drawPatrolName(const QString &name);
	int drawPatrolPoepleInCharge(const QString &peopleInCharge, int height);
	int drawPatrolTimePeriod(const QString &startTime, const QString &endTime, int height);
	int drawPatrolWeekDays(const QString &weekDays, int height);
	int drawPatrolTimesPerDay(const QString &timesPerDay, int height);

private:
	QImage *m_backgroudImage;
	QImage *m_logoImage;
	QImage m_sourceImage;
	QString m_id;
	QString m_savingPath;
	QString m_data;

	int m_padding;
	int m_textPadding;
	int m_lineSpacing;

	QFont m_departNameFont;
	QFont m_descriptionFont;
	QFont m_patrolInfoFont;
};

#endif // IMAGEPAINTER_H
