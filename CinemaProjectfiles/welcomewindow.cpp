#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include "loginwindow.h"

WelcomeWindow::WelcomeWindow(QString username, int age, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);
    ui->label_hello->setText("Hello, " + username + ", " + QString::number(age));
    QPixmap pix ("C:\\Users\\mahin\\Desktop\\Uni\\Spring 2024\\CS 2 Lab\\Assignments\\Assignment 1\\CinemaProject - Copy\\CinemaProjectfiles\\welcome.jpg");
    int w = ui->label_image->width();
    int h = ui->label_image->height();
    ui->label_image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));

}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}

void WelcomeWindow::on_pushButton_logout_clicked()
{
    hide();
    LoginWindow* loginWindow = new LoginWindow(this);
    loginWindow->show();

}

