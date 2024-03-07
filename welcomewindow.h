#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class WelcomeWindow;
}
QT_END_NAMESPACE

class WelcomeWindow : public QMainWindow
{
    Q_OBJECT

public:
    WelcomeWindow(QString, int, QWidget *parent = nullptr);
    ~WelcomeWindow();

private slots:
    void on_pushButton_logout_clicked();

private:
    Ui::WelcomeWindow *ui;
};
#endif // WELCOMEWINDOW_H
