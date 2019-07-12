#include "myrangeslider.h"

MyRangeSlider::MyRangeSlider(QWidget *parent)
    : QWidget (parent)
{
    Init();
}

MyRangeSlider::MyRangeSlider() {
    Init();
}

MyRangeSlider::~MyRangeSlider() {

}

void MyRangeSlider::Init() {
    border_line_wide_ = 2;
    border_line_wide_half_ = border_line_wide_ / 2;
    boder_color_  =  QColor(Qt::gray);
    content_color_ = inactive_color;
    resize_length_ = 10;
    head_ratio_ = 0.0;
    tail_ratio_ = 1.0;
}

void MyRangeSlider::resizeEvent(QResizeEvent *event) {
    Q_UNUSED(event);
    content_rect_  = this->rect().adjusted(border_line_wide_half_, border_line_wide_half_,
                                                     -border_line_wide_half_, -border_line_wide_half_);
    move_x_min_ = content_rect_.x();
    move_x_max_ = content_rect_.x() + content_rect_.width(); //y2 of content_rect

    head_pos_ = content_rect_.x() + static_cast<int>(head_ratio_ * content_rect_.width());
    tail_pos_ = content_rect_.x() + static_cast<int>(tail_ratio_ * content_rect_.width());
}

void MyRangeSlider::paintEvent(QPaintEvent *event) {

    Q_UNUSED(event);
    QPainter painter(this);

    //draw view border
    painter.setPen(QPen(boder_color_, border_line_wide_));
    QRect frame_rect = this->rect();
    painter.drawRect(frame_rect);

    //draw move block
    QRect move_block = QRect(head_pos_, content_rect_.y(),
                             tail_pos_ - head_pos_, content_rect_.height());
    painter.fillRect(move_block, QBrush(content_color_));

    //draw mark line
    int mark_line_lr_margin = 6;
    int mark_line_ud_margin = 4;

    QPoint point_h_1 = QPoint(head_pos_ + mark_line_lr_margin, content_rect_.y() + mark_line_ud_margin);
    QPoint point_h_2 = QPoint(head_pos_ + mark_line_lr_margin, content_rect_.y()+content_rect_.height() - mark_line_ud_margin);
    QPoint point_t_1 = QPoint(tail_pos_ - mark_line_lr_margin, content_rect_.y() + mark_line_ud_margin);
    QPoint point_t_2 = QPoint(tail_pos_ - mark_line_lr_margin, content_rect_.y()+content_rect_.height() - mark_line_ud_margin);

    painter.drawLine(point_h_1, point_h_2);
    painter.drawLine(point_t_1, point_t_2);

}

void MyRangeSlider::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {

        QRect left_resize_rect = QRect(head_pos_, content_rect_.y(),
                                                            resize_length_, content_rect_.height());
        QRect right_resize_rect = QRect(tail_pos_ - resize_length_, content_rect_.y(),
                                        tail_pos_, content_rect_.height());

        QPoint press_pos = event->pos();

        if (left_resize_rect.contains(press_pos)) { //adjsut head
            move_type_ = MoveType::Head;
        } else if (right_resize_rect.contains(press_pos)) { //adjust tail
            move_type_ = MoveType::Tail;
        } else {
            move_type_ = MoveType::None;
        }
    }
}

void MyRangeSlider::mouseMoveEvent(QMouseEvent *event) {

    QPoint cursor_pos_at_widget = event->pos();

    if (move_type_ == MoveType::Head) { //adjsut head

        head_pos_ = cursor_pos_at_widget.x();
        if (head_pos_ < move_x_min_) {
            head_pos_ = move_x_min_;
        }

        if(head_pos_ > (tail_pos_ - resize_length_*2)) {
            head_pos_ = tail_pos_ - resize_length_*2;
        }
        update();
        CalcRatio();
    } else if (move_type_ == MoveType::Tail) { //adjust tail
        tail_pos_ = cursor_pos_at_widget.x();
        if(tail_pos_ > move_x_max_) {
            tail_pos_ = move_x_max_;
        }
        if(tail_pos_  < (head_pos_ + resize_length_*2)) {
            tail_pos_  = (head_pos_ + resize_length_*2);
        }
        update();
        CalcRatio();
    }
}

void MyRangeSlider::enterEvent(QEvent *event) {
    Q_UNUSED(event);
    content_color_ = active_color;
    update();
}

void MyRangeSlider::leaveEvent(QEvent *event) {
    Q_UNUSED(event);
    content_color_ = inactive_color;
    update();
}

void MyRangeSlider::CalcRatio() {
    head_ratio_ = static_cast<float>(head_pos_) / static_cast<float>(content_rect_.width());
    tail_ratio_ = static_cast<float>(tail_pos_) / static_cast<float>(content_rect_.width());

    emit onRangeChanged(head_ratio_, tail_ratio_);
}

