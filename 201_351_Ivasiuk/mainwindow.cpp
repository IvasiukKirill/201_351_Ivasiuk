#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


bool MainWindow::check_pin(QString pinCode)
{
    QString goodpass = "1234";
    return pinCode == goodpass;
}

void MainWindow::on_pushButton_clicked()
{
    QString pinCode = ui->pincode->text();


    if(check_pin(pinCode))
    {
        sWindow = new Character();
        sWindow->show();
        this->close();
    }
    else
    {
        QMessageBox::warning(this,"Авторизация","Неправильный пин-код");
    }
}
