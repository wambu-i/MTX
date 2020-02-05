#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication mtx(argc, argv);
    MainWindow window;
    window.show();

    return mtx.exec();
}
