#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_hw1box_valueChanged(int arg1);

    void on_hw2box_valueChanged(int arg1);

    void on_hw3box_valueChanged(int arg1);

    void on_hw4box_valueChanged(int arg1);

    void on_hw5box_valueChanged(int arg1);

    void on_hw6box_valueChanged(int arg1);

    void on_hw7box_valueChanged(int arg1);

    void on_hw8box_valueChanged(int arg1);

    void on_midterm1box_valueChanged(int arg1);

    void on_midterm2box_valueChanged(int arg1);

    void on_hw1slider_sliderMoved(int position);

    void on_hw2slider_sliderMoved(int position);

    void on_hw3slider_sliderMoved(int position);

    void on_hw4slider_sliderMoved(int position);

    void on_hw5slider_sliderMoved(int position);

    void on_hw6slider_sliderMoved(int position);

    void on_hw7slider_sliderMoved(int position);

    void on_hw8slider_sliderMoved(int position);

    void on_midterm1slider_sliderMoved(int position);

    void on_midterm2slider_sliderMoved(int position);

    void on_finalslider_sliderMoved(int position);

    void on_finalbox_valueChanged(int arg1);

    void on_schema1radio_clicked();

    void on_schema2radio_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
