#ifndef ADDDOCTOR_H
#define ADDDOCTOR_H

#include <QWidget>

namespace Ui {
class adddoctor;
}

class adddoctor : public QWidget
{
    Q_OBJECT

public:
    explicit adddoctor(QWidget *parent = 0);
    ~adddoctor();

private:
    Ui::adddoctor *ui;
};

#endif // ADDDOCTOR_H
