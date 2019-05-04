#ifndef LOGIN_H
#define LOGIN_H
#include <QWidget>
#include <QDialog>
#include <QMessageBox>
#include <QMainWindow>
#include <QtDebug>
#include <QtSql>
#include <QFileInfo>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_commandLinkButton_clicked();
    void check_textbox();


    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

private:
    Ui::Login *ui;
    QSqlDatabase myDB;
};

#endif // LOGIN_H
