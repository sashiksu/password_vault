#ifndef SHOW_ACCOUNTS_H
#define SHOW_ACCOUNTS_H
#include <QWidget>
#include <QDialog>
#include <QMessageBox>
#include <QMainWindow>
#include <QtDebug>
#include <QtSql>
#include <QFileInfo>
namespace Ui {
class Show_Accounts;
}

class Show_Accounts : public QWidget
{
    Q_OBJECT

public:
    explicit Show_Accounts(QWidget *parent = nullptr);
    ~Show_Accounts();
    Ui::Show_Accounts *ui;
    QString USER_ID;

private slots:
    void on_pushButton_clicked();


private:
    //Ui::Show_Accounts *ui;
    QSqlDatabase myDB;

};

#endif // SHOW_ACCOUNTS_H
