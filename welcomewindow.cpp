#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include "loginwindow.h"

WelcomeWindow::WelcomeWindow(QString username, int age, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);
    ui->label_hello->setText("Hello" + username + " " + QString::number(age));
    QPixmap pix ("welcome.jpg");
    int w = ui->label_welcome->width();
    int h = ui->label_welcome->height();
    ui->label_welcome->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));

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

