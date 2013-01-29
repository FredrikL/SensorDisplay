#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <QListWidget>
#include "fileparser.h"
#include "sensorvalue.h"

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
    auto result = parser->parse();
    delete parser;

    addItemsToListWidget(result);
}

void MainWindow::addItemsToListWidget(QHash<QString, std::vector<SensorValue>> items) {
    QStringList listItems(items.keys());

    ui->lvRuns->insertItems(0, listItems);
}

