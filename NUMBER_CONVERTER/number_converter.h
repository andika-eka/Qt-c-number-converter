#ifndef NUMBER_CONVERTER_H
#define NUMBER_CONVERTER_H

#include <QMainWindow>

namespace Ui {
    class NUMBER_CONVERTER;
}

class NUMBER_CONVERTER : public QMainWindow
{
    Q_OBJECT

public:
    explicit NUMBER_CONVERTER(QWidget *parent = 0);
    ~NUMBER_CONVERTER();

private:
    Ui::NUMBER_CONVERTER *ui;

private slots:
    void on_octalButton_clicked();
    void on_hexadecimalButton_clicked();
    void on_binaryButton_clicked();
    void on_decimalButton_clicked();
    void on_creditButton_clicked();
    void on_exitButton_clicked();
};

#endif // NUMBER_CONVERTER_H
