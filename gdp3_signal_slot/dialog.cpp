#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->btn_Connect, &QPushButton::clicked, this, &Dialog::yazDbg);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_btn_Editor_clicked()
{
    qDebug() << "yazDbg ile butonun tıklandığı zamanı yazdıracağım.";
    yazDbg();
}

void Dialog::yazDbg()
{
    qInfo() <<"Buton tıklanma zamanı: " << QDateTime::currentDateTime().toString();
    accept(); //Pencereyi kapatır.

}


