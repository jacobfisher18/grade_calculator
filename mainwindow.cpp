#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

//global variables
int homeworks[8] = {};
int midterms[3] = {}; //for the purpose of this program, the final is called midterm 3

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

    //calculate overall homework score
    double hwOverall = 0;
    for (int i = 0; i < 8; i++) {
        hwOverall+=homeworks[i];
    }
    hwOverall /= 8;

    //calculate overall midterm score
    double midtermOverall = 0;
    for (int i = 0; i < 3; i++) {
        midtermOverall+=midterms[i];
    }
    midtermOverall /= 3;

    overall = (hwOverall + midtermOverall) / 2;

    ui->overalllabel->setText(QString::number(overall));
}

void hwboxChanged(int index, int& value, Ui::MainWindow* ui) {
    homeworks[index] = value;
    updateOverall(ui);
}

void midtermboxChanged(int index, int& value, Ui::MainWindow* ui) {
    midterms[index] = value;
    //update slider in the ui
    updateOverall(ui);
}

void sliderChanged(int index, int& value, Ui::MainWindow* ui) {
    midterms[index] = value;
    //update midterm box in the ui
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

void MainWindow::on_midterm1box_valueChanged(int arg1)
{
    midtermboxChanged(0, arg1, ui);
}

void MainWindow::on_midterm2box_valueChanged(int arg1)
{
    midtermboxChanged(1, arg1, ui);
}

void MainWindow::on_midterm3box_valueChanged(int arg1)
{
    midtermboxChanged(2, arg1, ui);
}

void MainWindow::on_hw1slider_sliderMoved(int position)
{
    sliderChanged(0, position, ui);
}

void MainWindow::on_hw2slider_sliderMoved(int position)
{
    sliderChanged(1, position, ui);
}

void MainWindow::on_hw3slider_sliderMoved(int position)
{
    sliderChanged(2, position, ui);
}

void MainWindow::on_hw4slider_sliderMoved(int position)
{
    sliderChanged(3, position, ui);
}

void MainWindow::on_hw5slider_sliderMoved(int position)
{
    sliderChanged(4, position, ui);
}

void MainWindow::on_hw6slider_sliderMoved(int position)
{
    sliderChanged(5, position, ui);
}

void MainWindow::on_hw7slider_sliderMoved(int position)
{
    sliderChanged(6, position, ui);
}

void MainWindow::on_hw8slider_sliderMoved(int position)
{
    sliderChanged(7, position, ui);
}

void MainWindow::on_midterm1slider_sliderMoved(int position)
{
    //midterm slider changed
}

void MainWindow::on_midterm2slider_sliderMoved(int position)
{
    //midterm slider changed
}

void MainWindow::on_midterm3slider_sliderMoved(int position)
{
    //midterm slider changed
}
