#ifndef BINARYWINDOW_H
#define BINARYWINDOW_H

#include <QDialog>

namespace Ui {
    class BinaryWindow;
}

class BinaryWindow : public QDialog
{
    Q_OBJECT

public:
    explicit BinaryWindow(QWidget *parent = 0);
    ~BinaryWindow();

private:
    Ui::BinaryWindow *ui;

private slots:
    void on_convert_Button_clicked();
};

#endif // BINARYWINDOW_H
