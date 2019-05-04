#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    //setWindowIcon(QIcon("qtest16.ico"));
    setWindowTitle("About");
}

About::~About()
{
    delete ui;
}
