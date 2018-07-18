#include "myInputDialog.h"

#include<QMessageBox>
#include<QPainter>

myInputDialog::myInputDialog(QWidget *parent)
    : QDialog(parent)
{
    int width = 210, height = 120;
    this->setWindowTitle("设置范围");
    this->setFixedSize(width,height);

    resize(width,height);

    // width 设置标签
    WLabel = new QLabel(this);
    WLabel->setText("宽度: ");    WLabel->setGeometry(10,10,50,30);
    inputW = new QLineEdit(this);
    inputW->setGeometry(60,10,130,30);
    inputW->setFocus();

    // height 设置标签
    HLabel = new QLabel(this);
    HLabel->setText("高度: ");   HLabel->setGeometry(10,50,50,30);
    inputH = new QLineEdit(this);
    inputH->setGeometry(60,50,130,30);

    // 确定按钮
    okButton = new QPushButton(this);
    okButton->setText("确 定");
    okButton->setGeometry(10,90,75,23);

    // 取消按钮
    noButton = new QPushButton(this);
    noButton->setText("取 消");
    noButton->setGeometry(115,90,75,23);

    connect(okButton,SIGNAL(clicked()),this,SLOT(get()));
    connect(noButton,SIGNAL(clicked()),this,SLOT(cancel()));

    //默认是 0
    width = 0;
    height = 0;
}

void myInputDialog::get()
{
    if( inputW->text()!="" && inputH->text()!="" )
    {
        width = inputW->text().toInt();
        height = inputH->text().toInt();
        hide();
    }
    else  // 没输入数据时
    {
        QMessageBox::information(this,"提示","没有输入数据！");
    }
}

//取消时，并设值 -1 输入框清空
void myInputDialog::cancel()
{
    width = -1;
    height = -1;
    inputW->setText("");
    inputH->setText("");
    hide();
}

bool myInputDialog::isOk()
{
    bool b;
    if( inputW->text()!="" && inputH->text()!="" )
    {
        b=true;
    }
    // 为 -1 说明按了取消键
    else if( width==-1 && height==-1 )
    {
        width=0;
        height=0;
        b=false;
    }
    return b;
}
