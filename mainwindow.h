#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHash>
#include <QString>
#include <vector>
#include "sensorvalue.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
public slots:
    void openFile();

private:
    void addItemsToListWidget(QHash<QString, std::vector<SensorValue>> items);

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
