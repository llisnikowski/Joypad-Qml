#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <QQuickPaintedItem>

class Joystick : public QQuickPaintedItem
{
    Q_OBJECT
public:
    explicit Joystick(QQuickItem * root);

    void setTouchPosition(const QPointF & point);
    QPointF getTouchPosition();

    void setRadius(qreal r);

protected:
    void paint(QPainter * painter) override;


signals:

};

#endif // JOYSTICK_H
