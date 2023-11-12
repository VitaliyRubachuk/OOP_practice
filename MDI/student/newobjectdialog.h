#ifndef NEWOBJECTDIALOG_H
#define NEWOBJECTDIALOG_H
#include <QLabel>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>

class NewObjectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewObjectDialog(QWidget *parent = nullptr);
    ~NewObjectDialog();

signals:
    void createObjectRequested(int id, const QString &lname, const QString &fname, const QString &mname, const QString &birth, const QString &phone, const QString &faculty, int course, const QString &group);
private slots:
    void createObject();

private:
    QLineEdit *idLineEdit;
    QLineEdit *lnameLineEdit;
    QLineEdit *fnameLineEdit;
    QLineEdit *mnameLineEdit;
    QLineEdit *birthLineEdit;
    QLineEdit *phoneLineEdit;
    QLineEdit *facultyLineEdit;
    QLineEdit *courseLineEdit;
    QLineEdit *groupLineEdit;
    QPushButton *createButton;
    QLabel *createLabel(const QString &text);
};

#endif
