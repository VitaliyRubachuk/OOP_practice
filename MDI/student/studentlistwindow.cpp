#include "studentlistwindow.h"

StudentListWindow::StudentListWindow(QWidget *parent)
    : QDialog(parent),
    studentListWidget(new QListWidget(this))
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(studentListWidget);
    setLayout(layout);

    setWindowTitle("Список студентів");
}

StudentListWindow::~StudentListWindow()
{
}


void StudentListWindow::setStudentsList(const QVector<Student*>& students)
{
    studentListWidget->clear();

    for (const Student* student : students)
    {
        QListWidgetItem* item = new QListWidgetItem(student->toString());
        studentListWidget->addItem(item);
    }
}

