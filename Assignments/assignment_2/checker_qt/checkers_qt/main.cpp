#include "mainwindow.h"

#include <QApplication>
#include <ui_mainwindow.h>
#include <QEvent>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.layout();
    w.show();
    w.centralWidget()->style();
    return a.exec();
}
