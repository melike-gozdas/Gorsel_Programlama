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


void Dialog::on_btn_Checkable_clicked()
{
    qDebug() << "Tıklandı mı? :" << ui->btn_Checkable->isChecked();
    //dialog.ui de bu butonun checkable tikini aç
}

void Dialog::on_btn_IsChecked_clicked()
{
    QString message;
    if (ui->btn_Checkable->isChecked())
    {
        message="EVET tıklandı. Checkable aktif.";
    }
    else
    {
        message="HAYIR tıklanmadı. Checkable aktif değil.";
    }
    QMessageBox::information(this,"Durum", message);
}

void Dialog::on_btn_AutoRepeat_clicked()
{
    qInfo() <<"Buton basılı durumda";
    //dialog.ui de bu butonun autorepeat tikini aç
}

void Dialog::on_btn_ToggleAuto_clicked()
{
    bool durum = !ui->btn_AutoRepeat->autoRepeat();
    ui->btn_AutoRepeat->setAutoRepeat(durum);
    qDebug() << "Auto Repeat buton durumu:"<< ui->btn_AutoRepeat->autoRepeat();
}

void Dialog::on_btn_Default_clicked()
{
    QMessageBox::information(this, "Durum", "Default Klavyeden Tıklandı.");
    //dialog.ui de bu butonun autodefault ve default tikini aç
    //bu şekilde fare kullanmadan default olan buton enterla tıklanır.
}

void Dialog::on_btn_ToggleDefault_clicked()
{

}

