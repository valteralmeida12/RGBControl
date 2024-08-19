#ifndef RGBCONTROL_H
#define RGBCONTROL_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class RGBControl;
}
QT_END_NAMESPACE

class RGBControl : public QMainWindow
{
    Q_OBJECT

public:
    RGBControl(QWidget *parent = nullptr);
    ~RGBControl();

private:
    Ui::RGBControl *ui;
    QSerialPort *serialPort;

    void refreshPortList();
    void sendColor(const QString &colorCode, QPushButton *button);

    void connectButton_clicked();

    void redButton_clicked();
    void orangeButton_clicked();
    void pinkButton_clicked();
    void purpleButton_clicked();

    void greenButton_clicked();
    void mintButton_clicked();
    void neongreenButton_clicked();
    void whiteButton_clicked();

    void blueButton_clicked();
    void cyanButton_clicked();
    void lightblueButton_clicked();
    void offButton_clicked();

};
#endif // RGBCONTROL_H


