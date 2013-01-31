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
    currentFile = result;

    addItemsToListWidget();
}

void MainWindow::addItemsToListWidget() {
    QStringList listItems(currentFile.keys());
    listItems.sort();
    ui->lvRuns->insertItems(0, listItems);
}

void MainWindow::on_lvRuns_itemClicked(QListWidgetItem *item)
{
    qDebug() << item->text();
    auto items = currentFile[item->text()];
    qDebug() << items[0].getDate();
    plotValues(items);
}

void MainWindow::plotValues(std::vector<SensorValue> values) {

    QVector<double> x, y;
    for (int i=-10; i<110; ++i)
    {
        y.append(i);
    }

    for(SensorValue& v : values){
        x.append(v.getRoom());
    }


    ui->graph->addGraph();
    ui->graph->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->graph->xAxis->setLabel("");
    ui->graph->yAxis->setLabel("temp");
    // set axes ranges, so we see all data:
    ui->graph->xAxis->setRange(0, 100);
    ui->graph->yAxis->setRange(-10, 100);
    ui->graph->replot();
}
