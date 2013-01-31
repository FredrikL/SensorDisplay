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

    QVector<double> y, room, evaporator, s1,s2,s3,s4;
    for (int i=-25; i<100; ++i)
    {
        y.append(i);
    }

    for(SensorValue& v : values){
        room.append(v.getRoom());
        evaporator.append(v.getEvaporator());
        s1.append(v.getSensor1());
        s2.append(v.getSensor2());
        s3.append(v.getSensor3());
        s4.append(v.getSensor4());
    }

    ui->graph->clearGraphs();

    ui->graph->addGraph();
    ui->graph->graph(0)->setData(room, y);

    ui->graph->addGraph();
    ui->graph->graph(1)->setData(evaporator, y);

    ui->graph->addGraph();
    ui->graph->graph(2)->setData(s1, y);

    ui->graph->addGraph();
    ui->graph->graph(3)->setData(s2, y);

    ui->graph->addGraph();
    ui->graph->graph(4)->setData(s3, y);

    ui->graph->addGraph();
    ui->graph->graph(5)->setData(s4, y);

    ui->graph->xAxis->setLabel("");
    ui->graph->yAxis->setLabel("temp");

    ui->graph->xAxis->setRange(0, room.size());
    ui->graph->yAxis->setRange(-25, 100);
    ui->graph->replot();
}
