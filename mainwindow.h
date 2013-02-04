#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHash>
#include <QString>
#include <vector>
#include <QListWidgetItem>
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

private slots:
    void on_actionAvsluta_triggered();

    void on_lvRuns_itemSelectionChanged();

private:
    void addItemsToListWidget();
    void plotValues(std::vector<SensorValue>);

    QHash<QString, std::vector<SensorValue>> currentFile;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
