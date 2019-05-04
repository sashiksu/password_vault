#include "update_password.h"
#include "ui_update_password.h"

Update_Password::Update_Password(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Update_Password)
{
    ui->setupUi(this);
    load_password();
    setWindowTitle("Update Password");
}

Update_Password::~Update_Password()
{
    delete ui;
}

void Update_Password::load_password()
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

void Update_Password::on_pushButton_clicked()
{
    QString Acc,uid,Pass;
    Acc=ui->comboBox->currentText();
    uid=ui->label_2->text();
    Pass=ui->lineEdit->text();
    QSqlQuery qry;
    qry.prepare("UPDATE Passwords SET Password='"+Pass+"' WHERE Acc_Name='"+Acc+"' AND UID='"+uid+"'");
    if(qry.exec()){
        QMessageBox messageBox;
        messageBox.information(0,"Information","Your Password Updated !");
    }
    else{
        //qDebug()<<"Error";
         qDebug() << "Error loading database:" << qry.lastError();
    }
}
