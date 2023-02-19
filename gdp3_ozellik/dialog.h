#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include <QMessageBox>

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
    void on_btn_Checkable_clicked();

    void on_btn_IsChecked_clicked();

    void on_btn_AutoRepeat_clicked();

    void on_btn_ToggleAuto_clicked();

    void on_btn_ToggleDefault_clicked();

    void on_btn_Default_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
