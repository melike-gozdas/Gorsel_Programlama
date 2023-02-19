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


void Dialog::on_btn_uygula_clicked()
{
    ui->label_goster->setEnabled(true);
    QString yazi_tipi, renk, yazi;
    yazi_tipi=ui->fontComboBox->currentText();
    int size=ui->spinBox_fontsize->value();  //integer değer olarak almak için bu şekilde tanımladık.
    renk=ui->comboBox->currentText();
    yazi=ui->ln_yaz->text();
    ui->label_goster->setText(yazi);
    //Stil Ayarlamaları
    QFont my_font(yazi_tipi, size);
    if(ui->checkBox_bold->isChecked())
    {
        my_font.setBold(true);
    }
    if(ui->checkBox_italik->isChecked())
    {
        my_font.setItalic(true);
    }
    QPalette my_color;
    my_color.setColor(QPalette::WindowText, ui->comboBox->currentText());
    ui->label_goster->setFont(my_font);
    ui->label_goster->setPalette(my_color);
}
