#ifndef OGRENCI_H
#define OGRENCI_H

#include <QDialog>
#include <QMessageBox>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlError>

namespace Ui {
class ogrenci;
}

class ogrenci : public QDialog
{
    Q_OBJECT

public:
    explicit ogrenci(QSqlDatabase, QWidget *parent = nullptr);
    ~ogrenci();
    void ogr_listele();

private slots:
    void on_pbtn_yenikayit_clicked();

    void on_tableView_ogr_clicked(const QModelIndex &index);

    void on_pbtn_sil_clicked();

    void on_pbtn_guncelle_clicked();

private:
    Ui::ogrenci *ui;
    QSqlQuery *sorgu_ogr, *sorgu_sogr;
    QSqlQueryModel *q_model_ogr, *q_model_sogr;
    QSqlTableModel *t_model_ogr, *t_model_sogr;
};

#endif // OGRENCI_H
