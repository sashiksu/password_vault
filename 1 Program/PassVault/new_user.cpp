#include "new_user.h"
#include "ui_new_user.h"
#include "login.h"

New_User::New_User(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::New_User)
{
    ui->setupUi(this);
    setWindowTitle("New User");
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
}

New_User::~New_User()
{
    delete ui;
}

void New_User::on_pushButton_3_clicked()
{
    close();
}

void New_User::on_pushButton_4_clicked()
{
    Login *lgn= new Login();
    lgn->show();
    this->close();
}

void New_User::on_pushButton_2_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}

void New_User::on_pushButton_clicked()
{
    QString Account_Name,Password;
    Account_Name=ui->lineEdit->text();
    Password=ui->lineEdit_2->text();
    QSqlQuery qry;
    qry.prepare("INSERT INTO Users (UserName,Password) VALUES (\'"+Account_Name+"\' ,\'"+Password+"\')");
    if(qry.exec()){
        QMessageBox messageBox;
        messageBox.information(0,"Information","You Have Successfully Created Account !");
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
    }
    else{
        QMessageBox messageBox;
        messageBox.warning(0,"Information","Error");
    }
}
void New_User::check_textbox(){
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

void New_User::on_lineEdit_textChanged(const QString &arg1)
{
    check_textbox();
}

void New_User::on_lineEdit_2_textChanged(const QString &arg1)
{
 check_textbox();
}
