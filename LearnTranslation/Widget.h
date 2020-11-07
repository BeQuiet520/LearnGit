#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTranslator>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void ChangTrans(int index);
private:
    Ui::Widget *ui;
    QTranslator translator;
};

#endif // WIDGET_H
