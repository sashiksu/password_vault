#include "login.h"
#include "ui_login.h"
#include "passvault.h"
#include "ui_passvault.h"
#include "new_user.h"
#include "show_accounts.h"
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>

#define Path_to_DB "C:/Users/SashIKa/Documents/my.sqlite" //this is for windows
//#define Path_to_DB "/home/sashika/Documents/my.sqlite" //this is for linux

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{

    ui->setupUi(this);
    //disable login and clear buttons default because load time text boxes are empty
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);

    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    QPixmap pix(":/file/bar.jpg");
    ui->label_3->setPixmap(pix);
    ui->label_4->setPixmap(pix);

    qDebug()<<Path_to_DB;



    myDB=QSqlDatabase::addDatabase("QSQLITE");
    myDB.setDatabaseName(Path_to_DB);
    QFileInfo checkFile(Path_to_DB);
    if(checkFile.isFile()){
        if(myDB.open()){
            //database connected code
            myDB.open();
        }
        else{
            //qDebug()<<"Not Connected !";
            QMessageBox messageBox;
            messageBox.warning(0,"Information","Database Error !");
        }
    }

}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    /* authenticate user ,
    if user autheticated it show main window;if not show message box*/
    QString User,Pass;
    User=ui->lineEdit->text();
    Pass=ui->lineEdit_2->text();
    QSqlQuery qry;
    qry.prepare("SELECT * FROM Users WHERE UserName=\'"+User+"\' AND Password=\'"+Pass+"\'");
    if(qry.exec()){
        if(qry.next()){
            Show_Accounts *showA=new Show_Accounts();
            PassVault *mainPV= new PassVault();
            QString user_id = qry.value(0).toString();
            showA->USER_ID=user_id;
            QString user_name = qry.value(1).toString();
            mainPV->ui->label->setText(user_id);
            mainPV->ui->label_3->setText(user_name);
            mainPV->show();
            this->hide();
        }
        else{
            QMessageBox messageBox;
            messageBox.information(0,"Information","Check UserName & Password Again !");
        }
    }
}

void Login::on_pushButton_2_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}

void Login::on_pushButton_3_clicked()
{
    close();
}

void Login::on_commandLinkButton_clicked()
{
    New_User *newU= new New_User();
    newU->show();
    this->close();
}
void Login::check_textbox(){
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

void Login::on_lineEdit_textChanged(const QString &arg1)
{
    check_textbox();
}

void Login::on_lineEdit_2_textChanged(const QString &arg1)
{
    check_textbox();
}
