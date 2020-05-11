#include "configserialport.h"
#include "ui_configserialport.h"

ConfigSerialPort::ConfigSerialPort(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigSerialPort)
{
    ui->setupUi(this);
    QList<QSerialPortInfo> listPort;
    QStringList baudRate = {"2400", "4800", "9600", "19200", "38400", "57600", "115200"};
    QStringList dataBits = {"5", "6", "7", "8"};
    QStringList parity = {"None (N)", "Odd (O)", "Even (E)", "Mark (M)", "Space (S)"};
    QStringList stopBits = {"1", "1.5", "2"};
    QStringList flowControl = {"None", "XON/XOFF", "RTS/CTS"};

    listPort = QSerialPortInfo::availablePorts();

    if(!listPort.isEmpty())
    {
        for(int i=0;i<listPort.size(); i++){
            ui->cbSerialPort->addItem(listPort.at(i).portName());
        }
    }

    ui->cbBaudRate->addItems(baudRate);
    ui->cbBaudRate->setCurrentIndex(6);

    ui->cbDataBits->addItems(dataBits);
    ui->cbDataBits->setCurrentIndex(3);

    ui->cbParity->addItems(parity);
    ui->cbParity->setCurrentIndex(0);

    ui->cbStopBits->addItems(stopBits);
    ui->cbStopBits->setCurrentIndex(0);

    ui->cbFlowControl->addItems(flowControl);
    ui->cbFlowControl->setCurrentIndex(0);
}

ConfigSerialPort::~ConfigSerialPort()
{
    delete ui;
}

void ConfigSerialPort::on_buttonBox_accepted()
{
    str_serialPort = ui->cbSerialPort->currentText();
    str_baudRate = ui->cbBaudRate->currentText();
    str_dataBits = ui->cbDataBits->currentText();
    str_parity = ui->cbParity->currentText();
    str_stopBits = ui->cbStopBits->currentText();
    str_flowControl = ui->cbFlowControl->currentText();
}

QString ConfigSerialPort::getSerialPort(){
    return str_serialPort;
}
QString ConfigSerialPort::getBaudRate(){
    return str_baudRate;
}
QString ConfigSerialPort::getDataBits(){
    return str_dataBits;
}
QString ConfigSerialPort::getParity(){
    return str_parity;
}
QString ConfigSerialPort::getStopBits(){
    return str_stopBits;
}
QString ConfigSerialPort::getFlowControl(){
    return str_flowControl;
}

