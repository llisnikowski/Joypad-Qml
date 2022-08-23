#include "joystick.h"

#include <QPainter>

Joystick::Joystick(QQuickItem * root)
    :QQuickPaintedItem(root)
{
    setVisible(false);
}

void Joystick::paint(QPainter *painter)
{
    painter->setPen(QPen(Qt::black, 10));
    qreal penWidth = painter->pen().widthF();
    QRectF sizeMargin = QRectF(penWidth/2, penWidth/2, this->width() - penWidth, this->height() - penWidth);

    painter->drawEllipse(sizeMargin);
}


void Joystick::setTouchPosition(const QPointF & point)
{
    setX(point.x() - size().width()/2);
    setY(point.y() - size().height()/2);

    update();
}

QPointF Joystick::getTouchPosition()
{
    return QPointF(x() + size().width()/2, y() + size().height()/2);
}

void Joystick::setRadius(qreal r)
{
    setWidth(r*2);
    setHeight(r*2);
}
