#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //connect(ui->pushButton_3, &QPushButton::clicked, this, &QDialog::reject);
    //connect fonksiyonu void Dialog::on_pushButton_3_clicked fonksiyonu ile aynı görevi yapar yani çıkış işlemini
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_buton_cikis_clicked()
{
    QDialog::reject();
}

void Dialog::on_buton_hesapla_clicked()
{
    QString ad, dersad, vize_not, final_not;
    ad=ui->lnedit_ad->text();
    dersad=ui->lnedit_dersad->text();
    vize_not=ui->lnedit_vizenot->text();
    final_not=ui->lnedit_finalnot->text();

    if(ad=="" || dersad=="" || vize_not=="" || final_not=="")
    {
        ui->text_sonuc->setText("Eksik bilgi girdiniz, lütfen kontrol edip tekrar giriniz!");
    }
    else
    {
        int vn, fn, gecme_notu;
        vn=vize_not.toInt();
        fn=final_not.toInt();
        gecme_notu=(vn*0.4)+(fn*0.6);

        if(gecme_notu>=60)
        {
            ui->text_sonuc->setText(ad+" isimli öğrenci "+dersad+" isimli dersten geçmiştir.");
        }
        else
        {
            ui->text_sonuc->setText(ad+" isimli öğrenci "+dersad+" isimli dersten kalmıştır.");
        }
    }


}


