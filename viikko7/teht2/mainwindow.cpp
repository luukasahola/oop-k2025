#include "mainwindow.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* Yhteydet numeronäppäimille */
    connect(ui->N,&QPushButton::clicked,this,&MainWindow::numberClickHandler);
    connect(ui->N1,&QPushButton::clicked,this,&MainWindow::numberClickHandler);
    connect(ui->N2,&QPushButton::clicked,this,&MainWindow::numberClickHandler);
    connect(ui->N3,&QPushButton::clicked,this,&MainWindow::numberClickHandler);
    connect(ui->N4,&QPushButton::clicked,this,&MainWindow::numberClickHandler);
    connect(ui->N5,&QPushButton::clicked,this,&MainWindow::numberClickHandler);
    connect(ui->N6,&QPushButton::clicked,this,&MainWindow::numberClickHandler);
    connect(ui->N7,&QPushButton::clicked,this,&MainWindow::numberClickHandler);
    connect(ui->N8,&QPushButton::clicked,this,&MainWindow::numberClickHandler);
    connect(ui->N9,&QPushButton::clicked,this,&MainWindow::numberClickHandler);

    /* Yhteydet laskutoimituksille */
    connect(ui->add,&QPushButton::clicked,this,&MainWindow::calculatorHandler);
    connect(ui->mul,&QPushButton::clicked,this,&MainWindow::calculatorHandler);
    connect(ui->div,&QPushButton::clicked,this,&MainWindow::calculatorHandler);
    connect(ui->sub,&QPushButton::clicked,this,&MainWindow::calculatorHandler);

    connect(ui->Clear,&QPushButton::clicked,this,&MainWindow::clearHandler);
    connect(ui->showResult,&QPushButton::clicked,this,&MainWindow::enterHandler);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton *>(sender());
    QString numberName = button->objectName();
    qDebug()<<numberName.at(1);


    if(state == 0)
    {
        QString val1 = ui->value1->text();
        val1 = val1 + numberName.at(1);
        ui->value1->setText(val1);
        input1 = val1.toFloat();
    }
    else
    {
        QString val2 = ui->value2->text();
        val2 = val2 + numberName.at(1);
        ui->value2->setText(val2);
        input2 = val2.toFloat();
    }
}

void MainWindow::calculatorHandler()
{
    state = 1;
    QPushButton * opbutton = qobject_cast<QPushButton *>(sender());
    QString operation = opbutton->objectName();
    qDebug()<<opbutton->objectName();


    /* Parempia tapoja olisi */
    if(operation == "add")
    {
        ui->operationWindow->setText("+");
        operand = 1;
    }
    else if(operation == "sub")
    {
        ui->operationWindow->setText("-");
        operand = 2;
    }
    else if(operation == "mul")
    {
        ui->operationWindow->setText("*");
        operand = 3;
    }
    else if(operation == "div")
    {
        ui->operationWindow->setText("/");
        operand = 4;
    }

}

void MainWindow::clearHandler()
{
    ui->operationWindow->clear();
    ui->value1->clear();
    ui->value2->clear();
    ui->resultWindow->clear();
    state = 0;
}

void MainWindow::enterHandler()
{
    switch(operand)
    {
    case 1:
        calcresult = input1+input2;
        break;
    case 2:
        calcresult = input1-input2;
        break;
    case 3:
        calcresult = input1*input2;
        break;
    case 4:
        calcresult = input1/input2;
        break;
    default:
        break;
    }
    QString result = QString::number(calcresult);
    ui->resultWindow->setText(result);
}

