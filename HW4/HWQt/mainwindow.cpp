#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_Task1_clicked()
{
    int a = ui->first->text().toInt();
    int b = ui->second->text().toInt();
    if(a + b >= 10 && a + b <= 20)
    {
       ui->label_6->setText("True");
    }
    else
    {
       ui->label_6->setText("False");
    }
}


void MainWindow::on_Task2_clicked()
{
    int a = ui->first_2->text().toInt();
    int b = ui->second_2->text().toInt();

    if (a == 10 && b == 10 || a + b == 10)
    {
        ui->label_7->setText("True");
    }
    else
    {
        ui->label_7->setText("False");
    }
}



void MainWindow::on_Task4_clicked()
{

    int a = ui->Simple->text().toInt();
    bool sn = true;
    for(int i = 2; i <= a / 2; i++)
    {
        if(a % i == 0)
        {
            ui->label_8->setText("Не простое число");
            sn = false;
            break;
        }
    }
    if(sn)
    {
        ui->label_8->setText("Простое число");
    }
}

void MainWindow::on_Task5_clicked()
{
    int a = ui->leapYear->text().toInt();
    if (a % 400 == 0)
    {
        ui->label_9->setText("Високосный год");
    }
    else if (a % 100 == 0)
    {
        ui->label_9->setText("Не високосный год");
    }
    else if (a % 4 == 0)
    {
        ui->label_9->setText("Високосный год");
    }
    else
    {
        ui->label_9->setText("Не високосный год");
    }
}
