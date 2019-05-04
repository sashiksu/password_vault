#include "delete_password.h"
#include "ui_delete_password.h"

Delete_Password::Delete_Password(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Delete_Password)
{

    ui->setupUi(this);
    setWindowTitle("Delete Password");
    load_passwords();
}

Delete_Password::~Delete_Password()
{
    delete ui;
}

void Delete_Password::load_passwords()
{

    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery qry;
    qry.prepare("SELECT distinct Acc_Name FROM Passwords");
    if(qry.exec()){
        modal->setQuery(qry);
        ui->comboBox->setModel(modal);
    }
    else{
        qDebug()<<"Error";
    }
}

void Delete_Password::on_pushButton_clicked()
{
    QString Acc,uid;
    Acc=ui->comboBox->currentText();
    uid=ui->label_2->text();
    QSqlQuery qry;
    qry.prepare("DELETE FROM Passwords WHERE Acc_Name='"+Acc+"' AND UID='"+uid+"'");
    if(qry.exec()){
        QMessageBox messageBox;
        messageBox.information(0,"Information","Your Password Deleted !");
    }
    else{
        qDebug()<<"Error";
    }
}
