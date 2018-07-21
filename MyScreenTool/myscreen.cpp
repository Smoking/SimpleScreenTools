#include "myscreen.h"

MyScreen::MyScreen(QSize size)
{
    /*设置屏幕大小*/
    maxWidth = size.width();
    maxHeight = size.height();

    //初始化截屏状态
    startPos = QPoint(-1,-1);
    endPos = startPos;
    leftUpPos = startPos;
    rightDownPos = startPos;
    status = SELECT;
}

int MyScreen::width()
{
    return maxWidth;
}

int MyScreen::height()
{
    return maxHeight;
}

STATUS MyScreen::getStatus()
{
    return status;
}

void MyScreen::setStatus(STATUS st)
{
    status=st;
}

void MyScreen::setEnd(QPoint pos)
{
    endPos = pos;
    //此时调用cmpPoint，设置区域的左上角、右下角
    leftUpPos = startPos;
    rightDownPos = endPos;
    cmpPoint(leftUpPos,rightDownPos);
}

void MyScreen::setStart(QPoint pos)
{
    startPos=pos;
}

QPoint MyScreen::getEnd()
{
    return endPos;
}

QPoint MyScreen::getStart()
{
    return startPos;
}

QPoint MyScreen::getLeftUp()
{
    return leftUpPos;
}

QPoint MyScreen::getRightDown()
{
    return rightDownPos;
}
/****************************************
*
*在区域内返回true 否则 false
*
****************************************/
bool MyScreen::isInArea(QPoint pos)
{
    if( pos.x() > leftUpPos.x() && pos.x() < rightDownPos.x()\
      &&pos.y() > leftUpPos.y() && pos.y() < rightDownPos.y() )
        {
            return true;
        }
    return false;
}
/****************************************
*
*按 p移动截图区域
*
****************************************/
void MyScreen::move(QPoint p)
{
    int lx = leftUpPos.x() + p.x();
    int ly = leftUpPos.y() + p.y();
    int rx = rightDownPos.x() + p.x();
    int ry = rightDownPos.y() + p.y();

    if( lx<0 ) { lx = 0; rx -= p.x(); }  // 当到最左边时、区域不再移动
    if( ly<0 ) { ly = 0; ry -= p.y(); }  // 最上
    if( rx>maxWidth )  { rx = maxWidth; lx -= p.x(); }  //最右
    if( ry>maxHeight ) { ry = maxHeight; ly -= p.y(); } //最下

    leftUpPos = QPoint(lx,ly);
    rightDownPos = QPoint(rx,ry);
    startPos = leftUpPos; // 重新设置起始点
    endPos = rightDownPos;
}

/****************************************
*
*比较两坐标，判断相对位置，左上角写到leftTop
*右下角写到rightDown
*
****************************************/
void MyScreen::cmpPoint(QPoint& leftTop,QPoint& rightDown)
{
    QPoint l = leftTop;
    QPoint r = rightDown;

    if( l.x()<=r.x()  )  //起点在终点左侧
    {
        if( l.y()<=r.y() ) //左上
        {
            ;
        }
        else              //左下
        {
            leftTop.setY(r.y());
            rightDown.setY(l.y());
        }
    }
    else                //在右侧
    {
        if( l.y()<r.y() ) //右上
        {
            leftTop.setX(r.x());
            rightDown.setX(l.x());
        }
        else             //右下
        {
            QPoint tmp;
            tmp = leftTop;
            leftTop = rightDown;
            rightDown = tmp;
        }
    }
}

