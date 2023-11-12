#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Викликайте qInstallMessageHandler тут, а не в qMain
    qInstallMessageHandler(MainWindow::customMessageHandler);

    MainWindow w;
    w.show();
    return a.exec();
}
