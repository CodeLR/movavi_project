#ifndef FRAME_H
#define FRAME_H

#include <QFrame>
#include <QGridLayout>
#include <QComboBox>
#include <QLabel>
#include <QScrollBar>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QPointer>
#include <QPixmap>
class Frame:public QFrame
{
    Q_OBJECT
private:

    QLabel* file;
    QLabel* layer;



    QLabel* sizeInscription;
    QString stringInscription;

    QComboBox* boxImage;
    QComboBox* boxLayer;
    QLabel* mainLabelImage;
    QGridLayout* gridLayout;
    QStringList list;
    QVBoxLayout* vboxLayout;


    QPointer<QScrollArea> scrollArea;
    QVector<QString> vecStr;
    QVector<QVector<QPixmap*>> pix;
    QVector<QVector<int>> numberSizeImages;

    int P=0; // шаг перехода по комбобоксу
    int sizeVec=0; // размер пака картинок
    int WIDTH = 380; // размер лайбла
    int HEIGHT = 400;
    int dynamicSizeImage=2; // по умолчанию идет 2 но можно в
    //меню менять размер формата картинки



    bool switchTraffic=false;//логический переход
     // название  массив картинок
public:
    Frame(QWidget* parent);
    ~Frame();
    QString ParsingStr(QString&);// парсинг названия файла
    void CreateSizeImage(QVector<QPixmap*>&); // получение картики
    void setSizeQLabel(int,int); // метод в котором идет конструкция картинок
public slots:
    void imgFromLabel(QString&);
    void show_on_screenInsidePack(int);
    void show_on_screenPacks(int);
    void setSizeVariable(int);

};

#endif // FRAME_H
