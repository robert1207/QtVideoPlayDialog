

#ifndef CAPTURE_VIDEO_DIALOG_H
#define CAPTURE_VIDEO_DIALOG_H

#include <QApplication>
#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSlider>



#include "../../views/myvideowidget.h"
#include "../../views/myrangeslider.h"

class CaptureVideoDialog: public QDialog
{
    Q_OBJECT
public:
    explicit CaptureVideoDialog(QWidget *parent = nullptr);
    ~CaptureVideoDialog();

private:
    void SetupUI(QDialog *dialog);
    void RetranslateUi(QDialog *dialog);

private:


private slots:
    //函数名规则：on_子对象名_信号名


private:
    const int dialog_w_ = 280;
    const int dialog_h_ = 180;

private:

};

#endif // CAPTURE_VIDEO_DIALOG_H
