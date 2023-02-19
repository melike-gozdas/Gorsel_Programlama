#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlError>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pbtn_ogr_clicked();

    void on_pbtn_ders_clicked();

    void on_pbtn_not_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase vt=QSqlDatabase::addDatabase("QSQLITE");
    QSqlTableModel *t_model_ogr, *t_model_ders, *t_model_nots;
    QSqlQueryModel *q_model, *q_model_ders, *q_model_nots;
    QSqlQuery *sorgu;
};
#endif // MAINWINDOW_H
