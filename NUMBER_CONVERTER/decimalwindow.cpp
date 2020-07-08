#include "decimalwindow.h"
#include "ui_decimalwindow.h"
#include "number_converter.h"
#include<QDebug>
#include <math.h>
#include <used_function.h>

using namespace std;

int input;
int octal[8],h=0; // up to 16,777,216
int binary[16], k=0;//up to 65,536
int q = 0, ascii;
char hexadecimal[4];//up to 65,536

DecimalWindow::DecimalWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DecimalWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("");
    ui->comboBox->addItem("Octal");
    ui->comboBox->addItem("Hexadecimal");
    ui->comboBox->addItem("Binary");

}
DecimalWindow::~DecimalWindow()
{
    delete ui;
}


void DecimalWindow::on_convertButton_clicked()
{
    qDebug() << "button cliked";
    if (ui->comboBox->currentText()=="Octal"){
        qDebug() << "Octal selected";
        int temp;
        input = ui->lineInput->text().toInt();
        temp= input,h=0;

        reset(octal,0,8);
        from_decimal(temp, octal, 8, h);

        ui->label_output->setText(QString::number(octal[7])+QString::number(octal[6])+QString::number(octal[5])+QString::number(octal[4])+QString::number(octal[3])+QString::number(octal[2])+QString::number(octal[1])+QString::number(octal[0]));
      }

    else if(ui->comboBox->currentText()=="Hexadecimal"){
        qDebug() << "Hexadecimal clicked";

        int temp;
        input = ui->lineInput->text().toInt();
        temp= input, q=0;

        reset_hexa(hexadecimal, 32 ,4);
        from_decimal_hexa(hexadecimal, temp, ascii, q);

        ui->label_output->setText(QString(QChar::fromLatin1(hexadecimal[3]))+QString(QChar::fromLatin1(hexadecimal[2]))+QString(QChar::fromLatin1(hexadecimal[1]))+QString(QChar::fromAscii(hexadecimal[0])));

    }

    else if(ui->comboBox->currentText()=="Binary"){
        qDebug() << "Binary";
        int temp;
        input = ui->lineInput->text().toInt();
        temp = input;
        k=0;

        reset(binary,0,16);
        from_decimal(temp, binary, 2, k);

        ui->label_output->setText("0"+QString::number(binary[15])+QString::number(binary[14])+QString::number(binary[13])+QString::number(binary[12])+QString::number(binary[11])+QString::number(binary[10])+QString::number(binary[9])+QString::number(binary[8])+QString::number(binary[7])+QString::number(binary[6])+QString::number(binary[5])+QString::number(binary[4])+QString::number(binary[3])+QString::number(binary[2])+QString::number(binary[1])+QString::number(binary[0]));
    }

    else{
        qDebug()<< "none is selected";
        ui->label_output->setText("tujuan konversi harus terisi!");
    }
}



