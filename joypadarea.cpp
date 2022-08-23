#include "joypadarea.h"

#include <QPen>
#include <QPainter>
#include <QDebug>

JoypadArea::JoypadArea(QQuickItem * root)
    :QQuickPaintedItem(root)
{
    setVisible(false);
}

void JoypadArea::setTouchPosition(const QPointF & point)
{
    setX(point.x() - size().width()/2);
    setY(point.y() - size().height()/2);

    update();
}

QPointF JoypadArea::getTouchPosition()
{
    return QPointF(x() + size().width()/2, y() + size().height()/2);
}


void JoypadArea::paint(QPainter *painter)
{
    painter->setPen(QPen(Qt::gray, 5));
    qreal penWidth = painter->pen().widthF();
    QRectF sizeMargin = QRectF(penWidth/2, penWidth/2, this->width() - penWidth, this->height() - penWidth);

    painter->drawEllipse(sizeMargin);
}


void JoypadArea::setRadius(qreal r)
{
    setWidth(r*2);
    setHeight(r*2);
}

qreal JoypadArea::getRadius()
{
    return width()/2;
}
