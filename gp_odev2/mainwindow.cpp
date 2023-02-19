#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ogrenci.h"
#include "dersler.h"
#include "notlar.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    vt.setDatabaseName("D:/gorsel_programlama_kodlari/veri_tabani/gp_odev2.db");
    if(!vt.open())
    {
        ui->statusbar->showMessage("Veri tabanına bağlanılamadı!");
    }
    else
    {
        ui->statusbar->showMessage("Veri tabanına bağlanıldı!");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pbtn_ogr_clicked()
{
    ogrenci *ogr=new ogrenci(vt);
    ogr->show();
}

void MainWindow::on_pbtn_ders_clicked()
{
    dersler *ders=new dersler(vt);
    ders->show();
}

void MainWindow::on_pbtn_not_clicked()
{
    notlar *nots=new notlar(vt);
    nots->show();
}



