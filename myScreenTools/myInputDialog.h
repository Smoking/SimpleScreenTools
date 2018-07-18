#ifndef MYINPUTDIALOG_H
#define MYINPUTDIALOG_H

#include<QDialog>
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>
#pragma execution_character_set("utf-8")
class myInputDialog : public QDialog
{
    Q_OBJECT
public:
    myInputDialog(QWidget* parent=0);
    int getWidth(){return width;}
    int getHeight(){return height;}

public slots:
    bool isOk();
    void get();
    void cancel();

private:
    QLabel *WLabel;
    QLineEdit* inputW;
    QLabel *HLabel;
    QLineEdit* inputH;
    QPushButton *okButton; // 确定
    QPushButton *noButton; // 取消

    int width, height; // 保存取得数据
};

#endif // MYINPUTDIALOG_H
