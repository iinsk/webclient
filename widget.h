#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QSslSocket>
#include <QUdpSocket>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    //QTcpSocket socket_;
    QSslSocket socket_;
    //QUdpSocket socket_;
public slots:
    void doConnected();     // have to make body
    void doDisconnected();
    void doReadyRead();
private slots:
    void on_pbConnect_clicked();

    void on_pbClear_clicked();

    void on_pbSend_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H