#include "frame.h"
#include <QDebug>
#include <iostream>
#include <QAbstractScrollArea>


Frame::Frame(QWidget* parent):QFrame(parent)
{
    gridLayout=new QGridLayout(this);

    file=new QLabel("File:",this);
    layer=new QLabel("Layer:",this);
    sizeInscription=new QLabel("Size: ",this);
    boxImage=new QComboBox(this);
    boxImage->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    boxLayer=new QComboBox(this);
    mainLabelImage=new QLabel(this);
    mainLabelImage->setBackgroundRole(QPalette::Base);
    mainLabelImage->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    mainLabelImage->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    gridLayout->addWidget(file,0,0);
    gridLayout->addWidget(boxImage,0,1);
    gridLayout->addWidget(layer,0,2);
    gridLayout->addWidget(boxLayer,0,3);
    gridLayout->addWidget(sizeInscription,0,4);

    vboxLayout=new QVBoxLayout(this);
    vboxLayout->addWidget(mainLabelImage);
    gridLayout->addLayout(vboxLayout,1,1,4,4,Qt::AlignCenter);


    // Изменение в комбобокаса паков

    connect(boxImage,SIGNAL(currentIndexChanged(int)),this,SLOT(show_on_screenPacks(int)));
}

Frame::~Frame()
{

}

QString Frame::ParsingStr(QString &str) // Отрезаем название с доступа к файлу
{
    QString stringNamFile;
    for(int i=str.size();i>0;--i){
        if(str[i]!='/'){
            stringNamFile+=str[i];
        }
        else if(str[i]=='/')
            break;
    }
    QString pars_string;
    for(int x=0;x<=stringNamFile.size();++x){
        pars_string+=stringNamFile[stringNamFile.size()-x];
    }
    return pars_string;
}

void Frame::setSizeVariable(int number)
{
    dynamicSizeImage=number;
    //Изменение размера по диалогу
}

void Frame::CreateSizeImage(QVector<QPixmap*>&_vec) // изменяем и записываем размеры в вектор
{
    int sizeCount=2;
    int i=0;
    while(true){
        //qDebug()<<_vec[i]->width()<<" "<<_vec[i]->height();
        QSize size(_vec[i]->width()/dynamicSizeImage,_vec[i]->height()/dynamicSizeImage);
        size=size/dynamicSizeImage;
        if(size.width()<250 && size.height()<300)
        {
            break;
        }else{
            _vec.push_back(new QPixmap(_vec[i]->scaled(size,Qt::KeepAspectRatio)));
            numberSizeImages[sizeVec].push_back(sizeCount);
            boxLayer->addItem(QString::number(numberSizeImages[sizeVec][i]));
            sizeCount+=2;
            ++i;
        }
    }

}



void Frame::setSizeQLabel(int w, int h) // установка в лейбл слов с высотой и шириной
{
    stringInscription.clear();
    sizeInscription->clear();
    stringInscription = QString::number(w) + "x" + QString::number(h);
    sizeInscription->setText("Size: " + stringInscription);
}

void Frame::imgFromLabel(QString& str) //Первый вход изображения после открытия
{
    boxLayer->clear();
    vecStr.push_back(ParsingStr(str));
    QVector<QPixmap*> pixVec;
    QVector<int> tempNumberSize;

    pixVec.append(new QPixmap(str));
    pix.push_back(pixVec);
    mainLabelImage->setPixmap(*pixVec[0]);

    tempNumberSize.push_back(0);
    numberSizeImages.push_back(tempNumberSize);// входим с нуля
    CreateSizeImage(pix[sizeVec]);

    // Изменение комбобокса в нутри пака
    boxImage->addItem(vecStr[sizeVec]);
    boxImage->setCurrentText(ParsingStr(str));
    sizeVec++;
    connect(boxLayer,SIGNAL(currentIndexChanged(int)),this,SLOT(show_on_screenInsidePack(int)));
}

void Frame::show_on_screenInsidePack(int index) //Контрол за картинками
{

    //Цикл
    scrollArea=new QScrollArea(this);
    scrollArea->setWidget(mainLabelImage);
    gridLayout->addWidget(scrollArea,1,0,4,5,Qt::AlignCenter);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    bool SCROLLTRUE=false;

    for(int k = 0 ; k < pix[P].size() ; ++k){ // k номер картинки в паке
        if( index == k  ){

            if( pix[P][k]->width() > WIDTH && pix[P][k]->height() > HEIGHT ){
                mainLabelImage->setPixmap( *pix[P][k] );
                if(SCROLLTRUE){
                    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
                    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
                }
                //scrollArea->setWidgetResizable(true);

                mainLabelImage->setFixedSize(pix[P][k]->width(),pix[P][k]->height());
                setSizeQLabel(pix[P][k]->width(),pix[P][k]->height());

                break;
            }
            else{

                mainLabelImage->setPixmap( *pix[P][k] );
                mainLabelImage->setFixedSize(380,400);
                scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
                scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
                scrollArea->verticalScrollBar()->setEnabled(false);
                scrollArea->horizontalScrollBar()->setEnabled(false);
                setSizeQLabel(pix[P][k]->width(),pix[P][k]->height());
                SCROLLTRUE=true;
                break;
            }
        }
    }
}

void Frame::show_on_screenPacks(int index)
{
    switchTraffic=true;
    // слот в котором будет меняться картинка по первому комбобоксу
    scrollArea=new QScrollArea(this);
    scrollArea->setWidget(mainLabelImage);
    gridLayout->addWidget(scrollArea,1,0,4,5,Qt::AlignCenter);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    bool SCROLLTRUE=false;
    boxLayer->clear();
    for(int i=0;i<numberSizeImages[index].size();++i){
        boxLayer->addItem(QString::number(numberSizeImages[index][i]));
    }
    for (P = 0 ; P < pix.size() ; ++P ){ // i номер пака
        if( index == P  ){
            if( pix[P][0]->width() > WIDTH){
                mainLabelImage->setPixmap( *pix[P][0] );
                if(SCROLLTRUE){
                    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
                    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
                }
                scrollArea->setWidgetResizable(true);
                mainLabelImage->setFixedSize(pix[P][0]->width(),pix[P][0]->height());
                setSizeQLabel(pix[P][0]->width(),pix[P][0]->height());
                break;
            }
            else{
                mainLabelImage->setPixmap( *pix[P][0] );
                mainLabelImage->setFixedSize(380,400);
                scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
                scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
                scrollArea->verticalScrollBar()->setEnabled(false);
                scrollArea->horizontalScrollBar()->setEnabled(false);
                setSizeQLabel(pix[P][0]->width(),pix[P][0]->height());
                SCROLLTRUE=true;
                break;
            }
        }
    }
}
