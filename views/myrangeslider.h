#ifndef MYRANGESLIDER_H
#define MYRANGESLIDER_H

#include "qglobal.h"

#include <QtWidgets/qwidget.h>
#include <QPainter>
#include <QKeyEvent>


class MyRangeSlider : public QWidget
{
    Q_OBJECT
public:
    explicit MyRangeSlider(QWidget *parent);
    ~MyRangeSlider() override;

    MyRangeSlider();

signals:
    void onRangeChanged(float headRatio, float tailRatio);

protected:
    void paintEvent(QPaintEvent *) override;
     void mousePressEvent(QMouseEvent *) override;
    void mouseMoveEvent(QMouseEvent * ) override;
    void resizeEvent(QResizeEvent *event) override;
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;

private:
    void CalcRatio();
    void Init();

private:
    Q_DISABLE_COPY(MyRangeSlider)

    enum MoveType {
        None,
        Head,
        Tail
    };

    int border_line_wide_;
    int border_line_wide_half_;
    QColor boder_color_;
    QColor content_color_;

    int move_type_;
    int move_x_min_;
    int move_x_max_;

    int head_pos_;
    int tail_pos_;

    float head_ratio_;
    float tail_ratio_;

    int resize_length_;
    QRect content_rect_;


    const QColor active_color = QColor(0xffFF9FA0);
    const QColor inactive_color = QColor(0xffF39799);
};

#endif // MYRANGESLIDER_H
