#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "Users.h"
#include "welcomewindow.h"

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
    bool errors = 1, empty = 1;
    username = ui->lineEdit_username->text(); //storing entered data
    password = ui->lineEdit_pass->text();
    rePassword = ui->lineEdit_rePass->text();
    month = ui->comboBox_month->currentText();
    day = ui->lineEdit_day->text();
    year = ui->lineEdit_year->text();

    int age =  2024-year.toInt(); //calculating age


    if (ui->radioButton_male->isChecked()) //storing data in boxes
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



    for (int i = 0; i < usersCount; i++) //making sure username doesnt exist
        if (username == usernames[i]){
            ui->label_error1->setVisible(true);
            errors = 0;
        }


    if (password != rePassword){ //making sure password and re-entered pass are the same
        ui->label_error2->setVisible(true);
        errors = 0;
        }

    if (2024-year.toInt() < 12 ){ //making sure age is above 12
        ui->label_error3->setVisible(true);
        errors = 0;
        }



        if (ui->lineEdit_username->text() == ""){ //making sure no fields are empty
            empty = 0;
            ui->label_error4->setVisible(true);
        }
        if (ui->lineEdit_pass->text() == ""){
            empty = 0;
            ui->label_error4->setVisible(true);
        }
        if (ui->lineEdit_rePass->text() == ""){
            empty = 0;
            ui->label_error4->setVisible(true);
        }
        if (ui->comboBox_month->currentText() == ""){
            empty = 0;
            ui->label_error4->setVisible(true);
        }
        if (ui->lineEdit_year->text() == ""){
            empty = 0;
            ui->label_error4->setVisible(true);
        }
        if (ui->lineEdit_day->text() == ""){
            empty = 0;
            ui->label_error4->setVisible(true);
        }
        if (!ui->radioButton_female->isChecked() && !ui->radioButton_male->isChecked()){
            empty = 0;
            ui->label_error4->setVisible(true);
        }
        if (!ui->radioButton_user->isChecked() && !ui->radioButton_admin->isChecked()){
            empty = 0;
            ui->label_error4->setVisible(true);
        }
        if (!ui->checkBox_action->isChecked() && !ui->checkBox_comedy->isChecked()
            && !ui->checkBox_drama->isChecked() && !ui->checkBox_horror->isChecked()
            && !ui->checkBox_romance->isChecked() && !ui->checkBox_other->isChecked()){
            empty = 0;
            ui->label_error4->setVisible(true);
        }



        if (errors && empty) //if no errors and no fields empty
        {
            usernames[usersCount] = username;
            passwords[usersCount] = password;
            ages[usersCount] = age;
            usersCount++;

            hide();
            WelcomeWindow* welcomeWindow = new WelcomeWindow(username, age, this);
            welcomeWindow->show();
        }
}

