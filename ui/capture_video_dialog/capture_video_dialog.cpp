
#include "capture_video_dialog.h"


CaptureVideoDialog::CaptureVideoDialog(QWidget *parent) :
        QDialog(parent)
{
    SetupUI(this);

}

CaptureVideoDialog::~CaptureVideoDialog()
{

}


void CaptureVideoDialog::SetupUI(QDialog *dialog) {

    if (dialog->objectName().isEmpty())
               dialog->setObjectName(QString::fromUtf8("capturingDialog"));
    dialog->setWindowModality(Qt::NonModal);
    dialog->resize(dialog_w_, dialog_h_);

    //给主窗口设置 尺寸策略，为了内部布局可以跟着窗口一起扩展，需要用“Expanding”
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    dialog->setSizePolicy(sizePolicy);
    dialog->setMinimumSize(QSize(dialog_w_, dialog_h_));

    QVBoxLayout *main_v_layout;
    main_v_layout = new QVBoxLayout(dialog);//只有这个布局需要传入主窗口对象，表示这个布局是管理窗口的布局
    main_v_layout->setObjectName(QString::fromUtf8("verticalLayout"));
    main_v_layout->setSpacing(0);//设置布局内的布局与布局之间或控件与控件之间的距离
    main_v_layout->setContentsMargins(0, 0, 0, 0);//设置主窗口dialog与此主布局之间的margin

    QHBoxLayout *video_h_layout;
    video_h_layout = new QHBoxLayout();//其他的子布局 ，不要传入主窗口的对象
    video_h_layout->setObjectName(QString::fromUtf8("video_h_layout"));

    //video
    MyVideoWidget *my_video_widget_p;
    my_video_widget_p = new MyVideoWidget();
    my_video_widget_p->setObjectName(QString::fromUtf8("my_video_widget_p"));
   // QSizePolicy video_view_size_policy(QSizePolicy::Expanding, QSizePolicy::Expanding);
   // my_video_widget_p->setSizePolicy(video_view_size_policy);
    video_h_layout->addWidget(my_video_widget_p);

    QHBoxLayout *toolbar_h_layout;
    toolbar_h_layout = new QHBoxLayout();//其他的子布局 ，不要传入主窗口的对象
    toolbar_h_layout->setObjectName(QString::fromUtf8("horizontalLayout_2"));
    toolbar_h_layout->setSpacing(6); //设置控件与控件之间的距离
    toolbar_h_layout->setContentsMargins(6, 3, 6,3);//设置各个边单独的 margin距离

    //tool bar
    //range
    MyRangeSlider *myrange_slider_p;
    myrange_slider_p = new MyRangeSlider();//不需要传入父窗口对象
    myrange_slider_p->setObjectName(QString::fromUtf8("myrange_slider_p"));
    myrange_slider_p->setMaximumHeight(24);
    myrange_slider_p->setMinimumHeight(24);
    myrange_slider_p->setMinimumWidth(100);

    //tool bar rocord btn
    QPushButton *record_btn_p;
    record_btn_p = new QPushButton();//不需要传入父窗口对象
    record_btn_p->setObjectName(QString::fromUtf8("record_btn_p"));
    record_btn_p->setFocusPolicy(Qt::NoFocus);
    record_btn_p->setFlat(true);
    record_btn_p->setMinimumSize(QSize(28, 28));
    record_btn_p->setMaximumSize(QSize(28, 28));
    record_btn_p->setStyleSheet("QPushButton{border-image: url(:/img/image/record.png);}"
                                      "QPushButton:hover{border-image: url(:/img/image/rightcheck.png);}"
                                      "QPushButton:pressed{border-image: url(:/img/image/pause.png);}");

    //tool bar ok btn
    QPushButton *ok_btn_p;
    ok_btn_p = new QPushButton();//不需要传入父窗口对象
    ok_btn_p->setObjectName(QString::fromUtf8("ok_btn_p"));
    ok_btn_p->setMinimumSize(QSize(28,28));
    ok_btn_p->setMaximumSize(QSize(28, 28));
    ok_btn_p->setStyleSheet("QPushButton{border-image: url(:/img/image/record.png);}"
                                      "QPushButton:hover{border-image: url(:/img/image/rightcheck.png);}"
                                      "QPushButton:pressed{border-image: url(:/img/image/pause.png);}");

    toolbar_h_layout->addWidget(myrange_slider_p);
    toolbar_h_layout->addWidget(record_btn_p);
    toolbar_h_layout->addWidget(ok_btn_p);
    toolbar_h_layout->setStretch(0, 8);
    toolbar_h_layout->setStretch(1, 1);
    toolbar_h_layout->setStretch(2, 1);

    main_v_layout->addLayout(video_h_layout);
    main_v_layout->addLayout(toolbar_h_layout);
    //由于控件自己支持延展因此不需要如下设置
  //  main_v_layout->setStretch(0, 5);//设置第一个添加的布局的比例
   // main_v_layout->setStretch(1, 5);//设置第二个添加的布局的比例


    //直接把这两个背景分别设置到 video_h_layout 和 toolbar_h_layout
    //就可以看到 main_v_layout->setStretch的效果了
    /*
    QWidget *video_h_layout_bg = new QWidget();
    video_h_layout_bg->setObjectName("video_h_layout_bg");
    video_h_layout_bg->setProperty("video-bg", true);
    video_h_layout_bg->setStyleSheet("QWidget[video-bg=\"true\"] {background-color: #ff0000;}");
    video_h_layout->addWidget(video_h_layout_bg);


    QWidget *toolbar_h_layout_bg = new QWidget();
    toolbar_h_layout_bg->setObjectName("toolbar_h_layout_bg");
    toolbar_h_layout_bg->setProperty("toolbar-bg", true);
    toolbar_h_layout_bg->setStyleSheet("QWidget[toolbar-bg=\"true\"] {background-color: #00ff00;}");
    toolbar_h_layout->addWidget(toolbar_h_layout_bg);
    */



    RetranslateUi(dialog);

    QMetaObject::connectSlotsByName(dialog);
}

void CaptureVideoDialog::RetranslateUi(QDialog *dialog) {
    dialog->setWindowTitle(QApplication::translate("CaptureVideoDialog", "CaptureVideoDialog"));

}



