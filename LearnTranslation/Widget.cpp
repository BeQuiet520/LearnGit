#include "Widget.h"
#include "ui_Widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setText(tr("i am a man"));
    ui->comboBox->addItem(tr("中文"));
    ui->comboBox->addItem(tr("English"));
    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Widget::ChangTrans);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::ChangTrans(int index)
{
    qDebug()<<"indeex:"<<index;
    QString path = QCoreApplication::applicationDirPath() + "translations";
    switch (index)
    {
    case 0:
    {
        translator.load(path+"/test_zh_CN.qm");
        break;
    }
    case 1:
    {
        translator.load(path+"/test_en_US.qm");
        break;
    }
    default:
        break;
    }
    qApp->installTranslator(&translator);
}
