#ifndef NEW_ACCOUNT_H
#define NEW_ACCOUNT_H

#include <QWidget>
#include <QDialog>
#include <QMessageBox>
#include <QMainWindow>
#include <QtDebug>
#include <QtSql>
#include <QFileInfo>
namespace Ui {
class New_Account;
}

class New_Account : public QWidget
{
    Q_OBJECT

public:
    explicit New_Account(QWidget *parent = nullptr);
    ~New_Account();
    Ui::New_Account *ui;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void check_textbox();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

private:
    //Ui::New_Account *ui;
    QSqlDatabase myDB;
};

#endif // NEW_ACCOUNT_H
