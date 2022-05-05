#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>
#include <QPieSeries>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPushButton>
#include "datashowdtl.h"
#include <QDebug>
#include "addpomodoro.h"
#include <QMouseEvent>
#include "myjsonobject.h"   //数据存储
#include <QStringList>

#include "linklist.h"
#include "quadrantitem.h"
#include "scheitem.h"
#include "workitem.h"
#include "mask.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //数据报表的方法
    int paintPie(QString cbuff = " ",int itemCount = 1);
    void Init();

    void AddQuadrant(int click_x,int click_y);
    void AddSchedule();
    void AddWorkTree();


public slots:
    void RefreshQuadrant();  //四象限的刷新
    void RefreshSchedule();  //日程的刷新
    void RefreshWorkTree();  //工作流的刷新

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


    QGraphicsScene* workScene;
    QGraphicsScene* scheScene;

};
#endif // MAINWINDOW_H
