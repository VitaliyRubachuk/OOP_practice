#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "student.h"

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void createObject();
    void displayObject();
    void exit();

private:
    Ui::MainWindow *ui;
    Student *student;
};

#endif // MAINWINDOW_H
