// У файлі mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "student.h"
#include "newobjectdialog.h"

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
    void exit();
    void openNewObjectDialog();
    void handleCreateObject(int id, const QString &lname, const QString &fname, const QString &mname, const QString &birth, const QString &phone, const QString &faculty, int course, const QString &group);
private:
    Ui::MainWindow *ui;
    Student *student;
    NewObjectDialog *newObjectDialog;
};

#endif // MAINWINDOW_H
