#ifndef PATIENTLIST_H
#define PATIENTLIST_H

#include <QWidget>

namespace Ui {
class patientlist;
}

class patientlist : public QWidget
{
    Q_OBJECT

public:
    explicit patientlist(QWidget *parent = 0);
    ~patientlist();

private:
    Ui::patientlist *ui;
};

#endif // PATIENTLIST_H
