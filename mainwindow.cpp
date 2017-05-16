#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

//global variables
int homeworks[8] = {};

void printHomeworks() {
    for (int i = 0; i < 8; i++) {
        std::cout << homeworks[i] << std::endl;
    }
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void updateOverall(Ui::MainWindow* ui) {
    double overall = 0;
    for (int i = 0; i < 8; i++) {
        overall+=homeworks[i];
    }

    overall /= 8;

    ui->overalllabel->setText(QString::number(overall));
}

void hwboxChanged(int index, int& value, Ui::MainWindow* ui) {
    homeworks[index] = value;
    updateOverall(ui);
}

void MainWindow::on_hw1box_valueChanged(int arg1)
{
    hwboxChanged(0, arg1, ui);
}

void MainWindow::on_hw2box_valueChanged(int arg1)
{
    hwboxChanged(1, arg1, ui);
}

void MainWindow::on_hw3box_valueChanged(int arg1)
{
    hwboxChanged(2, arg1, ui);
}

void MainWindow::on_hw4box_valueChanged(int arg1)
{
    hwboxChanged(3, arg1, ui);
}

void MainWindow::on_hw5box_valueChanged(int arg1)
{
    hwboxChanged(4, arg1, ui);
}

void MainWindow::on_hw6box_valueChanged(int arg1)
{
    hwboxChanged(5, arg1, ui);
}

void MainWindow::on_hw7box_valueChanged(int arg1)
{
    hwboxChanged(6, arg1, ui);
}

void MainWindow::on_hw8box_valueChanged(int arg1)
{
    hwboxChanged(7, arg1, ui);
}
