#include "rgbcontrol.h"
#include "./ui_rgbcontrol.h"
#include <QDebug>
#include <QApplication>
#include <QStyleFactory>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

RGBControl::RGBControl(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RGBControl)
    , serialPort(new QSerialPort(this))
{
    ui->setupUi(this);
    ui->ColorLabel->setWordWrap(true);

    // Set fixed size for the main window
    this->setFixedSize(368, 249);
    
    // Set design
    QApplication::setStyle(QStyleFactory::create("Fusion"));

    // Setup serial port
    serialPort->setBaudRate(QSerialPort::Baud9600);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    // List COM devices on drop down menu
    QList<QSerialPortInfo> portlist = QSerialPortInfo::availablePorts();

    for(int i = 0; i < portlist.size(); i++){
        const QSerialPortInfo &info = portlist[i];
        ui->comboBox->addItem(info.portName());

    }
    // Refresh Port list
    connect(ui->comboBox, &QComboBox::showPopup, this, &RGBControl::refreshPortList);
    // Connect the connectBT to open the selected port
    connect(ui->ConnectBT, &QPushButton::clicked, this, &RGBControl::connectButton_clicked);
    // Connect first button row
    connect(ui->Red, &QPushButton::clicked, this, &RGBControl::redButton_clicked);
    connect(ui->Orange, &QPushButton::clicked, this, &RGBControl::orangeButton_clicked);
    connect(ui->Pink, &QPushButton::clicked, this, &RGBControl::pinkButton_clicked);
    connect(ui->Purple, &QPushButton::clicked, this, &RGBControl::purpleButton_clicked);
    // Connect second button row
    connect(ui->Green, &QPushButton::clicked, this, &RGBControl::greenButton_clicked);
    connect(ui->Mint, &QPushButton::clicked, this, &RGBControl::mintButton_clicked);
    connect(ui->Neongreen, &QPushButton::clicked, this, &RGBControl::neongreenButton_clicked);
    connect(ui->White, &QPushButton::clicked, this, &RGBControl::whiteButton_clicked);
    // Connect third button row
    connect(ui->Blue, &QPushButton::clicked, this, &RGBControl::blueButton_clicked);
    connect(ui->Cian, &QPushButton::clicked, this, &RGBControl::cyanButton_clicked);
    connect(ui->Lighblue, &QPushButton::clicked, this, &RGBControl::lightblueButton_clicked);
    connect(ui->Off, &QPushButton::clicked, this, &RGBControl::offButton_clicked);
}

RGBControl::~RGBControl()
{
    if (serialPort->isOpen()){
        serialPort->close();
    }

    delete ui;
    delete serialPort;
}

void RGBControl::refreshPortList(){
    // Clear the existing items
    ui->comboBox->clear();

    // Get the list of available serial ports
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        // Add each port to the dropdown menu
        ui->comboBox->addItem(info.portName());
    }
}

void RGBControl::sendColor(const QString &colorCode, QPushButton *button){
    // check if serial port is open to send the color code
    if (serialPort->isOpen()){
        serialPort->write(colorCode.toUtf8());
    } else {
        ui->ColorLabel->clear();
        ui->ColorLabel->setText(QString("Serial Port is closed!"));
        qDebug() << "Serial Port is closed!" << serialPort->errorString();
    }

    QColor buttonColor = button->palette().color(QPalette::Button);
    QString colorName = buttonColor.name();
    QString styleSheet = QString("background-color: %1").arg(colorName);
    ui->ColorLabel->setStyleSheet(styleSheet);

}

void RGBControl::connectButton_clicked(){

    // Ensure the port is closed before opening
    serialPort->close();
    
    // Set the port name again just before opening
    serialPort->setPortName(ui->comboBox->currentText());
    if (serialPort->open(QIODevice::ReadWrite)) {
        ui->ColorLabel->clear();
        qDebug() << "Opened port:" << serialPort->portName();
    } else {
        ui->ColorLabel->clear();
        ui->ColorLabel->setText(QString("Failed to open port: %1").arg(serialPort->errorString()));
        qDebug() << "Failed to open port:" << serialPort->errorString();
    }
}

void RGBControl::redButton_clicked(){
    sendColor("a", ui->Red);
}

void RGBControl::greenButton_clicked(){
    sendColor("b", ui->Green);
}

void RGBControl::blueButton_clicked(){
    sendColor("c", ui->Blue);
}

void RGBControl::orangeButton_clicked(){
    sendColor("d", ui->Orange);
}

void RGBControl::mintButton_clicked(){
    sendColor("e", ui->Mint);
}

void RGBControl::cyanButton_clicked(){
    sendColor("f", ui->Cian);
}

void RGBControl::pinkButton_clicked(){
    sendColor("g", ui->Pink);
}

void RGBControl::neongreenButton_clicked(){
    sendColor("h", ui->Neongreen);
}

void RGBControl::lightblueButton_clicked(){
    sendColor("i", ui->Lighblue);
}

void RGBControl::purpleButton_clicked(){
    sendColor("j", ui->Purple);
}

void RGBControl::whiteButton_clicked(){
    sendColor("k", ui->White);
}

void RGBControl::offButton_clicked(){
    sendColor("l", ui->Off);
}
