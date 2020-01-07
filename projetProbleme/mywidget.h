#ifndef MYWIDGET_H
#define MYWIDGET_H


#include <QGraphicsView>

class MyWidget : public QGraphicsView
{
    Q_OBJECT
    public:
        MyWidget (QWidget *parent = 0);
   protected:
        void resizeEvent(QResizeEvent * event);
   private:
        QGraphicsScene * scene;
};
#endif
