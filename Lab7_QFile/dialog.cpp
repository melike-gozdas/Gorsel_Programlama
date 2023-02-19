#include "dialog.h"
#include "ui_dialog.h"
#include "Ogrenci.cpp"


QList<Ogrenci*> ogrler;
//global tanımlamam gerektiği için burada tanımladım.
//Ogrenci* yapmamın nedeni pointer olarak tutması için
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);




    //ogrenci sınıfı kullanmadan yapılan işlemler
    /*
    //user interface setup edildikten sonra yani uygulama çalışır çalışırmaz dosyadaki bilgileri okuma işlemi
    // Dosya oluşturduğumuzda oluşan dosya proje dosyasında değil o projenin ismiyle oluşan build dosyasında bulunur.
    QFile my_file("gecenler.txt");
    if(!my_file.exists())
    {
        QMessageBox::information(this, "UYARI!", "Böyle bir dosya bulunmamaktadır.", "Tamam");
        return;
    }
    else if(!my_file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(this, "UYARI!", my_file.errorString(), "Tamam");
        return;
    }
    QTextStream stream(&my_file);
    while(!stream.atEnd())
    {
        ui->listWidget_gecenler->addItem(stream.readLine());  //satır satır okuma için readLine kullanılır.
    }
    my_file.close();

    QFile my_file2("kalanlar.txt");
    if(!my_file2.exists())
    {
        QMessageBox::information(this, "UYARI!", "Böyle bir dosya bulunmamaktadır.", "Tamam");
        return;
    }
    else if(!my_file2.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(this, "UYARI!", my_file2.errorString(), "Tamam");
        return;
    }
    QTextStream stream2(&my_file2);
    while(!stream2.atEnd())
    {
        ui->listWidget_kalanlar->addItem(stream2.readLine());  //satır satır okuma için readLine kullanılır.
    }
    my_file2.close();
    */
}

Dialog::~Dialog()
{
    //user interface delete yapılmadan önce öğrencilerin bilgilerini dosyaya yazdırma işlemi
    QFile my_file("tumogrenciler.txt");
    if(!my_file.open(QIODevice::WriteOnly | QIODevice::Append))  //ilki dosyaya yazma ikincisi ekleme modunda açma
    //sadece yazma modunda açarsak önceki ekleneni siler son yazdığımızı ekler.
    {
        QMessageBox::information(this, "UYARI!", my_file.errorString(),"Tamam");
        return;
    }
    QTextStream stream(&my_file);
    Ogrenci *ogr;
    foreach(ogr, ogrler)
    {
        stream << ogr->ad+" "+ogr->soyad+" "+"Geçme Notu:"+QString::number(ogr->GecmeNotuHesapla(ogr->vize_notu, ogr->final_notu))+"\n";
    }
    my_file.close();
    delete ui;
}


void Dialog::on_btn_Hesapla_clicked()
{
    Ogrenci *ogr=new Ogrenci(ui->ln_ad->text(), ui->ln_soyad->text(), ui->ln_vizenot->text().toInt(), ui->ln_finalnot->text().toInt());
    ogrler.append(ogr);
    double gecme_notu=ogr->GecmeNotuHesapla(ogr->vize_notu, ogr->final_notu);
    if(gecme_notu >= 60)
    {
        ui->listWidget_gecenler->addItem(ogr->ad+" "+ogr->soyad+" "+"Geçme Notu:"+QString::number(gecme_notu));
        QFile my_file("gecenler.txt");
        if(!my_file.open(QIODevice::WriteOnly | QIODevice::Append))  //ilki dosyaya yazma ikincisi ekleme modunda açma
        //sadece yazma modunda açarsak önceki ekleneni siler son yazdığımızı ekler.
        {
            QMessageBox::information(this, "UYARI!", my_file.errorString(),"Tamam");
            return;
        }
        QTextStream stream(&my_file);
        stream << ogr->ad+" "+ogr->soyad+" "+"Geçme Notu:"+QString::number(gecme_notu)+"\n";
        my_file.close();
    }
    else
    {
        ui->listWidget_kalanlar->addItem(ogr->ad+" "+ogr->soyad+" "+"Geçme Notu:"+QString::number(gecme_notu));
        QFile my_file("kalanlar.txt");
        if(!my_file.open(QIODevice::WriteOnly | QIODevice::Append))
        //if ile dosya açılır ve açılıp açılmadığı kontrol edilir.
        {
            QMessageBox::information(this, "UYARI!", my_file.errorString(),"Tamam");
            return;
        }
        QTextStream stream(&my_file);
        stream << ogr->ad+" "+ogr->soyad+" "+"Geçme Notu:"+QString::number(gecme_notu)+"\n";
        my_file.close();
    }




    //ogrenci sınıfı kullanılmadan yapılan işlemler
    /*
    double gecme_notu;
    gecme_notu=(ui->ln_vizenot->text().toDouble()*0.4)+(ui->ln_finalnot->text().toDouble()*0.6);
    if(gecme_notu >= 60)
    {
        ui->listWidget_gecenler->addItem(ui->ln_ad->text()+" "+ui->ln_soyad->text()+" "+"Geçme Notu:"+QString::number(gecme_notu));
        QFile my_file("gecenler.txt");
        if(!my_file.open(QIODevice::WriteOnly | QIODevice::Append))  //ilki dosyaya yazma ikincisi ekleme modunda açma
        //sadece yazma modunda açarsak önceki ekleneni siler son yazdığımızı ekler.
        {
            QMessageBox::information(this, "UYARI!", my_file.errorString(),"Tamam");
            return;
        }
        QTextStream stream(&my_file);
        stream << ui->ln_ad->text()+" "+ui->ln_soyad->text()+" "+"Geçme Notu:"+QString::number(gecme_notu)+"\n";
        my_file.close();
    }
    else
    {
        ui->listWidget_kalanlar->addItem(ui->ln_ad->text()+" "+ui->ln_soyad->text()+" "+"Geçme Notu:"+QString::number(gecme_notu));
        QFile my_file("kalanlar.txt");
        if(!my_file.open(QIODevice::WriteOnly | QIODevice::Append))
        //if ile dosya açılır ve açılıp açılmadığı kontrol edilir.
        {
            QMessageBox::information(this, "UYARI!", my_file.errorString(),"Tamam");
            return;
        }
        QTextStream stream(&my_file);
        stream << ui->ln_ad->text()+" "+ui->ln_soyad->text()+" "+"Geçme Notu:"+QString::number(gecme_notu)+"\n";
        my_file.close();
    }
    */
}
