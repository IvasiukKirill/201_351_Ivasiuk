#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <character.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    bool check_pin(QString);

private:
    Ui::MainWindow *ui;
    Character *sWindow;

};
#endif // MAINWINDOW_H
