#ifndef HEXADECIMALWINDOW_H
#define HEXADECIMALWINDOW_H

#include <QDialog>

namespace Ui {
    class HexadecimalWindow;
}

class HexadecimalWindow : public QDialog
{
    Q_OBJECT

public:
    explicit HexadecimalWindow(QWidget *parent = 0);
    ~HexadecimalWindow();

private:
    Ui::HexadecimalWindow *ui;

private slots:
    void on_convert_Button_clicked();
};

#endif // HEXADECIMALWINDOW_H
