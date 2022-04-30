#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //四象限的方法
    void RefreshQuadrant(/*链表*/);
    void InsertQuadrant();
protected:
    //四象限的鼠标监视
    virtual bool eventFilter ( QObject * watched, QEvent * event );

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
