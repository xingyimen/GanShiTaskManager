#ifndef QUADITEM_H
#define QUADITEM_H

#include <QWidget>

namespace Ui {
class QuadItem;
}

class QuadItem : public QWidget
{
    Q_OBJECT

public:
    explicit QuadItem(QWidget *parent = nullptr);
    ~QuadItem();

private:
    Ui::QuadItem *ui;
};

#endif // QUADITEM_H
