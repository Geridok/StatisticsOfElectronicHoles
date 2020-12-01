#ifndef IMAGELABEL_H
#define IMAGELABEL_H
#include <QWidget>
#include <QLabel>
#include <QPixmap>
class ImageLabel : public QWidget
{
    Q_OBJECT

public:
    explicit ImageLabel(QWidget *parent = 0);
    const QPixmap* pixmap() const;

public slots:
    void setPixmap(const QPixmap&);

protected:
    void resizeEvent(QResizeEvent *);

private slots:
    void resizeImage();

private:
    QLabel *label;
};

// imagelabel.cpp

ImageLabel::ImageLabel(QWidget *parent) :
    QWidget(parent)
{
    label = new QLabel(this);
    label->setScaledContents(true);
    label->setFixedSize(0,0);
}

void ImageLabel::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);
    resizeImage();
}

const QPixmap* ImageLabel::pixmap() const {
    return label->pixmap();
}

void ImageLabel::setPixmap (const QPixmap &pixmap){
    label->setPixmap(pixmap);
    resizeImage();
}

void ImageLabel::resizeImage() {
    QSize pixSize = label->pixmap()->size();
    pixSize.scale(size(), Qt::KeepAspectRatio);
    label->setFixedSize(pixSize);
}
#endif // IMAGELABEL_H
