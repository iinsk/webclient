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

    //void setDefault();
    void setStatus(bool able);
    QSslSocket socket_;
    //QTcpSocket socket_;

public slots:
    void doConnected();     // have to make body
    void doDisconnected();
    void doReadyRead();
private slots:
    void on_pbConnect_clicked();

    void on_pbClear_clicked();

    void on_pbSend_clicked();

    void on_pbDisconnect_clicked();

    //void on_lePortCheck_stateChanged(int arg1);

    void on_le80_stateChanged(int arg1);

    void on_le443_stateChanged(int arg1);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
