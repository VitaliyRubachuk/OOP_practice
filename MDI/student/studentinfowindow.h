#ifndef STUDENTINFOWINDOW_H
#define STUDENTINFOWINDOW_H

#include <QDialog>
#include <QLabel>
#include "student.h"

namespace Ui
{
class StudentInfoWindow;
}

class StudentInfoWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StudentInfoWindow(const Student *student, QWidget *parent = nullptr);
    ~StudentInfoWindow();

private:
    const Student *student;
    QLabel *studentInfoLabel;
};

#endif
