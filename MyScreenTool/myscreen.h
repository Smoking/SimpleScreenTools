#ifndef MYSCREEN_H
#define MYSCREEN_H

#include "QPainter"
#include "QSize"

/*解决中文编码问题*/
#pragma execution_character_set("utf-8")

/*枚举三种状态选择，移动，和设置截屏窗口的大小*/
enum STATUS{SELECT,MOV,SET_W_H};

class MyScreen
{
public:
    /*设置构造函数*/
    MyScreen() {}
    MyScreen(QSize size);

    /*设置截图的起点和终点*/
    void setStart(QPoint pos);
    void setEnd(QPoint pos);
    QPoint getStart();
    QPoint getEnd();

    /*屏幕的左右极值坐标，为后面控制截屏的移动，防止溢出屏幕*/
    QPoint getLeftUp();
    QPoint getRightDown();

    STATUS getStatus();
    void setStatus(STATUS st);

    /*实现判断是否可以移动*/
    int width();
    int height();
    bool isInArea(QPoint pos); // 检测pos是否在截图区域内
    void move(QPoint p);       // 按 p 移动截图区域


private:
    /* 记录 截图区域 左上角、右下角*/
    QPoint leftUpPos;
    QPoint rightDownPos;

    /*记录 鼠标开始位置、结束位置*/
    QPoint startPos;
    QPoint endPos;

    /*记录 鼠标开始位置、结束位置*/
    int maxWidth, maxHeight;


    /*三个状态 :  选择区域、移动区域、设置width height*/
    STATUS status;

    /*比较两位置，重新设置左上角、右下角*/
    void cmpPoint(QPoint &s, QPoint &e);
};

#endif // MYSCREEN_H
