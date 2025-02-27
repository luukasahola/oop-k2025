#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDebug>

void MainWindow::timeout()
{

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pQTimer = new QTimer(this);
    /* edistyminen */
    connect(pQTimer, &QTimer::timeout,this, &MainWindow::updateProgressBar);

    /* napit */
    connect(ui->playTime5min,&QPushButton::clicked,this,&MainWindow::timeClickHandler);
    connect(ui->playTime120s,&QPushButton::clicked,this,&MainWindow::timeClickHandler);

    connect(ui->startGame,&QPushButton::clicked,this,&MainWindow::startClickHandler);
    connect(ui->stopGame,&QPushButton::clicked,this,&MainWindow::stopClickHandler);

    connect(ui->switchPlayer1,&QPushButton::clicked,this,&MainWindow::switchClickHandler);
    connect(ui->switchPlayer2,&QPushButton::clicked,this,&MainWindow::switchClickHandler);

    ui->player1Progress->setValue(0);
    ui->player2Progress->setValue(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timeClickHandler()
{
    QPushButton * swbutton = qobject_cast<QPushButton *>(sender());
    if(swbutton->objectName() == "playTime120s")
    {
        qDebug() << "120 valittu";
        gameTime = 1200;
    }
    else
    {
        qDebug() << "300 valittu";
        gameTime = 3000;
    }
    ui->player1Progress->setRange(0,gameTime);
    ui->player1Progress->setValue(gameTime);
    ui->player2Progress->setRange(0,gameTime);
    ui->player2Progress->setValue(gameTime);
    player1Time = gameTime;
    player2Time = gameTime;
    showGameInfoText("Ready to start", 1);
}

void MainWindow::startClickHandler()
{
        pQTimer->start(100);
        qDebug() << "start toimii";
}

void MainWindow::stopClickHandler()
{
    pQTimer->stop();

}

void MainWindow::switchClickHandler()
{
    QPushButton * swbutton = qobject_cast<QPushButton *>(sender());
    QString swPlayer = swbutton->objectName();

    if(swPlayer == "switchPlayer1")
    {
        currentPlayer = 0;
    }
    else
    {
        currentPlayer = 1;
    }
}

void MainWindow::showGameInfoText(QString s, short a)
{
    if(a == 1)
    {
    ui->statusLabel->setText(s);
    }
    else
    {
    ui->statusLabel->setText(s);
    ui->statusLabel->setStyleSheet("QLabel { color: white; background-color: blue; font-size: 16px; padding: 5px; }");
    }
}

void MainWindow::updateProgressBar()
{
    if(currentPlayer == 0 && player1Time != 0)
    {
        player1Time--;
        ui->player1Progress->setValue(player1Time);
        showGameInfoText("Player 1 is playing", 1);
    }
    else if(currentPlayer == 1 && player2Time != 0)
    {
        player2Time--;
        ui->player2Progress->setValue(player2Time);
        showGameInfoText("Player 2 is playing", 1);
    }
    else if(currentPlayer == 0)
    {
        showGameInfoText("Player 2 won!", 0);
    }
    else
    {
        showGameInfoText("Player 1 won!", 0);
    }

    qDebug() << "Update toimii";
}

