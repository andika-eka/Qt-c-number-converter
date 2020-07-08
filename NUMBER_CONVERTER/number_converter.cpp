#include "number_converter.h"
#include "ui_number_converter.h"
#include <QMessageBox>
#include <QDebug>

#include <decimalwindow.h>
#include <binarywindow.h>
#include <hexadecimalwindow.h>
#include <octalwindow.h>


NUMBER_CONVERTER::NUMBER_CONVERTER(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NUMBER_CONVERTER)
{
    ui->setupUi(this);
}

NUMBER_CONVERTER::~NUMBER_CONVERTER()
{
    delete ui;
}

void NUMBER_CONVERTER::on_exitButton_clicked()
{
    QMessageBox ::StandardButton respon = QMessageBox :: question(this,"QUIT", "would you like to quit?",
                          QMessageBox::Yes |  QMessageBox::No );
    if (respon == QMessageBox ::Yes){
        QApplication::quit();
    }else
        qDebug() << "pass";
}

void NUMBER_CONVERTER::on_creditButton_clicked()
{
    QMessageBox ::about(this, "Credit", "Putu Andika Eka Putra \nKomang Dika Priyatna \n IL_KOM \n 2019");
}

void NUMBER_CONVERTER::on_decimalButton_clicked()
{
    DecimalWindow decWindow;
    decWindow.setModal(true);
    decWindow.exec();

}

void NUMBER_CONVERTER::on_binaryButton_clicked()
{
    BinaryWindow binWindow;
    binWindow.setModal(true);
    binWindow.exec();
}

void NUMBER_CONVERTER::on_hexadecimalButton_clicked()
{
    HexadecimalWindow hexWindow;
    hexWindow.setModal(true);
    hexWindow.exec();
}

void NUMBER_CONVERTER::on_octalButton_clicked()
{
    OctalWindow octWindow;
    octWindow.setModal(true);
    octWindow.exec();
}
