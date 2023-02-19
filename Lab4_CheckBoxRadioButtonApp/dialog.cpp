#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>

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


void Dialog::on_rd_lisans_clicked()
{
     ui->grp_sinif->setEnabled(true);
     ui->grp_zorunluderslerlisans->setEnabled(true);
     ui->grp_durum->setEnabled(false);
     ui->grp_zorunluderslerlisansustu->setEnabled(false);
}

void Dialog::on_rd_lisansustu_clicked()
{
    ui->grp_sinif->setEnabled(false);
    ui->grp_zorunluderslerlisans->setEnabled(false);
    ui->grp_durum->setEnabled(true);
    ui->grp_zorunluderslerlisansustu->setEnabled(true);
}

void Dialog::on_btn_bilgileriYazdir_clicked()
{
    QString ad, soyad, bolum, seviye;
    ad=ui->ln_ad->text();
    soyad=ui->ln_soyad->text();
    bolum=ui->ln_bolum->text();
    /*
    //1.Yöntem
    QObjectList objler=this->children();
    foreach(QObject* obj, objler)
    {
        if(obj->inherits("QRadioButton"))
        {
            QRadioButton* rd=qobject_cast<QRadioButton*>(obj);
            if(rd->isChecked())
            {
                seviye=rd->text();
            }
        }
    }
    QMessageBox::information(this, "Öğrenci Bilgileri", "Ad: "+ad+"\n"+"Soyad: "+soyad+"\n"+"Bölüm: "+bolum+"\n"+"Seviye: "+seviye, "Tamam");
    //seviyeyi bu yöntemle yazdıramadım çünkü dialog içinde radiobutton varmı kontrol edip var mı diye baktım ama radio button groupbox içinde olduğu için erişemedik .
    //önce groupbox a sonra radiobutton a erişirsek seviye bilgisine ulaşabiliriz.
    */

    /*
    //2.Yöntem
    QObject* obj=ui->grp_egitim;
    QList<QRadioButton*> liste=obj->findChildren<QRadioButton*>(QString(),Qt::FindDirectChildrenOnly);
    foreach(QRadioButton* rd, liste)
    {
        if(rd->isChecked())
        {
            seviye=rd->text();
        }
    }
    QMessageBox::information(this, "Öğrenci Bilgileri", "Ad: "+ad+"\n"+"Soyad: "+soyad+"\n"+"Bölüm: "+bolum+"\n"+"Seviye: "+seviye, "Tamam");
    //Seviyeyi yazdırırken bir sorun yaşamadık çünkü direk eğitim groupbox ı için bir pointer kullandığımız için.
    */

    //3.Yöntem
    if(ui->rd_lisans->isChecked())
    {
        seviye=ui->rd_lisans->text();
    }
    if(ui->rd_lisansustu->isChecked())
    {
        seviye=ui->rd_lisansustu->text();
    }
    QMessageBox::information(this, "Öğrenci Bilgileri", "Ad: "+ad+"\n"+"Soyad: "+soyad+"\n"+"Bölüm: "+bolum+"\n"+"Seviye: "+seviye,"Tamam");
    //bu yöntem çok fazla radiobutton bulunan bir projede zor olabilir diğer yöntemleri de bil.
}

void Dialog::on_btn_mezuniyetSorgula_clicked()
{
    QString ad, soyad, bolum, seviye;
    ad=ui->ln_ad->text();
    soyad=ui->ln_soyad->text();
    bolum=ui->ln_bolum->text();
    if(ui->rd_lisans->isChecked())
    {
        seviye=ui->rd_lisans->text();
    }
    if(ui->rd_lisansustu->isChecked())
    {
        seviye=ui->rd_lisansustu->text();
    }

    if(ui->rd_lisans->isChecked())
    {
        if(ui->rd_sinif4->isChecked() && ui->ch_Aiit->isChecked() && ui->ch_Turkdili->isChecked() && ui->ch_isg->isChecked())
        {
            QMessageBox::information(this, "Mezuniyet Bilgileri", "Öğrenci Lisanstan Mezun olabilir!", "Tamam");
        }
        else
        {
            QMessageBox::information(this, "Mezuniyet Bilgileri", "Öğrenci Lisanstan Mezun olamaz!", "Tamam");
        }
    }
    if(ui->rd_lisansustu->isChecked())
    {
        if(ui->rd_tez->isChecked() && ui->ch_secmeli->isChecked() && ui->ch_seminer->isChecked() && ui->ch_tez->isChecked())
        {
            QMessageBox::information(this, "Mezuniyet Bilgileri", "Öğrenci Lisansüstünden Mezun olabilir!", "Tamam");
        }
        else
        {
            QMessageBox::information(this, "Mezuniyet Bilgileri", "Öğrenci Lisansüstünden Mezun olamaz!", "Tamam");
        }
    }
}

void Dialog::on_btn_ogrDurumYazdir_clicked()
{
    QString ad, soyad, bolum, seviye;
    ad=ui->ln_ad->text();
    soyad=ui->ln_soyad->text();
    bolum=ui->ln_bolum->text();
    if(ui->rd_lisans->isChecked())
    {
        seviye=ui->rd_lisans->text();
    }
    if(ui->rd_lisansustu->isChecked())
    {
        seviye=ui->rd_lisansustu->text();
    }
    bool durum=MezuniyetSorgula();
    if(seviye=="Lisans")
    {
        if(durum)
        {
            QMessageBox::information(this, "Öğrenci Bilgileri", "Öğrenci Lisans seviyesinde Mezun durumundaki bir öğrencidir!", "Tamam");

        }
        else
        {
            QMessageBox::information(this, "Öğrenci Bilgileri", "Öğrenci Lisans seviyesinde bir öğrencidir!", "Tamam");
        }
    }
    if(seviye=="Lisansüstü")
    {
        if(durum)
        {
            QMessageBox::information(this, "Öğrenci Bilgileri", "Öğrenci Lisansüstü seviyesinde Mezun durumundaki bir öğrencidir!", "Tamam");

        }
        else
        {
            QMessageBox::information(this, "Öğrenci Bilgileri", "Öğrenci Lisansüstü seviyesinde bir öğrencidir!", "Tamam");
        }
    }
}

bool Dialog::MezuniyetSorgula()
{
    QString ad, soyad, bolum, seviye;
    ad=ui->ln_ad->text();
    soyad=ui->ln_soyad->text();
    bolum=ui->ln_bolum->text();
    if(ui->rd_lisans->isChecked())
    {
        seviye=ui->rd_lisans->text();
    }
    if(ui->rd_lisansustu->isChecked())
    {
        seviye=ui->rd_lisansustu->text();
    }

    if(ui->rd_lisans->isChecked())
    {
        if(ui->rd_sinif4->isChecked() && ui->ch_Aiit->isChecked() && ui->ch_Turkdili->isChecked() && ui->ch_isg->isChecked())
        {
            //QMessageBox::information(this, "Mezuniyet Bilgileri", "Öğrenci Lisanstan Mezun olabilir!", "Tamam");
            return true;
        }
        else
        {
            //QMessageBox::information(this, "Mezuniyet Bilgileri", "Öğrenci Lisanstan Mezun olamaz!", "Tamam");
            return false;
        }
    }
    if(ui->rd_lisansustu->isChecked())
    {
        if(ui->rd_tez->isChecked() && ui->ch_secmeli->isChecked() && ui->ch_seminer->isChecked() && ui->ch_tez->isChecked())
        {
            //QMessageBox::information(this, "Mezuniyet Bilgileri", "Öğrenci Lisansüstünden Mezun olabilir!", "Tamam");
            return true;
        }
        else
        {
            //QMessageBox::information(this, "Mezuniyet Bilgileri", "Öğrenci Lisansüstünden Mezun olamaz!", "Tamam");
            return false;
        }
    }
}
