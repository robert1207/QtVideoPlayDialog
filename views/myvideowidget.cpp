#include "myvideowidget.h"


MyVideoWidget::MyVideoWidget(QWidget *parent)
    : QLabel (parent)
{

}


MyVideoWidget::MyVideoWidget() {


}


MyVideoWidget::~MyVideoWidget() {


}

void MyVideoWidget::resizeEvent(QResizeEvent *event) {
    Q_UNUSED(event);

    content_rect_  = this->rect();

    //todo: get current pixmap and scale it
    QPixmap pixmap = QPixmap(content_rect_.width(), content_rect_.height());
    pixmap.fill(QColor(121, 121, 121));
    this->setPixmap(pixmap);

}

QRect MyVideoWidget::GetVideoRect() {

    return content_rect_;
}

void MyVideoWidget::SetVideoPixmap(QPixmap &pixmap) {
    pixmap_ = pixmap;
}

