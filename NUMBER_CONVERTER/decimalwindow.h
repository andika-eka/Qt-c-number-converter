#ifndef DECIMALWINDOW_H
#define DECIMALWINDOW_H

#include <QDialog>



namespace Ui {
    class DecimalWindow;
}

class DecimalWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DecimalWindow(QWidget *parent = 0);
    ~DecimalWindow();

private:
    Ui::DecimalWindow *ui;

private slots:
    void on_convertButton_clicked();
};




#endif // DECIMALWINDOW_H
