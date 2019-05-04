#ifndef NEW_USER_H
#define NEW_USER_H

#include <QWidget>

namespace Ui {
class New_User;
}

class New_User : public QWidget
{
    Q_OBJECT

public:
    explicit New_User(QWidget *parent = nullptr);
    ~New_User();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();
    void check_textbox();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

private:
    Ui::New_User *ui;
};

#endif // NEW_USER_H
