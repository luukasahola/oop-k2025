#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void numberClickHandler();
    void calculatorHandler();
    void clearHandler();
    void enterHandler();

private:
    Ui::MainWindow *ui;
    int state = 0;
    short operand;
    float input1;
    float input2;
    float calcresult;


};
#endif // MAINWINDOW_H
