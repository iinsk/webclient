#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //setDefault();
    setStatus(true);
    socket_.connected();    // signal, not functionn
    socket_.readyRead();    // readyRead
    QObject::connect(&socket_, &QAbstractSocket::connected, this, &Widget::doConnected);
    QObject::connect(&socket_, &QAbstractSocket::disconnected, this, &Widget::doDisconnected);
    QObject::connect(&socket_, &QAbstractSocket::readyRead, this, &Widget::doReadyRead);

}
Widget::~Widget()
{
    delete ui;
}


void Widget::setStatus(bool able){
    // true == Default & Disconnect
    // false == Connect Pressed
    ui->pbConnect->setEnabled(able);
    ui->pbDisconnect->setDisabled(able);
    ui->pbClear->setDisabled(able);
    ui->pbSend->setDisabled(able);
}

void Widget::doConnected(){
    ui->pteMessage->insertPlainText("Connnected\r\n");
    setStatus(false);
}
void Widget::doDisconnected(){
    ui->pteMessage->insertPlainText("Disconnnected\r\n");
    setStatus(true);
}
void Widget::doReadyRead(){
    ui->pteMessage->insertPlainText(socket_.readAll());
}
void Widget::on_pbConnect_clicked()
{
    if(ui->le443->isChecked()) {
        socket_.connectToHostEncrypted(ui->leHost->text(), 443);
    } else if(ui->le80->isChecked()) {
        socket_.connectToHost(ui->leHost->text(), 80);
    }
}

void Widget::on_pbDisconnect_clicked()
{
    socket_.close();
}
void Widget::on_pbClear_clicked()
{

}
void Widget::on_pbSend_clicked()
{
    socket_.write(ui->pteSend->toPlainText().toUtf8());
}
void Widget::on_le80_stateChanged(int arg1){
    if(arg1) {
        ui->le443->setChecked(false);
    }
}

void Widget::on_le443_stateChanged(int arg1){
    if(arg1) {
        ui->le80->setChecked(false);
    }
}


