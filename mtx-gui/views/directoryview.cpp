#include "directoryview.h"

DirectoryView::DirectoryView() {
/*     this->createDirectoryView(); */
    QString s = "/home/wambui/";
    test = new FileSystemModel
    test->setRootPath(s);
    tree = new QTreeView;
    tree->setModel(this);


}
/*
void DirectoryView::createDirectoryView(MainWindow *directories) {
    QString s = "/home/wambui/";
    directories->setRootPath(s);

    tree = new QTreeView;
    tree->setModel(directories);

} */

DirectoryView::~DirectoryView() {
    delete tree;
}