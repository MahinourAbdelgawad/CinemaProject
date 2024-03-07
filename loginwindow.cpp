#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "Users.h"
#include "registerwindow.h"
#include "welcomewindow.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->error->setVisible(false); //setting visibility of error label to false

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
    for (int i = 0; i < 100; i++) //checking if entered username exists and the password is correct
        if (usernames[i] == user && passwords[i] == pass){
            found = 1;
            hide();
            WelcomeWindow* welcomeWindow = new WelcomeWindow(user, ages[i],this);
            welcomeWindow->show();
        }

    if (!found)
     ui->error->setVisible(true);


}


void LoginWindow::on_pushButton_register_clicked()
{
    hide();
    RegisterWindow* registerWindow = new RegisterWindow(this);
    registerWindow->show();
}

