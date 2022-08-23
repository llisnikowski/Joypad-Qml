#include "joypad.h"
#include <QPainter>

#include <QDebug>

Joypad::Joypad()
    :area_(this), joystick_(this)
{
    setAcceptedMouseButtons(Qt::LeftButton);
    area_.setRadius(30);
    joystick_.setRadius(20);
}

void Joypad::paint(QPainter *painter)
{
    QRectF size = QRectF(0, 0, this->width(), this->height());
    painter->fillRect(size, QColor(200,200,200,50));
}

bool Joypad::event(QEvent *event)
{
    switch (event->type()) {
    case QEvent::MouseButtonPress:
    {
        beginTouch(static_cast<QMouseEvent *>(event)->localPos());
        break;
    }
    case QEvent::MouseMove:
    {
        moveTouch(static_cast<QMouseEvent *>(event)->localPos());
        break;
    }
    case QEvent::TouchBegin:
    {
        const QList<QTouchEvent::TouchPoint> touchPoints = static_cast<QTouchEvent *>(event)->touchPoints();
        if(touchPoints.count()){
            beginTouch(touchPoints.at(0).pos());
        }
        break;
    }
    case QEvent::TouchUpdate:
    {
        const QList<QTouchEvent::TouchPoint> touchPoints = static_cast<QTouchEvent *>(event)->touchPoints();
        if(touchPoints.count()){
            moveTouch(touchPoints.at(0).pos());
        }
        break;
    }
    case QEvent::MouseButtonRelease:
    case QEvent::TouchEnd:
    {
        endTouch();
        break;
    }
    default:
        return QQuickItem::event(event);
    }
    return true;
}

void Joypad::beginTouch(const QPointF & point)
{
    area_.setTouchPosition(point);
    area_.setVisible(true);
    joystick_.setTouchPosition(point);
    joystick_.setVisible(true);
    update();
}

void Joypad::moveTouch(const QPointF &point)
{
    QPointF beginPoint = area_.getTouchPosition();
    QLineF difVector = QLineF(beginPoint, point);
    if(difVector.length() > area_.getRadius()){
        difVector.setLength(area_.getRadius());
    }
    joystick_.setTouchPosition(difVector.p2());
}

void Joypad::endTouch()
{
    area_.setVisible(false);
    joystick_.setVisible(false);
    update();
}
