#ifndef DELETE_PASSWORD_H
#define DELETE_PASSWORD_H
#include <QWidget>
#include <QDialog>
#include <QMessageBox>
#include <QMainWindow>
#include <QtDebug>
#include <QtSql>
#include <QFileInfo>
namespace Ui {
class Delete_Password;
}

class Delete_Password : public QWidget
{
    Q_OBJECT

public:
    explicit Delete_Password(QWidget *parent = nullptr);
    ~Delete_Password();
    Ui::Delete_Password *ui;
    void load_passwords();

private slots:
    void on_pushButton_clicked();

private:
    //Ui::Delete_Password *ui;
};

#endif // DELETE_PASSWORD_H
