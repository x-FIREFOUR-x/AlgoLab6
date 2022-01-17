//#include "windows/mainwindow.h"
#include "windows/windowsworker.h"

#include <QApplication>
#include <ctime>

int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);
    WindowsWorker::open_MainWindow();
    return a.exec();
}
