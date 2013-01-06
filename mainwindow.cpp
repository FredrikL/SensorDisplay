#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int x = 0;
    auto foo = 1;
}

MainWindow::~MainWindow()
{
    delete ui;
}
