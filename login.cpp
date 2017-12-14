#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    db.connect();
    if (!db.r_db().open())
        ui->dbstatus->setText("Виникли проблеми, перевірте з'єднання!");
    else ui->dbstatus->setText("Підключено до БД...");

}

login::~login()
{
    delete ui;
}
void login::on_show_pass_toggled(bool checked)
{
    if (! checked) ui -> lineEdit_password-> setEchoMode (QLineEdit::Password);
    else ui -> lineEdit_password -> setEchoMode (QLineEdit::Normal);
}

void login::on_login_Button_clicked()
{
    QString username = ui->lineEdit_username->text();
    //if(lineEdit_password )
    QString hashStr = QString("%1").arg(QString(QCryptographicHash::hash(ui->lineEdit_password->text().toUtf8(),QCryptographicHash::Sha256).toHex()));
    qDebug() << hashStr;
    if(db.log_in(username,hashStr)) {
            QMessageBox::information(this, "Вхід", "Логін та пароль правильні!");
            hide();
            mainWindow = new MainWindow(this);
            mainWindow->show();
        }
    else {
        QMessageBox::warning(this,"Вхід", "Логін або пароль не правильні!");
    }
}

void login::on_Guest_Button_clicked()
{
    hide();
    d = new doctorlist();
    d->setFixedSize(d->size());
    d->show();
}
