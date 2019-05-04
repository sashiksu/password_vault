#include "passvault.h"
#include <QApplication>
#include "login.h"
#include <QSplashScreen>
#include <QTimer>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen *splash=new QSplashScreen;
    splash->setPixmap(QPixmap(":/file/Splash.jpg"));
    splash->show();
    Login l;
    l.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    QTimer::singleShot(1000,splash,SLOT(close()));
    QTimer::singleShot(1000,&l,SLOT(show()));
    return a.exec();
}
