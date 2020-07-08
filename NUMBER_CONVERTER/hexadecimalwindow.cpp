#include "hexadecimalwindow.h"
#include "ui_hexadecimalwindow.h"
#include <math.h>
#include <QDebug>
#include <string.h>
#include <used_function16.h>
using namespace std;

char hexa[20];
int  j;
int  decimal_aa, aaa=1;
QString Input_2;
int octal_3[8],H=0;
int binary_2[16];
HexadecimalWindow::HexadecimalWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HexadecimalWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("");
    ui->comboBox->addItem("decimal");
    ui->comboBox->addItem("octal");
    ui->comboBox->addItem("binary");
}

HexadecimalWindow::~HexadecimalWindow()
{
    delete ui;
}


void HexadecimalWindow::on_convert_Button_clicked()
{
    qDebug() << "convert button is clicked";
    if (ui->comboBox->currentText()=="decimal"){
        qDebug() << "decimal is selected";

        Input_2= ui->line_input->text();
        qDebug() << Input_2;
        qDebug() << "__________";
        QChar StrToAr[6];
        char temp[6];
        decimal_aa =0;



      for (int ArNum = 0; ArNum < 6; ArNum++) {
                StrToAr[ArNum] = Input_2[ArNum];
                qDebug() << StrToAr[ArNum];
            }

        int len=Input_2.length();
        for(int i=0;i<6;i++){
            temp[i]=StrToAr[i].toLatin1();
            qDebug() <<temp[i];
        }
        if (len>6){
            ui->label_output->setText("batas terlampaui");
        }
        else{
           decimal_aa =to_decimal16(temp, len, j);
           qDebug() << decimal_aa;
           ui->label_output->setText(QString::number(decimal_aa));
        }


    }
    else if (ui->comboBox->currentText()=="octal"){
        qDebug() << "octal is selected";

        Input_2= ui->line_input->text();
        qDebug() << Input_2;
        qDebug() << "__________";
        QChar StrToAr[6];
        char temp[6];
        decimal_aa =0;
        int temporary,H=0;

        for (int ArNum = 0; ArNum < 6; ArNum++) {
                StrToAr[ArNum] = Input_2[ArNum];
                qDebug() << StrToAr[ArNum];
            }
        qDebug() <<"________________";

        int len=Input_2.length();
        for(int i=0;i<6;i++){
            temp[i]=StrToAr[i].toLatin1();
            qDebug() <<temp[i];
        }
        if (len>6){
            ui->label_output->setText("batas terlampaui");
        }
        else{
           decimal_aa =to_decimal16(temp, len, j);
           qDebug() << decimal_aa;
           temporary=decimal_aa;
           from_decimal16(temporary, octal_3, 8, H);
           ui->label_output->setText(QString::number(octal_3[7])+QString::number(octal_3[6])+QString::number(octal_3[5])+QString::number(octal_3[4])+QString::number(octal_3[3])+QString::number(octal_3[2])+QString::number(octal_3[1])+QString::number(octal_3[0]));
        }

    }
    else if (ui->comboBox->currentText()=="binary"){
        qDebug() << "binary is selected";

        Input_2= ui->line_input->text();
        qDebug() << Input_2;
        qDebug() << "__________";
        QChar StrToAr[6];
        char temp[6];
        decimal_aa =0;
        int temporary,H=0;

        for (int ArNum = 0; ArNum < 6; ArNum++) {
                StrToAr[ArNum] = Input_2[ArNum];
                qDebug() << StrToAr[ArNum];
            }
        qDebug() <<"________________";

        int len=Input_2.length();
        for(int i=0;i<6;i++){
            temp[i]=StrToAr[i].toLatin1();
            qDebug() <<temp[i];
        }
        if (len>6){
            ui->label_output->setText("batas terlampaui");
        }
        else{
           decimal_aa =to_decimal16(temp, len, j);

            qDebug() << decimal_aa;
            temporary=decimal_aa;
            from_decimal16(temporary, binary_2, 2, H);
        ui->label_output->setText("0"+QString::number(binary_2[15])+QString::number(binary_2[14])+QString::number(binary_2[13])+QString::number(binary_2[12])+QString::number(binary_2[11])+QString::number(binary_2[10])+QString::number(binary_2[9])+QString::number(binary_2[8])+QString::number(binary_2[7])+QString::number(binary_2[6])+QString::number(binary_2[5])+QString::number(binary_2[4])+QString::number(binary_2[3])+QString::number(binary_2[2])+QString::number(binary_2[1])+QString::number(binary_2[0]));
         }
    }
    else{
        qDebug()<< "none is selected";
        ui->label_output->setText("tujuan konversi harus terisi!");
    }
}
