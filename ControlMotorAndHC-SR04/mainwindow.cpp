#include "mainwindow.h"
#include "ui_mainwindow.h"

QSerialPort *serial;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial = new QSerialPort(this);
    //connect(serial, SIGNAL(readyRead()), this, SLOT(serialReceived()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionConfig_Serial_Port_triggered()
{
    ConfigSerialPort configSerial;
    configSerial.setModal(true);
    configSerial.exec();
    str_serialPort = configSerial.getSerialPort();
    str_baudRate = configSerial.getBaudRate();
    str_dataBits = configSerial.getDataBits();
    str_stopBits = configSerial.getStopBits();
    str_parity = configSerial.getParity();
    str_flowControl = configSerial.getFlowControl();
    QFont font("Arial",26, QFont::Bold);

    if(str_serialPort == ""){
        QMessageBox::critical(this, tr("Error"), tr("No serial port is connected"));
    }else{
        serial->setPortName(str_serialPort);

        if(str_baudRate == baudRate.at(0)){
            serial->setBaudRate(QSerialPort::Baud2400);
        }else if(str_baudRate == baudRate.at(1)){
            serial->setBaudRate(QSerialPort::Baud4800);
        }else if(str_baudRate == baudRate.at(2)){
            serial->setBaudRate(QSerialPort::Baud9600);
        }else if(str_baudRate == baudRate.at(3)){
            serial->setBaudRate(QSerialPort::Baud19200);
        }else if(str_baudRate == baudRate.at(4)){
            serial->setBaudRate(QSerialPort::Baud38400);
        }else if(str_baudRate == baudRate.at(5)){
            serial->setBaudRate(QSerialPort::Baud57600);
        }else if(str_baudRate == baudRate.at(6)){
            serial->setBaudRate(QSerialPort::Baud115200);
        }

        if(str_dataBits == dataBits.at(0)){
            serial->setDataBits(QSerialPort::Data5);
        }else if(str_dataBits == dataBits.at(1)){
            serial->setDataBits(QSerialPort::Data6);
        }else if(str_dataBits == dataBits.at(2)){
            serial->setDataBits(QSerialPort::Data7);
        }else if(str_dataBits == dataBits.at(3)){
            serial->setDataBits(QSerialPort::Data8);
        }

        if(str_parity == parity.at(0)){
            serial->setParity(QSerialPort::NoParity);
        }else if(str_parity == parity.at(1)){
            serial->setParity(QSerialPort::OddParity);
        }else if(str_parity == parity.at(2)){
            serial->setParity(QSerialPort::EvenParity);
        }else if(str_parity == parity.at(3)){
            serial->setParity(QSerialPort::MarkParity);
        }else if(str_parity == parity.at(4)){
            serial->setParity(QSerialPort::SpaceParity);
        }

        if(str_stopBits == stopBits.at(0)){
            serial->setStopBits(QSerialPort::OneStop);
        }else if(str_stopBits == stopBits.at(1)){
            serial->setStopBits(QSerialPort::OneAndHalfStop);
        }else if(str_stopBits == stopBits.at(2)){
            serial->setStopBits(QSerialPort::TwoStop);
        }

        if(str_flowControl == flowControl.at(0)){
             serial->setFlowControl(QSerialPort::NoFlowControl);
        }else if(str_flowControl == flowControl.at(1)){
             serial->setFlowControl(QSerialPort::SoftwareControl);
        }else if(str_flowControl == flowControl.at(2)){
             serial->setFlowControl(QSerialPort::HardwareControl);
        }

        serial->open(QIODevice::ReadWrite);
        QMessageBox::information(this, tr("Connected"), tr("Config serial port done!"));
        ui->lbStatus->setText("Connected");
        ui->lbStatus->setFont(font);
     }
}

void MainWindow::on_btnStart_clicked()
{
    QFont font("Arial",26, QFont::Bold);

    if(serial->isOpen() && serial->isWritable()){
        QByteArray sendData = "1";
        serial->write(sendData);
        ui->lbStatus->setText("RUNNING");
        ui->lbStatus->setFont(font);

    }else{
        QMessageBox::critical(this, tr("Error"), serial->errorString());
    }
}

void MainWindow::on_btnStop_clicked()
{
    QFont font("Arial",26, QFont::Bold);

    if(serial->isOpen() && serial->isWritable()){
        QByteArray sendData = "0";
        serial->write(sendData);
        ui->lbStatus->setText("STOP");
        ui->lbStatus->setFont(font);
    }else{
        QMessageBox::critical(this, tr("Error"), serial->errorString());
    }
}

void MainWindow::on_actionHow_to_use_triggered()
{
    howtouse howto;
    howto.setModal(true);
    howto.exec();
}

void MainWindow::on_actionAbout_triggered()
{
    about about;
    about.setModal(true);
    about.exec();
}
