#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>
#include <QPieSeries>
#include <QGraphicsView>
#include <QPushButton>
#include "datashowdtl.h"

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
    //数据报表的方法
    int paintPie(QString cbuff = " ",int itemCount = 1);
    void Init();

private slots:
    void on_datagrambtn_clicked();
    void on_button_ptr_clicked();


protected:
    //四象限的鼠标监视
    virtual bool eventFilter ( QObject * watched, QEvent * event );


private:
    QVBoxLayout *layout;
    QHBoxLayout *layoutH;
    QChartView *chartView;
    QLabel* m_tooltip;
    QPushButton* button_ptr;
    QPushButton* button_dayChart;
    QPushButton* button_monChart;
    QPushButton* button_yearChart;
    dataShowDtl* dataShowdtl;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
