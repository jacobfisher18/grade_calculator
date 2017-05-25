#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <iostream>

using std::vector;

/*
 * Potential To-Do:
 * Add final project to pic10c
 * Clean up code, comment code
 * Make UI look and feel better
 * Respond to keyboard presses
 * Clean up ui widget names, variable names in general
*/

//global variables
vector<int> homeworks(8, 0);
vector<int> midterms(2, 0);
int final = 0; //final score
bool schema1 = true; //if false, use schema2
bool pic10b = true; //if false, use pic10c

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(550, 500);

    ui->comboBox->addItem("PIC 10B");
    ui->comboBox->addItem("PIC 10C");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void updateOverall(Ui::MainWindow* ui) {
    double overall = 0;
    int numHomeworks;

    if (pic10b)
        numHomeworks = 8;
    else
        numHomeworks = 3;

    //calculate overall homework score, dropping the lowest
    double hwOverall = 0;
    int lowest = 100;
    //int numHomeworks = static_cast<int>(homeworks.size());
    for (int i = 0; i < numHomeworks; i++) {
        if (homeworks[i] < lowest)
            lowest = homeworks[i];
        hwOverall+=homeworks[i];
    }
    hwOverall -= lowest; //drop lowest score
    hwOverall /= (numHomeworks-1);

    //score for pic10b
    if (pic10b) {
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
    }

    //score for pic10c
    else {
        if (schema1) {
            overall = (0.25 * hwOverall) + (0.3 * midterms[0]) + (0.45 * final);
        }

        else {
            //drop the midterm
            overall = (0.4 * hwOverall) + (0.6 * final);
        }
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

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if (index == 0) {
        pic10b = true;

        updateOverall(ui);

        ui->apptitle->setText("Grade Calculator for PIC 10B");

        ui->midterm2label->show();
        ui->midterm2slider->show();
        ui->midterm2box->show();

        ui->hw4label->show();
        ui->hw4slider->show();
        ui->hw4box->show();

        ui->hw5label->show();
        ui->hw5slider->show();
        ui->hw5box->show();

        ui->hw6label->show();
        ui->hw6slider->show();
        ui->hw6box->show();

        ui->hw7label->show();
        ui->hw7slider->show();
        ui->hw7box->show();

        ui->hw8label->show();
        ui->hw8slider->show();
        ui->hw8box->show();
    }

    else {
        pic10b = false;

        updateOverall(ui);

        ui->apptitle->setText("Grade Calculator for PIC 10C");

        ui->midterm2label->hide();
        ui->midterm2slider->hide();
        ui->midterm2box->hide();

        ui->hw4label->hide();
        ui->hw4slider->hide();
        ui->hw4box->hide();

        ui->hw5label->hide();
        ui->hw5slider->hide();
        ui->hw5box->hide();

        ui->hw6label->hide();
        ui->hw6slider->hide();
        ui->hw6box->hide();

        ui->hw7label->hide();
        ui->hw7slider->hide();
        ui->hw7box->hide();

        ui->hw8label->hide();
        ui->hw8slider->hide();
        ui->hw8box->hide();
    }
}
