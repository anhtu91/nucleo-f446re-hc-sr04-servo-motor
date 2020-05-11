#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include "configserialport.h"
#include <QDebug>
#include "howtouse.h"
#include "about.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionConfig_Serial_Port_triggered();

    void on_btnStart_clicked();

    void on_btnStop_clicked();

    void on_actionHow_to_use_triggered();

    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;
    const QStringList baudRate = {"2400", "4800", "9600", "19200", "38400", "57600", "115200"};
    const QStringList dataBits = {"5", "6", "7", "8"};
    const QStringList parity = {"None (N)", "Odd (O)", "Even (E)", "Mark (M)", "Space (S)"};
    const QStringList stopBits = {"1", "1.5", "2"};
    const QStringList flowControl = {"None", "XON/XOFF", "RTS/CTS"};
    QString str_serialPort, str_baudRate, str_dataBits, str_stopBits, str_parity, str_flowControl;
};

#endif // MAINWINDOW_H
