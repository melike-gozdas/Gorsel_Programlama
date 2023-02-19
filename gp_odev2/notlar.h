#ifndef NOTLAR_H
#define NOTLAR_H

#include <QDialog>
#include <QMessageBox>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlError>

namespace Ui {
class notlar;
}

class notlar : public QDialog
{
    Q_OBJECT

public:
    explicit notlar(QSqlDatabase, QWidget *parent = nullptr);
    ~notlar();
    void not_listele();

private slots:
    void on_tableView_ogrnot_clicked(const QModelIndex &index);

    void on_tableView_ogrders_clicked(const QModelIndex &index);

    void on_pbtn_dkayit_clicked();

private:
    Ui::notlar *ui;
    QSqlQuery *sorgu_nots;
    QSqlQueryModel *q_model_ogr, *g_model_ders, *q_model_nots;
    QSqlTableModel *t_model_ogr, *t_model_ders, *t_model_nots;
};

#endif // NOTLAR_H
