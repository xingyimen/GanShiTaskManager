#include "titlelabel.h"
#include <QPalette>
TitleLabel::TitleLabel(QWidget *parent)
    : QLabel{parent}
{

    QFont ft;
    ft.setPointSize(20);
    ft.setFamily("幼圆");
    ft.setBold(QFont::Bold);
    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::white);
    setFont(ft);
    setPalette(pe);

}
