#include "dialog.h"
#include "ui_dialog.h"

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


void Dialog::on_btn_baglan_clicked()
{
    sqlitedb.setDatabaseName("D:/gorsel_programlama_kodlari/veri_tabani/myDB.db");
    if(!sqlitedb.open())
    {
        QMessageBox::information(this, "Hata", "Bağlantı sağlanamadı");
    }
    else
    {
        QMessageBox::information(this, "Durum", "Bağlantı BAŞARILI ");
    }
}

void Dialog::on_btn_ekle_clicked()
{
     if(!sqlitedb.open())
     {
         QMessageBox::information(this, "Hata", "Önce veritabanına bağlanınız!!!");
     }
     else
     {
         // SQL sorgu cümlesi çalıştıracağız
         QSqlQuery qry;
         qry.prepare("INSERT INTO uye values(?, ?)");
         qry.addBindValue(ui->edt_ad->text());
         qry.addBindValue(ui->edt_soyad->text());
         if(qry.exec())
         {
             QMessageBox::information(this, "durum", "Eklendi");
         }
         else
         {
             qDebug() << qry.lastError();
         }
     }
}

void Dialog::on_btn_listele_clicked()
{
    QSqlQuery sorgu;
    model=new QSqlQueryModel();
    if(sorgu.exec("Select * from uye"))
    {
        model->setQuery(sorgu);
        ui->tableView->setModel(model);
    }
    else
    {
        qDebug() << sorgu.lastError();
    }
}
