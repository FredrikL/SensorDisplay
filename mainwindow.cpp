#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::openFile() {
    qDebug() << "openFile()";
    auto fileName = QFileDialog::getOpenFileName(this, tr("Open log file"), "", tr("Log file (*.txt)"));
    qDebug() << fileName;
}
