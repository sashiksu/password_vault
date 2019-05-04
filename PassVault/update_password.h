#ifndef UPDATE_PASSWORD_H
#define UPDATE_PASSWORD_H
#include <QWidget>
#include <QDialog>
#include <QMessageBox>
#include <QMainWindow>
#include <QtDebug>
#include <QtSql>
#include <QFileInfo>

namespace Ui {
class Update_Password;
}

class Update_Password : public QWidget
{
    Q_OBJECT

public:
    explicit Update_Password(QWidget *parent = nullptr);
    ~Update_Password();
    Ui::Update_Password *ui;
    void load_password();

private slots:
    void on_pushButton_clicked();

private:
    //Ui::Update_Password *ui;
};

#endif // UPDATE_PASSWORD_H
