#include "new_account.h"
#include "ui_new_account.h"
#include "passvault.h"
#include "ui_passvault.h"
//#define Path_to_DB "C:/Users/SashIKa/Documents/my.sqlite"
New_Account::New_Account(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::New_Account)
{
    ui->setupUi(this);
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);

    setWindowTitle("New Account");
    ui->lineEdit->setFocus();
    resize(300,200);

}

New_Account::~New_Account()
{
    delete ui;
}

void New_Account::on_pushButton_clicked()
{
    QString Account_Name,Password,Uid;
    Account_Name=ui->lineEdit->text();
    Password=ui->lineEdit_2->text();
    Uid=ui->label_4->text();
    QSqlQuery qry;
    qry.prepare("INSERT INTO Passwords (Acc_Name,Password,UID) VALUES (\'"+Account_Name+"\' ,\'"+Password+"\',\'"+Uid+"\')");
    if(qry.exec()){
        QMessageBox messageBox;
        messageBox.information(0,"Information","Your Password Saved !");
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
    }
    else{
        QMessageBox messageBox;
        messageBox.information(0,"Information","Database Error !");
    }
}

void New_Account::on_pushButton_2_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}
void New_Account::check_textbox(){
    if(ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty()){
        ui->pushButton->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
    }
    else
    {
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
    }
}
void New_Account::on_lineEdit_textChanged(const QString &arg1)
{
    check_textbox();
}

void New_Account::on_lineEdit_2_textChanged(const QString &arg1)
{
   check_textbox();
}
