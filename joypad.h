#ifndef JOYPAD_H
#define JOYPAD_H

#include <QQuickPaintedItem>
#include <QPointF>

#include "joypadarea.h"
#include "joystick.h"

class Joypad : public QQuickPaintedItem
{
    Q_OBJECT
public:
    Joypad();

    void paint(QPainter * painter) override;

protected:
    bool event(QEvent *event) override;

private:
    void beginTouch(const QPointF & point);
    void moveTouch(const QPointF & point);
    void endTouch();

signals:

private:
    JoypadArea area_;
    Joystick joystick_;

};

#endif // JOYPAD_H
