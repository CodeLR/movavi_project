#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMessageBox>
#include <QMenu>
#include <QMenuBar>
#include <QFileDialog>
#include "frame.h"
#include "mysettings.h"



class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Frame * m_frame;
    QMenu* m_menu;
    QAction* menu_File;
    QAction* settings;
    QFileDialog* dialog;
    MySettings* mySettings;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void OpenFile();
    void SettingsSlot();
signals:
    void fileSignal(QString&);
};
#endif // MAINWINDOW_H
