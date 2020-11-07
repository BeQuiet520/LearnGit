#include "Widget.h"
#include <QApplication>
#include <QTranslator>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString path = QApplication::applicationDirPath() + "/translations";
    QTranslator translator;
    QString filePath = path+"/test_zh_CN.qm";
    bool ret = translator.load(filePath);
    qDebug()<<"path:"<<filePath<<" ret:"<<ret;
    qApp->installTranslator(&translator);
    Widget w;
    w.show();

    return a.exec();
}
