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
    //update homework slider in the ui
    updateOverall(ui);
}

void midtermboxChanged(int index, int& value, Ui::MainWindow* ui) {
    midterms[index] = value;
    //update midterm slider in the ui
    updateOverall(ui);
}

void hwsliderChanged(int index, int& value, Ui::MainWindow* ui) {
    homeworks[index] = value;
    //update homework box in the ui
    updateOverall(ui);
}

void midtermsliderChanged(int index, int& value, Ui::MainWindow* ui) {
    midterms[index] = value;
    //update homework box in the ui
    updateOverall(ui);
}

void MainWindow::on_hw1box_valueChanged(int arg1)
{
    hwboxChanged(0, arg1, ui);
    ui->hw1slider->setValue(arg1);
}

void MainWindow::on_hw2box_valueChanged(int arg1)
{
    hwboxChanged(1, arg1, ui);
    ui->hw2slider->setValue(arg1);
}

void MainWindow::on_hw3box_valueChanged(int arg1)
{
    hwboxChanged(2, arg1, ui);
    ui->hw3slider->setValue(arg1);
}

void MainWindow::on_hw4box_valueChanged(int arg1)
{
    hwboxChanged(3, arg1, ui);
    ui->hw4slider->setValue(arg1);
}

void MainWindow::on_hw5box_valueChanged(int arg1)
{
    hwboxChanged(4, arg1, ui);
    ui->hw5slider->setValue(arg1);
}

void MainWindow::on_hw6box_valueChanged(int arg1)
{
    hwboxChanged(5, arg1, ui);
    ui->hw6slider->setValue(arg1);
}

void MainWindow::on_hw7box_valueChanged(int arg1)
{
    hwboxChanged(6, arg1, ui);
    ui->hw7slider->setValue(arg1);
}

void MainWindow::on_hw8box_valueChanged(int arg1)
{
    hwboxChanged(7, arg1, ui);
    ui->hw8slider->setValue(arg1);
}

void MainWindow::on_midterm1box_valueChanged(int arg1)
{
    midtermboxChanged(0, arg1, ui);
    ui->midterm1slider->setValue(arg1);
}

void MainWindow::on_midterm2box_valueChanged(int arg1)
{
    midtermboxChanged(1, arg1, ui);
    ui->midterm2slider->setValue(arg1);
}

void MainWindow::on_midterm3box_valueChanged(int arg1)
{
    midtermboxChanged(2, arg1, ui);
    ui->midterm3slider->setValue(arg1);
}

void MainWindow::on_hw1slider_sliderMoved(int position)
{
    hwsliderChanged(0, position, ui);
    ui->hw1box->setValue(position);
}

void MainWindow::on_hw2slider_sliderMoved(int position)
{
    hwsliderChanged(1, position, ui);
    ui->hw2box->setValue(position);
}

void MainWindow::on_hw3slider_sliderMoved(int position)
{
    hwsliderChanged(2, position, ui);
    ui->hw3box->setValue(position);
}

void MainWindow::on_hw4slider_sliderMoved(int position)
{
    hwsliderChanged(3, position, ui);
    ui->hw4box->setValue(position);
}

void MainWindow::on_hw5slider_sliderMoved(int position)
{
    hwsliderChanged(4, position, ui);
    ui->hw5box->setValue(position);
}

void MainWindow::on_hw6slider_sliderMoved(int position)
{
    hwsliderChanged(5, position, ui);
    ui->hw6box->setValue(position);
}

void MainWindow::on_hw7slider_sliderMoved(int position)
{
    hwsliderChanged(6, position, ui);
    ui->hw7box->setValue(position);
}

void MainWindow::on_hw8slider_sliderMoved(int position)
{
    hwsliderChanged(7, position, ui);
    ui->hw8box->setValue(position);
}

void MainWindow::on_midterm1slider_sliderMoved(int position)
{
    midtermsliderChanged(0, position, ui);
    ui->midterm1box->setValue(position);
}

void MainWindow::on_midterm2slider_sliderMoved(int position)
{
    midtermsliderChanged(1, position, ui);
    ui->midterm2box->setValue(position);
}

void MainWindow::on_midterm3slider_sliderMoved(int position)
{
    midtermsliderChanged(2, position, ui);
    ui->midterm3box->setValue(position);
}
