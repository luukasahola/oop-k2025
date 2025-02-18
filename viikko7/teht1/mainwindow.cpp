#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->iterateOne,&QPushButton::clicked,
        this,&MainWindow::handleIter);
    connect(ui->resetButton,&QPushButton::clicked,
            this,&MainWindow::reset);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleIter()
{
    counter++;
    QString teksti = QString::number(counter);
    ui->showValue->setText(teksti);
}

void MainWindow::reset()
{
    counter = 0;
    QString teksti = QString::number(counter);
    ui->showValue->setText(teksti);
}



