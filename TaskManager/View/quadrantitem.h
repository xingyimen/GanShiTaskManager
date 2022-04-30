#ifndef QUADRANTITEM_H
#define QUADRANTITEM_H

#include <QWidget>

class QuadrantItem : public QWidget
{
    Q_OBJECT
public:
    explicit QuadrantItem(QWidget *parent = nullptr);
private:
    int emergency;
    int importance;
    QString name;
signals:

};

#endif // QUADRANTITEM_H
