#include "show_accounts.h"
#include "ui_show_accounts.h"
//#define Path_to_DB "C:/Users/SashIKa/Documents/my.sqlite"
Show_Accounts::Show_Accounts(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Show_Accounts)
{
    ui->setupUi(this);
    //setWindowIcon(QIcon("qtest16.ico"));
    setWindowTitle("Show Passwords");
}

Show_Accounts::~Show_Accounts()
{
    delete ui;
}

void Show_Accounts::on_pushButton_clicked()
{
    QString uid;
    uid=ui->label_2->text();
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery qry;
    qry.prepare("SELECT Acc_Name as 'Account Name',Password FROM Passwords WHERE UID='"+uid+"'");
    if(qry.exec()){
        modal->setQuery(qry);
        // qDebug()<< (modal->rowCount());
        ui->tableView->setModel(modal);
    }
    else{
        qDebug()<<"Error";
    }
}

