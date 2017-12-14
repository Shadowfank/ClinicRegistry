#ifndef DOCTORLIST_H
#define DOCTORLIST_H

#include <QWidget>

namespace Ui {
class doctorlist;
}

class doctorlist : public QWidget
{
    Q_OBJECT

public:
    explicit doctorlist(QWidget *parent = 0);
    ~doctorlist();

private:
    Ui::doctorlist *ui;
};

#endif // DOCTORLIST_H
