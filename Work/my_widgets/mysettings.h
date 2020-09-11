#ifndef MYSETTINGS_H
#define MYSETTINGS_H

#include <QDialog>
#include <QSplitter>
#include <QLabel>
#include <QSlider>
#include <QHBoxLayout>
#include <QPushButton>
class MySettings: public QDialog
{
    Q_OBJECT
private:
    QLabel* d_label;
    QSlider* d_slider;
    QPushButton* but_ok;
    QHBoxLayout* layout;

public:
    MySettings(QWidget* parent);
    ~MySettings();
signals:
    void signalNumber(int);
public slots:
    void slotforSignalNumber(int);
};

#endif // MYSETTINGS_H
