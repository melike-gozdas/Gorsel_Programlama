#include "dialog.h"
#include "ui_dialog.h"
#include "QClipboard"

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

//QClipboard sınıfı ile oluşturulan clipboard nesnesi ile windows panosuna erişmiş olurum.
void Dialog::on_pushButton_clicked()
{
    QClipboard* clipboard = QApplication::clipboard();
    clipboard->setText(ui->lineEdit->text());
}
