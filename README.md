# Qt对话框的自适应动态布局（布局跟随窗口大小改变）
## 一、效果图
![demo_video](https://github.com/robert1207/QtVideoPlayDialog/blob/master/doc/demo_video.gif)
## 二、制作原理说明
要想实现对话框缩放时候内部的控件跟着动态缩放。需要以下几个关键设置：
1. 给对话框窗口设置一个布局，以后窗口靠这个布局管理
2. 给对话框窗口设置QSizePolicy为Expanding
3. 窗口内包含的控件都设置QSizePolicy::Expanding属性，或自定义控件覆盖resizeEvent来保持自定义控件动态填满父布局。layout不用设置Expanding属性。
4. 对话框窗口设置setMinimumSize
## 三、自定义跟随父布局缩放的控件
本例子中自己实现了两个自定义控件，分别是：
MyVideoWidget：显示视频或图片的控件
MyRangeSlider：调节裁剪范围的控件
这两个控件都重新实现了resizeEvent方法。因此这两个控件，默认就会填满父布局。会跟着父布局扩展而扩展
## 四、在伸缩动态布局中，保持按钮不变形
在本例子中有两个按钮分别设置了图片背景。以实现自己需要的按钮造型。按钮配图片的方法为：
```
record_btn_p->setStyleSheet("QPushButton{border-image: url(:/img/image/record.png);}"
		"QPushButton:hover{border-image: url(:/img/image/rightcheck.png);}"
		"QPushButton:pressed{border-image: url(:/img/image/pause.png);}");
```
设置完按钮发现按钮会随着缩放变形，导致很难看。并且设置setGeometry并不管用。
设置按钮的sizePolicy为Fixed也没有用。经过测试发现，最终的固定按钮尺寸的方法为：
```
record_btn_p->setMinimumSize(QSize(28, 28));
record_btn_p->setMaximumSize(QSize(28, 28));
```
当需要只设置垂直方向固定，则需要如下配置：
```
myrange_slider_p->setMaximumHeight(24);
myrange_slider_p->setMinimumHeight(24);
```
当需要只设置水平方向固定，则需要如下配置：
```
myrange_slider_p->setMinimumWidth(100);
myrange_slider_p->setMaximumWidth(100);
```
