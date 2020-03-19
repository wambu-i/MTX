#ifndef EDITMENU_H
#define EDITMENU_H

#include <QMenu>
#include <QAction>


class EditMenu: public QMenu {
    Q_OBJECT
    public:
        EditMenu();
        ~EditMenu();

    private:
        //EditMenu *editOption;

        QAction *cutOption;
        QAction *copyOption;
        QAction *pasteOption;

        void createMenuOption(EditMenu *);
        void createActions();

    private slots:

};
#endif