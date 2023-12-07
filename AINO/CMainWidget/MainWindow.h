#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "DBAccesser.h"
#include "CSystemInfoBar.h"
#include "commondefine.h"


#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    //初始化界面
    void initUI();

    //初始化导航栏点击响应
    void initNavitationBar();

    void connectManager();

    void initQCPageConnection();

private:
    Ui::MainWindow *ui;



private:
};
#endif // MAINWINDOW_H
