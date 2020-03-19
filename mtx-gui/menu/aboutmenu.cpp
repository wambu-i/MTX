#include "aboutmenu.h"

AboutMenu::AboutMenu() {
    this->setTitle(tr("&About"));
    this->createActions();
    this->createAboutMenu(this);
}

AboutMenu::~AboutMenu() {
    delete aboutMTX;
}

void AboutMenu::createAboutMenu(AboutMenu *aboutOption) {
    aboutOption->addAction(aboutMTX);
}

void AboutMenu::createActions() {
    aboutMTX = new QAction(tr("&About MTX"), this);
    aboutMTX->setShortcut(tr("&Ctrl+?"));
    aboutMTX->setStatusTip(tr("&Learn More about MTX"));
    connect(aboutMTX, &QAction::triggered, this, &AboutMenu::showAbout);
}

void AboutMenu::showAbout() {
    about.setText(aboutText);
    about.exec();
}