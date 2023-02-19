#ifndef PERSONEL_H
#define PERSONEL_H

#include <QDialog>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QMessageBox>

namespace Ui {
class personel;
}

class personel : public QDialog
{
    Q_OBJECT

public:
    explicit personel(QSqlDatabase, QWidget *parent = nullptr);
    ~personel();
    void listele();

private slots:
    void on_btn_kaydet_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_btn_guncelle_clicked();

    void on_btn_sil_clicked();

private:
    Ui::personel *ui;
    QSqlQuery *sorgu;
    QSqlQueryModel *model;
};

#endif // PERSONEL_H
