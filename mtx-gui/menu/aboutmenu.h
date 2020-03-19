#ifndef ABOUTMENU_H
#define ABOUTMENU_H

#include <QMessageBox>
#include <QMenu>
#include <QAction>
#include <QString>

class AboutMenu: public QMenu {
    Q_OBJECT

    public:
        AboutMenu();
        ~AboutMenu();

    private:
        QAction *aboutMTX;
        QMessageBox about;

        QString aboutText = "Version 0.0.1";

        void createAboutMenu(AboutMenu *);
        void createActions();

    private slots:
        void showAbout();

};
#endif