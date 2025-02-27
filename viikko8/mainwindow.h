#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void timeout();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void timeClickHandler();
    void startClickHandler();
    void stopClickHandler();
    void switchClickHandler();
    void showGameInfoText(QString,short);
    void updateProgressBar();

private:
    Ui::MainWindow *ui;
    short player1Time;
    short player2Time;
    short currentPlayer;
    short gameTime;
    QTimer * pQTimer;

};
#endif // MAINWINDOW_H
