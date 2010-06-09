#include <QtDebug>
#include "startscene.h"

#include <QPainter>
#include <QGraphicsSimpleTextItem>
#include "gamescene.h"

StartScene::StartScene(QObject *parent)
    :QGraphicsScene(parent)
{
    QLinearGradient grad(QPointF(400, 0), QPointF(400, 480));
    grad.setColorAt(0, QColor(100, 100, 100));
    grad.setColorAt(1, QColor(150, 150, 150));

    setBackgroundBrush(grad);

    loadData();
}

QRectF StartScene::sceneRect() const
{
    return QRectF(0, 0, 800, 480);

}

void StartScene::loadData()
{
    int m_pos = sceneRect().height()/3;

    ProgressBar *m_levelBar = new ProgressBar(0, "Level");
    m_pos = m_pos - m_levelBar->boundingRect().height() * 2 ;
    m_levelBar->setPos(sceneRect().width()/2 - m_levelBar->boundingRect().width()/2, m_pos);


    QGraphicsSimpleTextItem *m_easy = addSimpleText(tr("Easy"), QFont("Arial", 12));
    m_easy->setPos(m_levelBar->pos().x() - QFontMetrics(QFont("Arial", 13)).width(m_easy->text()), m_levelBar->pos().y()+m_levelBar->boundingRect().height()/2);

    addItem(m_levelBar);

    QGraphicsSimpleTextItem *m_hard = addSimpleText(tr("Hard"), QFont("Arial", 12));
    m_hard->setPos(m_levelBar->pos().x() + m_levelBar->boundingRect().width(), m_levelBar->pos().y()+m_levelBar->boundingRect().height()/2);

    ProgressBar *m_musicBar = new ProgressBar(0, "Music");
    m_pos = m_pos + m_musicBar->boundingRect().height() * 2 ;
    m_musicBar->setPos(sceneRect().width()/2 - m_levelBar->boundingRect().width()/2, m_pos );

    QGraphicsSimpleTextItem *m_low = addSimpleText(tr("Low"), QFont("Arial", 12));
    m_low->setPos(m_musicBar->pos().x() - QFontMetrics(QFont("Arial", 13)).width(m_low->text()), m_musicBar->pos().y()+m_musicBar->boundingRect().height()/2);


    QGraphicsSimpleTextItem *m_high = addSimpleText(tr("High"), QFont("Arial", 12));
    m_high->setPos(m_musicBar->pos().x() + m_musicBar->boundingRect().width(), m_musicBar->pos().y()+m_musicBar->boundingRect().height()/2);

    addItem(m_musicBar);

    Button *start = new Button;
    m_pos = m_pos + start->boundingRect().height() * 2 ;
    start->setPos(sceneRect().width()/2 - start->boundingRect().width()/2, m_pos );

    addItem(start);
    connect(start, SIGNAL(clicked()), this, SIGNAL(game()));
}

//void StartScene::startGame()
//{
//    GameScene *game = new GameScene;
//
//}

ProgressBar::ProgressBar(QGraphicsObject *parent, QString str)
    :QGraphicsObject(parent), m_cap(str)
{

}

QRectF ProgressBar::boundingRect() const
{
    return QRectF(0, 0, 300, 50) ;
}

void ProgressBar::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();
    //draw  button
    QLinearGradient grad(QPointF(boundingRect().center().x(), 0), QPointF(boundingRect().center().x(), boundingRect().bottom()));
    grad.setColorAt(0, QColor(100, 100, 100));
    grad.setColorAt(1, QColor(50, 50, 50));

    painter->setPen(Qt::gray);
    painter->setBrush(grad);
    painter->drawRoundRect(boundingRect(), 5, 15);

    //draw value

    QLinearGradient valGrad(QPointF(boundingRect().center().x(), 0), QPointF(boundingRect().center().x(), boundingRect().bottom()));
    valGrad.setColorAt(0, Qt::yellow);
    valGrad.setColorAt(1, Qt::darkYellow);
    painter->setBrush(valGrad);
    painter->drawRoundRect(QRect(boundingRect().topLeft().toPoint(), loadData() ), 5, 15);

    painter->setFont(QFont("Arial", 24));
    painter->setPen(Qt::darkGray);
    painter->drawText(boundingRect(), Qt::AlignCenter , m_cap);

    painter->restore();
}

void  ProgressBar::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
   if (event->pos().x() <= boundingRect().bottomRight().x() && event->pos().y() <= boundingRect().bottomRight().y()){
       QPointF m_point= event->pos();
       setData(m_point.toPoint());
   }

}


void ProgressBar::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}


void ProgressBar::setData(QPoint data)
{
    if (data.y() < boundingRect().height())
        data.setY(boundingRect().height());

    m_pos = data;
    update();
}

QPoint ProgressBar::loadData()
{
    return m_pos;
}


Button::Button(QGraphicsObject *parent, bool pressed)
    :QGraphicsObject(parent), isPressed(pressed)
{

}

QRectF Button::boundingRect() const
{
    return QRectF(0, 0, 300, 50) ;
}

void Button::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();

    QLinearGradient grad(QPointF(boundingRect().center().x(), 0), QPointF(boundingRect().center().x(), boundingRect().bottom()));

    if (!isPressed) {
        grad.setColorAt(0, QColor(100, 100, 100));
        grad.setColorAt(1, QColor(50, 50, 50));
    } else {
        grad.setColorAt(0, Qt::yellow);
        grad.setColorAt(1, Qt::darkYellow);

}
    painter->setPen(Qt::gray);
    painter->setBrush(grad);
    painter->drawRoundRect(boundingRect(), 5, 15);

    painter->setFont(QFont("Arial", 24));
    painter->setPen(Qt::darkGray);
    painter->drawText(boundingRect(), Qt::AlignCenter ,tr("Start"));

    painter->restore();
}



void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    isPressed = true;
    update();
}

void Button::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    isPressed = false;
    update();
    emit clicked();
}
