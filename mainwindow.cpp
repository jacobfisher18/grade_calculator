#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

//global variables
int homeworks[8] = {}; //homework scores
int midterms[2] = {}; //midterm scores
int final = 0; //final score
bool schema1 = true; //if false, use schema2

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(600, 500);
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



    if (schema1) {
        overall = (0.25 * hwOverall) + (0.2 * midterms[0]) + (0.2 * midterms[1]) + (0.35 * final);
    }

    else {
        //figure out higher midterm
        int higherMidterm = 0;
        if (midterms[0] > midterms[1])
            higherMidterm = midterms[0];
        else
            higherMidterm = midterms[1];

        overall = (0.25 * hwOverall) + (0.3 * higherMidterm) + (0.44 * final);
    }

    ui->overalllabel->setText(QString::number(overall));
}

void hwboxChanged(int index, int& value, Ui::MainWindow* ui) {
    homeworks[index] = value;
    updateOverall(ui);
}

void midtermboxChanged(int index, int& value, Ui::MainWindow* ui) {
    midterms[index] = value;
    updateOverall(ui);
}

void hwsliderChanged(int index, int& value, Ui::MainWindow* ui) {
    homeworks[index] = value;
    updateOverall(ui);
}

void midtermsliderChanged(int index, int& value, Ui::MainWindow* ui) {
    midterms[index] = value;
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

void MainWindow::on_finalslider_sliderMoved(int position)
{
    final = position;
    ui->finalbox->setValue(position);
    updateOverall(ui);
}

void MainWindow::on_finalbox_valueChanged(int arg1)
{
    final = arg1;
    ui->finalslider->setValue(arg1);
    updateOverall(ui);
}

void MainWindow::on_schema1radio_clicked()
{
    schema1 = true;
    updateOverall(ui);
}

void MainWindow::on_schema2radio_clicked()
{
    schema1 = false;
    updateOverall(ui);
}
