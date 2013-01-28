#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include "fileparser.h"

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
    auto fileName = QFileDialog::getOpenFileName(this, tr("Open log file"), "", tr("Log file (*.txt)"));

    auto parser= new FileParser(fileName);
    parser->parse();
    delete parser;
}
