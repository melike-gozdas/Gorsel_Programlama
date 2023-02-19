#include "personel.h"
#include "ui_personel.h"

personel::personel(QSqlDatabase db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::personel)
{
    ui->setupUi(this);
    sorgu=new QSqlQuery(db);
    listele();

}

personel::~personel()
{
    delete ui;
}

void personel::listele()
{
    model=new QSqlQueryModel();
    if(sorgu->exec("Select * from personel"))
    {
        model->setQuery(*sorgu);
        ui->tableView->setModel(model);
    }
    else
        qDebug() << sorgu->lastError();

}

void personel::on_btn_kaydet_clicked()
{
    sorgu->prepare("insert into personel(personel_ad,personel_soyad,departman_id) values(?, ?, ?)");
    sorgu->addBindValue(ui->edt_per_ad->text());
    sorgu->addBindValue(ui->edt_per_soyad->text());
    sorgu->addBindValue(ui->edt_depar_id->text().toInt());
    if(!sorgu->exec())
    {
        QMessageBox::critical(this,"Hata!",sorgu->lastError().text());
    }
    listele();
}

void personel::on_tableView_clicked(const QModelIndex &index)
{
    ui->edt_per_id->setText(model->index(index.row(),0).data().toString());
    ui->edt_per_ad->setText(model->index(index.row(),1).data().toString());
    ui->edt_per_soyad->setText(model->index(index.row(),2).data().toString());
    ui->edt_depar_id->setText(model->index(index.row(),3).data().toString());
}

void personel::on_btn_guncelle_clicked()
{
    sorgu->prepare("update personel set personel_ad=?, personel_soyad=?, departman_id=? where personel_id=?");
    sorgu->addBindValue(ui->edt_per_ad->text());
    sorgu->addBindValue(ui->edt_per_soyad->text());
    sorgu->addBindValue(ui->edt_depar_id->text().toInt());
    sorgu->addBindValue(ui->edt_per_id->text().toInt());
    if(!sorgu->exec())
    {
        QMessageBox::critical(this,"Hata!",sorgu->lastError().text());
    }
    listele();
}

void personel::on_btn_sil_clicked()
{
    sorgu->prepare("delete from personel where personel_id=?");
    sorgu->addBindValue(ui->edt_per_id->text().toInt());
    if(!sorgu->exec())
    {
        QMessageBox::critical(this,"Hata!",sorgu->lastError().text());
    }
    listele();
}
