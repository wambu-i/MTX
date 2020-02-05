#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "filesystem.h"

#include "./menu/filemenu.h"
#include "./menu/editmenu.h"
#include "./menu/aboutmenu.h"
#include "./views/directoryview.h"

class QString;

class FileMenu;
class EditMenu;
class AboutMenu;
class DirectoryView;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString main_title = "MTX";

    int width;
    int height;

    FileMenu *filemenu;
    EditMenu *editmenu;
    AboutMenu *aboutmenu;
    MainWindow *duplicate;

    DirectoryView *directories;

    void setName() {
        this->setWindowTitle(MainWindow::main_title);
    };

    void resizeMainWindow();
    void setUp();

private slots:
    //void openNewWindow();

};

#endif
