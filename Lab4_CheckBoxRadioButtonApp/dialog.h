#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_rd_lisans_clicked();

    void on_rd_lisansustu_clicked();

    void on_btn_bilgileriYazdir_clicked();

    void on_btn_mezuniyetSorgula_clicked();

    void on_btn_ogrDurumYazdir_clicked();

    bool MezuniyetSorgula();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
