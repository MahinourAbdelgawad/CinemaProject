#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "Users.h"
#include "registerwindow.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->error->setVisible(false);

}

LoginWindow::~LoginWindow()
{
    delete ui;
}




void LoginWindow::on_loginbutton_clicked()
{
    QString user= ui->userin->text();
    QString pass= ui->passin->text();

    bool found = 0;
    for (int i = 0; i < 100; i++)
        if (usernames[i] == user && passwords[i] == pass)
            found = 1;

    if (!found)
     ui->error->setVisible(true);


}


void LoginWindow::on_pushButton_register_clicked()
{
    hide();
    RegisterWindow* registerWindow = new RegisterWindow(this);
    registerWindow->show();
}

