#include "octalwindow.h"
#include "ui_octalwindow.h"
#include <math.h>
#include <QDebug>
//#include <used_function.h>
#include <used_function8.h>
using namespace std;

int Input, decimal, a=0;//up to 77,777
int modulus;
int qq = 0, ascii_1;
char hexadecimal_1[4];//up to 65,536
int binary_1[16], kk=0;//up to 65,536



OctalWindow::OctalWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OctalWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("");
    ui->comboBox->addItem("decimal");
    ui->comboBox->addItem("hexadecimal");
    ui->comboBox->addItem("binary");
}

OctalWindow::~OctalWindow()
{
    delete ui;
}

void OctalWindow::on_convertButton_clicked()
{
    qDebug() << "convert button is clicked";
    if (ui->comboBox->currentText()=="decimal"){
        qDebug() << "decimal is selected";
        Input = ui->input_line->text().toInt();
        int temp, a=0, decimal=0,modulus=0;
        temp=Input;

        if ((800000<temp)||((80000<temp)&&(temp<100000))||((8000<temp)&&(temp<10000))||((800<temp)&&(temp<1000))||((80<temp)&&(temp<100))||((8<temp)&&(temp<10))){
            qDebug() <<"invalid input";
            ui->output_lable->setText("bukan bilangan octal");       
        }
        else{
            decimal =to_decimal8 (temp, modulus, a, 8);
            qDebug() << decimal;

            ui->output_lable->setText(QString::number(decimal));
        }


    }
    else if (ui->comboBox->currentText()=="hexadecimal"){
        qDebug() << "hexadecimal is selected";
        Input = ui->input_line->text().toInt();
        int temp, a=0, decimal=0,modulus=0;
        temp=Input;
        qq=0;

        if ((800000<temp)||((80000<temp)&&(temp<100000))||((8000<temp)&&(temp<10000))||((800<temp)&&(temp<1000))||((80<temp)&&(temp<100))||((8<temp)&&(temp<10))){
            qDebug() <<"invalid input";
            ui->output_lable->setText("bukan bilangan octal");

        }
        else{
            decimal =to_decimal8 (temp, modulus, a, 8);

            qDebug() << decimal;
            temp =decimal;

            reset8_hexa (hexadecimal_1, 32, 4);
            from_decimal8_hexa( hexadecimal_1, temp, ascii_1, qq);

          ui->output_lable->setText(QString(QChar::fromLatin1(hexadecimal_1[3]))+QString(QChar::fromLatin1(hexadecimal_1[2]))+QString(QChar::fromLatin1(hexadecimal_1[1]))+QString(QChar::fromAscii(hexadecimal_1[0])));

        }

    }
    else if (ui->comboBox->currentText()=="binary"){
        qDebug() << "binary is selected";
        Input = ui->input_line->text().toInt();
        int temp, a=0, decimal=0,modulus=0;
        temp=Input;

        if ((800000<temp)||((80000<temp)&&(temp<100000))||((8000<temp)&&(temp<10000))||((800<temp)&&(temp<1000))||((80<temp)&&(temp<100))||((8<temp)&&(temp<10))){
            qDebug() <<"invalid input";
            ui->output_lable->setText("bukan bilangan octal");

        }
        else{
            decimal =to_decimal8 (temp, modulus, a, 8);
            qDebug() << decimal;
            temp =decimal;
            kk=0;
            from_decimal8(temp, binary_1, 2, kk);

          }
        ui->output_lable->setText("0"+QString::number(binary_1[15])+QString::number(binary_1[14])+QString::number(binary_1[13])+QString::number(binary_1[12])+QString::number(binary_1[11])+QString::number(binary_1[10])+QString::number(binary_1[9])+QString::number(binary_1[8])+QString::number(binary_1[7])+QString::number(binary_1[6])+QString::number(binary_1[5])+QString::number(binary_1[4])+QString::number(binary_1[3])+QString::number(binary_1[2])+QString::number(binary_1[1])+QString::number(binary_1[0]));
        }

    else{
        qDebug()<< "none is selected";
        ui->output_lable->setText("tujuan konversi harus terisi!");
    }
}
