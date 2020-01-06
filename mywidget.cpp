#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent) : QGraphicsView(parent)
{
    scene = new QGraphicsScene(this);
    setScene(scene);
    scene->addText("test");
}
void MyWidget::resizeEvent(QResizeEvent * event)
{
    scene->setSceneRect( QRect(QPoint(0, 0), size()) );
    fitInView(sceneRect());
}
