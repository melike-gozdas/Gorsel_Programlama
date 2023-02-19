#include "ogrenci.h"
#include "ui_ogrenci.h"

ogrenci::ogrenci(QSqlDatabase vt, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ogrenci)
{
    ui->setupUi(this);
    sorgu_ogr=new QSqlQuery(vt);
    t_model_ogr=new QSqlTableModel();
    t_model_ogr->setTable("öğrenci");
    ui->tableView_ogr->setModel(t_model_ogr);
    t_model_ogr->select();
    ogr_listele();
    t_model_sogr=new QSqlTableModel();
    t_model_sogr->setTable("notlar");
    t_model_sogr->select();
}

ogrenci::~ogrenci()
{
    delete ui;
}

void ogrenci::ogr_listele()
{
    q_model_ogr= new QSqlQueryModel();
    if(sorgu_ogr->exec("Select * from öğrenci"))
    {
        q_model_ogr->setQuery(*sorgu_ogr);
        ui->tableView_ogr->setModel(q_model_ogr);
    }
    else
    {
        qDebug() << sorgu_ogr->lastError();
    }
}

void ogrenci::on_tableView_ogr_clicked(const QModelIndex &index)
{
    ui->lnedt_ogrno->setText(t_model_ogr->index(index.row(),0).data().toString());
    ui->lnedt_ograd->setText(t_model_ogr->index(index.row(),1).data().toString());
    ui->lnedt_ogrsoyad->setText(t_model_ogr->index(index.row(),2).data().toString());
}

void ogrenci::on_pbtn_yenikayit_clicked()
{
    if(ui->lnedt_ograd->text()=="" || ui->lnedt_ogrsoyad->text()=="")
    {
        QMessageBox::critical(this, "Hata!", "Gerekli alanları doldurunuz!");

    }
    else
    {
        sorgu_ogr->prepare("insert into öğrenci(ogr_ad, ogr_soyad) values(?, ?)");
        sorgu_ogr->addBindValue(ui->lnedt_ograd->text());
        sorgu_ogr->addBindValue(ui->lnedt_ogrsoyad->text());
        if(sorgu_ogr->exec())
        {
           ogr_listele();
        }
        else
        {
           QMessageBox::critical(this, "Hata!", "Gerekli alanları doldurunuz!");
        }
        t_model_ogr->select();
    }


}

void ogrenci::on_pbtn_sil_clicked()
{
    int index1=0, index2=0;
    int flag=0;
    while(t_model_sogr->index(index2,0).data().toString() != "")
    {

        if(ui->lnedt_ogrno->text() == t_model_sogr->index(index2,0).data().toString())
        {
            flag=flag+1;
            break;
        }
        index1=index1+1;
        index2=index2+1;
    }
    if(flag == 0)
    {
        sorgu_ogr->prepare("delete from öğrenci where ogr_no=?");
        sorgu_ogr->addBindValue(ui->lnedt_ogrno->text().toInt());
        if(sorgu_ogr->exec())
        {
           ogr_listele();
        }
        else
        {
           QMessageBox::critical(this, "Hata!", "Gerekli alanları doldurunuz!");
        }
        t_model_ogr->select();
    }
    else
    {
        QMessageBox::information(this, "Hata!", "Bu öğrenci silinemez. Bu öğrencinin üstüne tanımlanmış dersler vardır!");
    }
}


void ogrenci::on_pbtn_guncelle_clicked()
{
    if(ui->lnedt_ograd->text()=="" || ui->lnedt_ogrsoyad->text()=="")
    {
        QMessageBox::critical(this, "Hata!", "Gerekli alanları doldurunuz!");

    }
    else
    {
        sorgu_ogr->prepare("update öğrenci set ogr_ad=?, ogr_soyad=? where ogr_no=?");
        sorgu_ogr->addBindValue(ui->lnedt_ograd->text());
        sorgu_ogr->addBindValue(ui->lnedt_ogrsoyad->text());
        sorgu_ogr->addBindValue(ui->lnedt_ogrno->text().toInt());
        if(sorgu_ogr->exec())
        {
           ogr_listele();

        }
        else
        {
           QMessageBox::critical(this, "Hata!", "Gerekli alanları doldurunuz!");
        }
        t_model_ogr->select();
    }

}



