#include "dersler.h"
#include "ui_dersler.h"

dersler::dersler(QSqlDatabase vt, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dersler)
{
    ui->setupUi(this);
    sorgu_ders=new QSqlQuery(vt);
    sorgu_ders_alan=new QSqlQuery(vt);
    t_model_ders=new QSqlTableModel();
    t_model_ders->setTable("dersler");
    ui->tableView_ders->setModel(t_model_ders);
    t_model_ders->select();
    ders_listele();
}

dersler::~dersler()
{
    delete ui;
}

void dersler::ders_listele()
{
    q_model_ders= new QSqlQueryModel();
    if(sorgu_ders->exec("Select * from dersler"))
    {
        q_model_ders->setQuery(*sorgu_ders);
        ui->tableView_ders->setModel(q_model_ders);
    }
    else
    {
        qDebug() << sorgu_ders->lastError();
    }
}


void dersler::on_tableView_ders_clicked(const QModelIndex &index)
{
    ui->lnedt_derskod->setText(t_model_ders->index(index.row(),0).data().toString());
    ui->lnedt_dersad->setText(t_model_ders->index(index.row(),1).data().toString());

    q_model_sdnot=new QSqlQueryModel();
    sorgu_ders_alan->prepare("SELECT * FROM notlar WHERE ders_kodu =?");
    sorgu_ders_alan->addBindValue(ui->lnedt_derskod->text().toInt());
    if(sorgu_ders_alan->exec())
    {
        q_model_sdnot->setQuery(*sorgu_ders_alan);
        ui->tableView_dersogr->setModel(q_model_sdnot);
    }
    else
    {
        qDebug() << sorgu_ders_alan->lastError();
    }

}

void dersler::on_pbtn_yenikayit_clicked()
{
    if(ui->lnedt_derskod->text()=="" || ui->lnedt_dersad->text()=="")
    {
        QMessageBox::critical(this, "Hata!", "Gerekli alanları doldurunuz!");

    }
    int index=0;
    int flag=0;
    while(t_model_ders->index(index,0).data().toString() != "")
    {

        if(t_model_ders->index(index,0).data().toString() == ui->lnedt_derskod->text())
        {
            flag=flag+1;
            break;
        }
        index=index+1;
    }
    if(flag == 0)
    {
        sorgu_ders->prepare("insert into dersler(ders_kodu, ders_adi) values(?, ?)");
        sorgu_ders->addBindValue(ui->lnedt_derskod->text().toInt());
        sorgu_ders->addBindValue(ui->lnedt_dersad->text());
        if(sorgu_ders->exec())
        {
           ders_listele();

        }
        else
        {
           QMessageBox::critical(this, "Hata!", "Gerekli alanları doldurunuz!");
        }
        t_model_ders->select();
    }
    else
    {
        QMessageBox::information(this, "Hata!", "Bu kodda başka bir ders vardır. Farklı kodda ders ekleyiniz!");
    }

}

void dersler::on_pbtn_guncelle_clicked()
{
    if(ui->lnedt_derskod->text()=="" || ui->lnedt_dersad->text()=="")
    {
        QMessageBox::critical(this, "Hata!", "Gerekli alanları doldurunuz!");

    }
    else
    {
        sorgu_ders->prepare("update dersler set ders_adi=? where ders_kodu=? ");
        sorgu_ders->addBindValue(ui->lnedt_dersad->text());
        sorgu_ders->addBindValue(ui->lnedt_derskod->text().toInt());
        if(sorgu_ders->exec())
        {
           ders_listele();
        }
        else
        {
           QMessageBox::critical(this, "Hata!", "Gerekli alanları doldurunuz!");
        }
        t_model_ders->select();
    }

}



void dersler::on_pbtn_sil_clicked()
{
    int index1=0, index2=0;
    int flag=0;
    while(q_model_ders->index(index1,0).data().toString() != "" && q_model_sdnot->index(index2,1).data().toString() != "")
    {

        if(q_model_ders->index(index1,0).data().toString() == q_model_sdnot->index(index2,1).data().toString())
        {
            flag=flag+1;
            break;
        }
        index1=index1+1;
        index2=index2+1;
    }
    if(flag == 0)
    {
        sorgu_ders->prepare("delete from dersler where ders_kodu=?");
        sorgu_ders->addBindValue(ui->lnedt_derskod->text().toInt());
        if(sorgu_ders->exec())
        {
           ders_listele();
        }
        else
        {
           QMessageBox::critical(this, "Hata!", "Gerekli alanları doldurunuz!");
        }
        t_model_ders->select();
    }
    else
    {
        QMessageBox::information(this, "Hata!", "Bu ders silinemez. Bu derse kayıtlı öğrenciler vardır!");
    }
}


