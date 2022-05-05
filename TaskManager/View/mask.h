#ifndef MASK_H
#define MASK_H

#include <QWidget>

class Mask : public QWidget
{
    Q_OBJECT
public:
    explicit Mask(QWidget *parent = nullptr);
    ~Mask();
    void setRect(QRect);


protected:
    virtual void mousePressEvent(QMouseEvent *event);

private:
    QRect rec;
signals:

};

#endif // MASK_H
