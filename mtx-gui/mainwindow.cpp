#include <stdlib.h>
#include <QtWidgets>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>
#include <QRect>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setUp();
    filemenu = new FileMenu;
    editmenu = new EditMenu;
    aboutmenu = new AboutMenu;

    directories = new DirectoryView;

    this->menuBar()->addMenu(filemenu);
    this->menuBar()->addMenu(editmenu);
    this->menuBar()->addMenu(aboutmenu);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::resizeMainWindow() {
    QRect main_screen = QDesktopWidget().availableGeometry(QDesktopWidget().primaryScreen());
    MainWindow::height = main_screen.height();
    MainWindow::width = main_screen.width();
    this->resize(MainWindow::width, MainWindow::height);
}

void MainWindow::setUp() {
    this->setName();
    this->resizeMainWindow();
}

/* void MainWindow::openNewWindow() {
    duplicate = new MainWindow;
    duplicate.show();
} */
