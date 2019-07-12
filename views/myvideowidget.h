#ifndef MYVIDEOWIDGET_H
#define MYVIDEOWIDGET_H

#include <QLabel>
#include <QRect>
#include <QPixmap>
#include <QResizeEvent>
#include <QWidget>


class MyVideoWidget : public QLabel
{
    Q_OBJECT
public:
    explicit MyVideoWidget(QWidget *parent);
    ~MyVideoWidget() override;

   MyVideoWidget();


    QRect GetVideoRect();
    void SetVideoPixmap(QPixmap &pixmap);

protected:
    void resizeEvent(QResizeEvent *event) override;


private:
   Q_DISABLE_COPY(MyVideoWidget)

    QRect content_rect_;
    QPixmap pixmap_;
};

#endif // MYVIDEOWIDGET_H
