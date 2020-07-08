#include "binarywindow.h"
#include "ui_binarywindow.h"
#include <math.h>
#include <QDebug>
#include <used_function2.h>


using namespace std;

int Input_1, decimal_a, aa=1;//up to 77,777
int modulus_1;
int qqq = 0, ascii_2;
char hexadecimal_2[4];//up to 65,536
int octal_1[8],hhh=0; // up to 16,777,216

BinaryWindow::BinaryWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BinaryWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("");
    ui->comboBox->addItem("octal");
    ui->comboBox->addItem("decimal");
    ui->comboBox->addItem("hexadecimal");

}

BinaryWindow::~BinaryWindow()
{
    delete ui;
}

void BinaryWindow::on_convert_Button_clicked()
{
    qDebug() << "convert button is clicked";
    if (ui->comboBox->currentText()=="decimal"){
        qDebug("decimal is selected");
        int temp=0,mod=0;
        Input_1 =ui->input_line->text().toInt();
        temp= Input_1;
        decimal_a=0;
        aa=1;
        bool bin;

        if ((Input_1 % 10 == 0)||(Input_1 % 10==1)){
            decimal_a =to_decimal2 (temp, mod, aa, 2);
            qDebug() << decimal_a;
            mod=0,temp= Input_1, aa=1;
            bin =check (temp, mod, aa, 2);
            qDebug() << bin;

            if (bin == true){
                ui->input_line->setText("0"+QString::number(Input_1));
                ui->output_lable->setText(QString::number(decimal_a/2));
            }
            else{
                qDebug() <<"invalid input";
                ui->output_lable->setText("bukan bilangan binary");
            }
        }
        else{
            qDebug() <<"invalid input";
            ui->output_lable->setText("bukan bilangan binary");
        }

    }
    else if (ui->comboBox->currentText()=="octal"){
        qDebug() << "octal is selected";
        int temp=0,mod=0;
        Input_1 =ui->input_line->text().toInt();
        temp= Input_1;
        decimal_a=0;
        aa=1;hhh=0;
        bool bin;

        if ((Input_1 % 10 == 0)||(Input_1 % 10==1)){
            decimal_a =to_decimal2 (temp, mod, aa, 2);
            qDebug() << decimal_a;
            mod=0,temp= Input_1, aa=1;
            bin =check (temp, mod, aa, 2);
            qDebug() << bin;

            if (bin == true){
                ui->input_line->setText("0"+QString::number(Input_1));
                temp = decimal_a/2;
                from_decimal2(temp, octal_1, 8, hhh);
                ui->input_line->setText("0"+QString::number(Input_1));//no negative
                ui->output_lable->setText(QString::number(octal_1[7])+QString::number(octal_1[6])+QString::number(octal_1[5])+QString::number(octal_1[4])+QString::number(octal_1[3])+QString::number(octal_1[2])+QString::number(octal_1[1])+QString::number(octal_1[0]));

            }
            else{
                qDebug() <<"invalid input";
                ui->output_lable->setText("bukan bilangan binary");
            }
        }
        else{
            qDebug() <<"invalid input";
            ui->output_lable->setText("bukan bilangan binary");
        }

    }

    else if (ui->comboBox->currentText()=="hexadecimal"){
        qDebug() << "hexadecimal is selected";
        int temp=0,mod=0;
        Input_1 =ui->input_line->text().toInt();
        temp= Input_1;
        decimal_a=0;
        aa=1;qqq = 0;
        bool bin;

        if ((Input_1 % 10 == 0)||(Input_1 % 10==1)){
            decimal_a =to_decimal2 (temp, mod, aa, 2);
            qDebug() << decimal_a;
            mod=0,temp= Input_1, aa=1;
            bin =check (temp, mod, aa, 2);
            qDebug() << bin;

            if (bin == true){
                ui->input_line->setText("0"+QString::number(Input_1));
                temp = decimal_a/2;
                reset2_hexa (hexadecimal_2,32, 4 );
                from_decimal2_hexa(hexadecimal_2, temp, ascii_2, qqq);
                ui->input_line->setText("0"+QString::number(Input_1));//no negative
                ui->output_lable->setText(QString(QChar::fromLatin1(hexadecimal_2[3]))+QString(QChar::fromLatin1(hexadecimal_2[2]))+QString(QChar::fromLatin1(hexadecimal_2[1]))+QString(QChar::fromAscii(hexadecimal_2[0])));
}
            else{
                qDebug() <<"invalid input";
                ui->output_lable->setText("bukan bilangan binary");
            }
        }
        else{
            qDebug() <<"invalid input";
            ui->output_lable->setText("bukan bilangan binary");
        }
    }

    else{
        qDebug()<< "none is selected";
        ui->output_lable->setText("tujuan konversi harus terisi!");
    }
}
