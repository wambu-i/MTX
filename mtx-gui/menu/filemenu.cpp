#include "filemenu.h"

FileMenu::FileMenu(){
    this->setTitle(tr("&File Menu"));
    this->createFileActions();
    this->createMenuBar(this);

}

void FileMenu::createMenuBar(FileMenu *fileOption) {
    fileOption->addAction(newWindow);
    fileOption->addAction(newFolder);
    fileOption->addAction(newFile);
    fileOption->addAction(exitWindow);
}


void FileMenu::createFileActions() {
    newFolder = new QAction(tr("&New Folder"), this);
    newFolder->setShortcut(tr("Ctrl+Shift+N"));
    newFolder->setStatusTip(tr("Create a new folder"));
    /* connect(newFolder, &QAction::triggered, this, &FileMenu::openNewFolder);
 */
    newWindow = new QAction(tr("&New Window"), this);
    newWindow->setShortcut(tr("Ctrl+N"));
    newWindow->setStatusTip("Open a new MTX window");
    //connect(newWindow,&QAction::triggered, this, &FileMenu::openNewWindow);

    newFile = new QAction(tr("&New File"), this);
    newFile->setShortcut(tr("Shift+N"));
    newFile->setStatusTip("Create a new file");
    /* connect(newFile, &QAction::triggered, this, &FileMenu::openNewFile); */

    exitWindow = new QAction(tr("&Exit"), this);
    exitWindow->setShortcut(tr("Shift+C"));
    exitWindow->setStatusTip("Exit MTX");
    connect(exitWindow, &QAction::triggered, this, &FileMenu::exitMTX);
}


void FileMenu::exitMTX() {
    exit(EXIT_SUCCESS);
}

FileMenu::~FileMenu() {
    delete newFolder;
    delete newFile;
    delete newWindow;
    delete exitWindow;
}

