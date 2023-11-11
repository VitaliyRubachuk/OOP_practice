#ifndef STUDENTLISTWINDOW_H
#define STUDENTLISTWINDOW_H

#include <QDialog>
#include <QListWidget>
#include <QVBoxLayout>
#include "student.h"
class StudentListWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StudentListWindow(QWidget *parent = nullptr);
    ~StudentListWindow();

    void setStudentsList(const QVector<Student*>& students);

private:
    QListWidget *studentListWidget;
};

#endif
