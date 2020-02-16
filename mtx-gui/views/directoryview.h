#ifndef DIRECTORYVIEW_H
#define DIRECTORYVIEW_H

#include <QFileSystemModel>
#include <QTreeView>
#include "../mainwindow.h"

class MainWindow;

class DirectoryView: public QFileSystemModel {
    Q_OBJECT

    public:
        explicit DirectoryView();
        ~DirectoryView();

    private:
        QFileSystemModel *test;
        QTreeView *tree;
       /*  void createDirectoryView(MainWindow *); */

};
#endif