#include "studentinfowindow.h"
#include <QVBoxLayout>
#include <QLabel>

StudentInfoWindow::StudentInfoWindow(const Student *student, QWidget *parent)
    : QDialog(parent),
    student(student)
{
    setWindowTitle("Інформація про студента");

    studentInfoLabel = new QLabel(student->toString());

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(studentInfoLabel);

    setLayout(layout);
}

StudentInfoWindow::~StudentInfoWindow()
{
}
