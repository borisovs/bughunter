#include <QtDebug>
#include "startscene.h"

#include <QPainter>
#include <QGraphicsSimpleTextItem>
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
    QGraphicsSimpleTextItem *m_level = addSimpleText(tr("Level"), QFont("Arial", 24));
    m_level->setPos(sceneRect().width()/2 - QFontMetrics(QFont("Arial", 24)).width(m_level->text())/2, 0);

    ProgressBar *m_levelBar = new ProgressBar;
    m_levelBar->setPos(sceneRect().width()/2 - m_levelBar->boundingRect().width()/2, 50 );

    QGraphicsSimpleTextItem *m_easy = addSimpleText(tr("Easy"), QFont("Arial", 12));
    m_easy->setPos(m_levelBar->pos().x() - QFontMetrics(QFont("Arial", 13)).width(m_easy->text()), m_levelBar->pos().y()+m_levelBar->boundingRect().height()/2);

    addItem(m_levelBar);

    QGraphicsSimpleTextItem *m_hard = addSimpleText(tr("Hard"), QFont("Arial", 12));
    m_hard->setPos(m_levelBar->pos().x() + m_levelBar->boundingRect().width(), m_levelBar->pos().y()+m_levelBar->boundingRect().height()/2);
}

ProgressBar::ProgressBar(QGraphicsObject *parent)
    :QGraphicsObject(parent)
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
