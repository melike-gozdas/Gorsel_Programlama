#include "notlar.h"
#include "ui_notlar.h"

notlar::notlar(QSqlDatabase vt, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::notlar)
{
    ui->setupUi(this);
    sorgu_nots=new QSqlQuery(vt);
    t_model_ogr=new QSqlTableModel();
    t_model_ogr->setTable("öğrenci");
    ui->tableView_ogrnot->setModel(t_model_ogr);
    t_model_ogr->select();
    //not_listele();
    t_model_ders=new QSqlTableModel();
    t_model_ders->setTable("dersler");
    ui->tableView_ogrders->setModel(t_model_ders);
    t_model_ders->select();
    t_model_nots=new QSqlTableModel();
    t_model_nots->setTable("notlar");
    ui->tableView_nots->setModel(t_model_nots);
    t_model_nots->select();
}

notlar::~notlar()
{
    delete ui;
}

void notlar::not_listele()
{
    q_model_nots= new QSqlQueryModel();
    if(sorgu_nots->exec("Select * from notlar"))
    {
        q_model_nots->setQuery(*sorgu_nots);
        ui->tableView_nots->setModel(q_model_nots);
    }
    else
    {
        qDebug() << sorgu_nots->lastError();
    }
}

void notlar::on_tableView_ogrnot_clicked(const QModelIndex &index)
{
    ui->ln_ogrno->setText(t_model_ogr->index(index.row(),0).data().toString());
}

void notlar::on_tableView_ogrders_clicked(const QModelIndex &index)
{
    ui->ln_derskod->setText(t_model_ders->index(index.row(),0).data().toString());
}



void notlar::on_pbtn_dkayit_clicked()
{
    if(ui->ln_ogrno->text()=="" || ui->ln_derskod->text()=="" || ui->ln_vizenot->text()=="" || ui->ln_finalnot->text()=="")
    {
        QMessageBox::critical(this, "Hata!", "Gerekli alanları doldurunuz!");

    }
    int index=0;
    int flag=0;
    while(t_model_nots->index(index,0).data().toString() != "")
    {

        if(t_model_nots->index(index,0).data().toString() == ui->ln_ogrno->text() && t_model_nots->index(index,1).data().toString() == ui->ln_derskod->text())
        {
            QMessageBox::information(this, "Hata!", "Bu öğrenci üzerinde bu ders zaten kayıtlı");
            flag=flag+1;
        }
        index=index+1;
    }
    if(flag==0)
    {
        int gecme_notu=ui->ln_vizenot->text().toInt()*0.4 + ui->ln_finalnot->text().toInt()*0.6;
        sorgu_nots->prepare("insert into notlar(ogr_no, ders_kodu, vize_not, final_not, geçme_notu) values(?, ?, ?, ?, ?)");
        sorgu_nots->addBindValue(ui->ln_ogrno->text().toInt());
        sorgu_nots->addBindValue(ui->ln_derskod->text().toInt());
        sorgu_nots->addBindValue(ui->ln_vizenot->text().toInt());
        sorgu_nots->addBindValue(ui->ln_finalnot->text().toInt());
        sorgu_nots->addBindValue(gecme_notu);
        if(sorgu_nots->exec())
        {
           not_listele();

        }
        else
        {
           QMessageBox::critical(this, "Hata!", "Gerekli alanları doldurunuz!");
        }
        t_model_nots->select();
    }

}
