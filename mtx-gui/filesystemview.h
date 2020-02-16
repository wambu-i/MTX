#ifndef FILESYSTEMVIEW_H
#define FILESYSTEMVIEW_H

#include <QFileSystemModel>
#include <QDialog>

#include <mainwindow.h>

class MainWindow;

class FileSystemView: public QFileSystemModel{
	Q_OBJECT

	public:
		// Constructor
		FileSystemView(MainWindow *parent);
		// Destructor
		~FileSystemView();

	private:
		MainWindow *parent;

		QFileSystemModel *directories;
		QFileSystemModel *files;

		void openBasePath();
};
	
#endif