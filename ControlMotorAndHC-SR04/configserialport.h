#ifndef CONFIGSERIALPORT_H
#define CONFIGSERIALPORT_H

#include <QDialog>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

namespace Ui {
class ConfigSerialPort;
}

class ConfigSerialPort : public QDialog
{
    Q_OBJECT

public:
    explicit ConfigSerialPort(QWidget *parent = 0);
    QString getSerialPort();
    QString getBaudRate();
    QString getDataBits();
    QString getParity();
    QString getStopBits();
    QString getFlowControl();
    ~ConfigSerialPort();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ConfigSerialPort *ui;
    QString str_serialPort, str_baudRate, str_dataBits, str_stopBits, str_parity, str_flowControl;
};

#endif // CONFIGSERIALPORT_H
