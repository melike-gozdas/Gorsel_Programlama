#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include <time.h>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

int sayi;
QString birinci_aralik, ikinci_aralik;
int b_aralik, i_aralik;

void Dialog::on_buton_Uret_clicked()
{
    srand(time(0));
    birinci_aralik=ui->lnedit_birinciAralik->text();
    ikinci_aralik=ui->lnedit_ikinciAralik->text();
    b_aralik=birinci_aralik.toInt();
    i_aralik=ikinci_aralik.toInt();
    sayi=rand()%(i_aralik-b_aralik)+b_aralik;
    qDebug()<<sayi;
}


int ds=0;
void Dialog::on_buton_TahminEt_clicked()
{
    srand(time(0));
    ui->buton_TahminEt->setAutoRepeat(true);  //bu komut ile tahmin et butonuna basılı tutulduğu sürece tahmin et sürekli tıklanır.
    int tahmin=rand()%(i_aralik-b_aralik)+b_aralik;
    ds++;
    QString string=QString::number(ds); //ds yi int ifadeyi QString ifadeye çevirme
    if(sayi!=tahmin)
    {
        ui->text_sonuc->setText("Doğru tahmin edilemedi. Deneme sayısı: "+string);
    }
    else
    {
        ui->text_sonuc->setText("Tebrikler. Doğru tahmin edildi. Deneme sayısı: "+string);
        ui->buton_TahminEt->setVisible(false);  //bu işlem tahmin doğru ise tahmin et butonunu kapatır.
    }
}
