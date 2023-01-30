#include <QApplication>

#include "mainwindow.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Monitoring Aviation");
    w.show();

    return a.exec();
}
