#include "passvault.h"
#include "ui_passvault.h"
#include "ui_passvault.h"
#include "new_account.h"
#include "ui_new_account.h"
#include "show_accounts.h"
#include "ui_show_accounts.h"
#include "delete_password.h"
#include "ui_delete_password.h"
#include "about.h"
#include "login.h"
#include "update_password.h"
#include "ui_update_password.h"
#include <QMdiSubWindow>
#include <QDateTime>
PassVault::PassVault(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PassVault)
{
    ui->setupUi(this);
    //setWindowIcon(QIcon("qtest16.ico"));
    setWindowTitle("Pass Vault");

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(myfunction()));
    timer->start(1000);
    myfunction();

}

PassVault::~PassVault()
{
    delete ui;
}

void PassVault::loadSubWindow(QWidget *widget)
{
    auto window = ui->mdiArea->addSubWindow(widget);
    window->setWindowTitle(widget->windowTitle());
    window->setWindowIcon(widget->windowIcon());
    window->resize(400,212);
    window->setWindowFlags(Qt::Window);
    window->show();
}

void PassVault::myfunction()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh : mm : ss");
    if ((time.second() % 2) == 0)
    {
        text[3] = ' ';
        text[8] = ' ';
    }
    ui->label_2->setText(text);
}


void PassVault::on_pushButton_clicked()
{
    QString uid=ui->label->text();
    New_Account *na= new New_Account();
    na->ui->label_4->setText(uid);
    loadSubWindow(na);
}

void PassVault::on_pushButton_2_clicked()
{
    QString uid=ui->label->text();
    Show_Accounts *sa= new Show_Accounts();
    sa->ui->label_2->setText(uid);
    loadSubWindow(sa);
}

void PassVault::on_actionNew_Account_triggered()
{
    QString uid=ui->label->text();
    New_Account *na= new New_Account();
    na->ui->label_4->setText(uid);
    loadSubWindow(na);

}

void PassVault::on_actionExit_triggered()
{
    close();
}

void PassVault::on_actionShow_My_Passwords_triggered()
{
    QString uid=ui->label->text();
    Show_Accounts *sa= new Show_Accounts();
    sa->ui->label_2->setText(uid);
    loadSubWindow(sa);
}

void PassVault::on_actionAbout_triggered()
{
    loadSubWindow(new About(this));
}

void PassVault::on_pushButton_3_clicked()
{
    Login *lgn=new Login();
    lgn->show();
    this->close();
}
void PassVault::GetRandomString()
{
    const QString possibleCharacters("`~!@#$%^&*()-_=+<,>.?/[]{}ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
    const int randomStringLength = 8; // assuming you want random strings of 8 characters

    QString randomString;
    for(int i=0; i<randomStringLength; ++i)
    {
        int index = qrand() % possibleCharacters.length();
        QChar nextChar = possibleCharacters.at(index);
        randomString.append(nextChar);
    }
    ui->lineEdit->setText(randomString);
}

void PassVault::on_pushButton_4_clicked()
{
    GetRandomString();
}



void PassVault::on_actionDelete_Password_triggered()
{
    QString uid=ui->label->text();
    Delete_Password *da= new Delete_Password();
    da->ui->label_2->setText(uid);
    loadSubWindow(da);
}



void PassVault::on_actionUpdate_Password_triggered()
{
    QString uid=ui->label->text();
    Update_Password *up =new Update_Password();
    up->ui->label_2->setText(uid);
    loadSubWindow(up);
}
