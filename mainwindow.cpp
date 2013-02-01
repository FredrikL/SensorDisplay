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

    for(int k = 0; k < (listItems.size()/2); k++) listItems.swap(k,listItems.size()-(1+k));

    ui->lvRuns->insertItems(0, listItems);
}

void MainWindow::on_lvRuns_itemClicked(QListWidgetItem *item)
{
    auto items = currentFile[item->text()];
    plotValues(items);
}

void MainWindow::plotValues(std::vector<SensorValue> values) {

    QVector<double> y, room, evaporator, s1,s2,s3,s4;

    for(SensorValue& v : values){
        room.append(v.getRoom());
        evaporator.append(v.getEvaporator());
        s1.append(v.getSensor1());
        s2.append(v.getSensor2());
        s3.append(v.getSensor3());
        s4.append(v.getSensor4());
    }

    for (int i=0; i<=room.size(); ++i)
    {
        y.append(i);
    }

    ui->graph->clearGraphs();
    ui->graph->legend->setVisible(true);

    ui->graph->addGraph();
    ui->graph->graph(0)->setData(y, room);
    ui->graph->graph(0)->setName("Rum");

    ui->graph->addGraph();
    ui->graph->graph(1)->setData(y, evaporator);
    ui->graph->graph(1)->setPen(QPen(Qt::red));
    ui->graph->graph(1)->setName("Förångare");

    ui->graph->addGraph();
    ui->graph->graph(2)->setData(y, s1);
    ui->graph->graph(2)->setPen(QPen(Qt::cyan));
    ui->graph->graph(2)->setName("Givare 1");

    ui->graph->addGraph();
    ui->graph->graph(3)->setData(y, s2);
    ui->graph->graph(3)->setPen(QPen(Qt::yellow));
    ui->graph->graph(3)->setName("Givare 2");

    ui->graph->addGraph();
    ui->graph->graph(4)->setData(y, s3);
    ui->graph->graph(4)->setPen(QPen(Qt::magenta));
    ui->graph->graph(4)->setName("Givare 3");

    ui->graph->addGraph();
    ui->graph->graph(5)->setData(y, s4);
    ui->graph->graph(5)->setPen(QPen(Qt::green));
    ui->graph->graph(5)->setName("Givare 4");

    ui->graph->xAxis->setLabel("Minuter igång");
    ui->graph->yAxis->setLabel("Temperatur");

    ui->graph->xAxis->setRange(0, room.size());
    ui->graph->yAxis->setRange(-25, 100);

    ui->graph->yAxis2->setVisible(true);
    ui->graph->yAxis2->setRange(-25, 100);

    ui->graph->replot();
}

void MainWindow::on_actionAvsluta_triggered()
{
    qApp->exit();
}
