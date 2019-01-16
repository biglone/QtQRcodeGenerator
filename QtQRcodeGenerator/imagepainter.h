#ifndef IMAGEPAINTER_H
#define IMAGEPAINTER_H

#include <QObject>
#include <QImage>
#include <QColor>

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

	void drawText();

	bool saveImage();

	QString data() const;
private:
	QImage *m_backgroudImage;
	QImage *m_logoImage;
	QImage m_sourceImage;
	QString m_id;
	QString m_savingPath;
	QString m_data;
};

#endif // IMAGEPAINTER_H
