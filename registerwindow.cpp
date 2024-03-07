#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "Users.h"

RegisterWindow::RegisterWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    ui->label_error1->setVisible(false); //set the visibility to all error messages to false.
    ui->label_error2->setVisible(false);
    ui->label_error3->setVisible(false);
    ui->label_error4->setVisible(false);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_pushButton_register_clicked()
{
    ui->label_error1->setVisible(false);
    ui->label_error2->setVisible(false);
    ui->label_error3->setVisible(false);
    ui->label_error4->setVisible(false);

    QString username, password, rePassword, month, day, year, gender, accType, favGenres[6];
    int genreCount = 0;
    bool errors = 1;
    username = ui->lineEdit_username->text();
    password = ui->lineEdit_pass->text();
    rePassword = ui->lineEdit_rePass->text();
    month = ui->comboBox_month->currentText();
    day = ui->lineEdit_day->text();
    year = ui->lineEdit_year->text();

    if (ui->radioButton_male->isChecked())
        gender = "Male";
    else
        gender = "Female";

    if (ui->radioButton_admin->isChecked())
        accType = "Admin";
    else
        accType = "User";

    if (ui->checkBox_action->isChecked())
    {
        favGenres[genreCount++] = "Action";

    }
    if (ui->checkBox_comedy->isChecked())
    {
        favGenres[genreCount++] = "Comedy";

    }
    if (ui->checkBox_romance->isChecked())
    {
        favGenres[genreCount++] = "Romance";

    }
    if (ui->checkBox_drama->isChecked())
    {
        favGenres[genreCount++] = "Drama";

    }
    if (ui->checkBox_horror->isChecked())
    {
        favGenres[genreCount++] = "Horror";

    }
    if (ui->checkBox_other->isChecked())
    {
        favGenres[genreCount++] = "Other";

    }


    for (int i = 0; i < 100; i++)
        if (username == usernames[i]){
            ui->label_error1->setVisible(true);
            errors = 0;
        }


    if (password != rePassword){
        ui->label_error2->setVisible(true);
        errors = 0;
        }

    if (2024-year.toInt() < 12 ){
        ui->label_error3->setVisible(true);
        errors = 0;
        }


        if (errors)
        {
            usernames[usersCount] = username;
            passwords[usersCount] = password;
            ages[usersCount] = 2024-year.toInt();
            usersCount++;
        }


     //Check if any of the input fields is not entered by the user.
     // show the “WelcomeWindow” with passing the current username and age to its constructor

}

