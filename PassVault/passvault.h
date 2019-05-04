#ifndef PASSVAULT_H
#define PASSVAULT_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class PassVault;
}

class PassVault : public QMainWindow
{
    Q_OBJECT

public:
    explicit PassVault(QWidget *parent = nullptr);
    ~PassVault();
    Ui::PassVault *ui;


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_actionNew_Account_triggered();

    void on_actionExit_triggered();

    void on_actionShow_My_Passwords_triggered();

    void on_actionAbout_triggered();

    void on_pushButton_3_clicked();
    void myfunction();
    void GetRandomString();

    void on_pushButton_4_clicked();



    void on_actionDelete_Password_triggered();

    void on_actionUpdate_Password_triggered();

private:
    //Ui::PassVault *ui;
    void loadSubWindow(QWidget *widget);
    QTimer *timer;

};

#endif // PASSVAULT_H
