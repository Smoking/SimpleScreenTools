#ifndef SHOWMAIN_H
#define SHOWMAIN_H

#define WIDTH_SHOW 340
#define HEIGHT_SHOW 30

#include <QWidget>
#include <QSystemTrayIcon>
#include<QtGui>
#include<QPixmap>
#include<QPainter>
#include<QPoint>
#include<QLabel>
#include<QPixmap>
#include<QLineEdit>

#include "myScreen.h"

/*设置中文编码为utf-8*/
#pragma execution_character_set("utf-8")

namespace Ui {
class ShowMain;
}

class ShowMain : public QWidget
{
    Q_OBJECT

public:
    explicit ShowMain(QWidget *parent = 0);
    ~ShowMain();

private:
    Ui::ShowMain *ui;


    MyScreen *cutScreen;      // RCutScreen对象,记录x y w h 数据
    QPixmap *infoPix;         // 截图信息显示背景
    QPixmap *fullScreen;      // 保存全屏图像
    QPixmap *bgScreen;        // 模糊背景图
    QPoint movPos;

protected:

    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void keyReleaseEvent(QKeyEvent *);
    void paintEvent(QPaintEvent *);


private slots:
    /*设置窗口托盘点击激活信号*/
    void trayIconActivated(QSystemTrayIcon::ActivationReason activationReason);
    void activeTray(QSystemTrayIcon::ActivationReason reason);//将单击事件给占了防止干扰

private:
    void saveScreen();//保存截图
    void saveFullScreen();//保存全屏
    QSystemTrayIcon *trayIcon;//设置系统托盘
};

#endif // SHOWMAIN_H
