#ifndef JOYPADAREA_H
#define JOYPADAREA_H

#include <QQuickPaintedItem>

class JoypadArea : public QQuickPaintedItem
{
    Q_OBJECT

public:
    explicit JoypadArea(QQuickItem * root);

    void setTouchPosition(const QPointF & point);
    QPointF getTouchPosition();

    void setRadius(qreal r);
    qreal getRadius();

protected:
    void paint(QPainter * painter) override;


signals:

};

#endif // JOYPADAREA_H
