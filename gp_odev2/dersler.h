#ifndef DERSLER_H
#define DERSLER_H

#include <QDialog>
#include <QMessageBox>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlError>

namespace Ui {
class dersler;
}

class dersler : public QDialog
{
    Q_OBJECT

public:
    explicit dersler(QSqlDatabase, QWidget *parent = nullptr);
    ~dersler();
    void ders_listele();

private slots:
    void on_tableView_ders_clicked(const QModelIndex &index);

    void on_pbtn_yenikayit_clicked();

    void on_pbtn_guncelle_clicked();

    void on_pbtn_sil_clicked();

private:
    Ui::dersler *ui;
    QSqlQuery *sorgu_ders, *sorgu_ders_alan, *sorgu_ders_sil;
    QSqlQueryModel *q_model_ders, *q_model_sdnot, *q_model_dsil;
    QSqlTableModel *t_model_ders, *t_model_sdnot;
};

#endif // DERSLER_H
