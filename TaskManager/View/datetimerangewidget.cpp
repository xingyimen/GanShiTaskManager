#include "datetimerangewidget.h"
#include "ui_datetimerangewidget.h"

DateTimeRangeWidget::DateTimeRangeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DateTimeRangeWidget)
{
    ui->setupUi(this);
    int width = this->geometry().width();
    int height = this->geometry().height();
    this->setFixedSize(width,height); //设置窗体固定大小
}

DateTimeRangeWidget::~DateTimeRangeWidget()
{
    delete ui;
}


void DateTimeRangeWidget::initPage()
{
//	connect(ui->btnYes, &QPushButton::clicked, this, [this] {

//		QString start = ui->wdgStart->datetime();
//		QString end = ui->wdgEnd->datetime();

//		emit signal_dateTime(QString("%1 - %2").arg(start).arg(end));
//	});

//	connect(ui->btnCancel, &QPushButton::clicked, this, [this] {
//		emit signal_cancel();
//	});

//	QDateTime date = QDateTime::currentDateTime();
//	ui->wdgStart->setDateTime(date.addDays(-7).toString("yyyy-MM-dd hh:mm:ss"));
}
