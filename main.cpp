#include "mainwindow.h"
#include "firstwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    FirstWindow *sWindow = new FirstWindow();
    sWindow->show();


    return a.exec();
}
