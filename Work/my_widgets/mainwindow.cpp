#include "mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_frame=new Frame(this);
    menu_File=new QAction(this);
    settings=new QAction(this);
    settings->setText("Settings");
    menu_File->setText("Open");
    settings->setMenuRole(QAction::NoRole);
    menu_File->setMenuRole(QAction::NoRole);
    menu_File->setShortcut(QKeySequence (Qt::ALT + Qt::Key_O));
    settings->setShortcut(QKeySequence(Qt::ALT + Qt::Key_S));

    m_menu=new QMenu("File");
    m_menu->addAction(menu_File);
    m_menu->addAction(settings);
    m_menu->addSeparator();
    menuBar()->addMenu(m_menu);
    setCentralWidget(m_frame);
    setFixedSize(400,450);
    mySettings=new MySettings(this);
    mySettings->setModal(false);

    // Открытие картики
    connect(menu_File,SIGNAL(triggered()),this,SLOT(OpenFile()));
    // Открытие параметров для изм. рамера картинки
    connect(settings,SIGNAL(triggered()),this,SLOT(SettingsSlot()));
    // Передача строки где лежит файл (картинка)
    connect(this,SIGNAL(fileSignal(QString&)),
            m_frame,SLOT(imgFromLabel(QString&)));

    // передача цифры для size
    connect(mySettings,SIGNAL(signalNumber(int)),
            m_frame,SLOT(setSizeVariable(int)));

}

MainWindow::~MainWindow()
{
    delete mySettings;
    delete m_frame;

    delete m_menu;
    delete  menu_File;
    delete settings;
    delete dialog;
}

void MainWindow::OpenFile()
{
    dialog=new QFileDialog(this);
    QString fileName = QFileDialog::getOpenFileName(0, "Open File", "", "*.png *.jpg");
    if (fileName != "") {
            QFile file(fileName);
            if (!file.open(QIODevice::ReadOnly)) {
                QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
                return;
            }
            emit fileSignal(fileName);
    }
}

void MainWindow::SettingsSlot()
{
    mySettings->exec();
}

