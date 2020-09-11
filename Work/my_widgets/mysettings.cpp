#include "mysettings.h"

MySettings::MySettings(QWidget* parent):QDialog(parent)
{
    d_label=new QLabel("0",this);
    d_slider=new QSlider(Qt::Horizontal,this);
    d_slider->setRange(0,10);
    d_slider->setPageStep(1);
    d_slider->setValue(0);
    layout=new QHBoxLayout(this);
    layout->addWidget(d_slider);
    layout->addWidget(d_label);
    but_ok=new QPushButton("Ok",this);
    layout->addWidget(but_ok);

    connect(d_slider,SIGNAL(valueChanged(int)),
            d_label,SLOT(setNum(int)));

    connect(d_slider,SIGNAL(valueChanged(int)),
            this,SLOT(slotforSignalNumber(int)));

    connect(but_ok,SIGNAL(clicked()),this,SLOT(close()));
}

MySettings::~MySettings()
{

}

void MySettings::slotforSignalNumber(int _number)
{
    emit signalNumber(_number);
}
