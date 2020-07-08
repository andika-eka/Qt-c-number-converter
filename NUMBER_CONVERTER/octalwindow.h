#ifndef OCTALWINDOW_H
#define OCTALWINDOW_H

#include <QDialog>

namespace Ui {
    class OctalWindow;
}

class OctalWindow : public QDialog
{
    Q_OBJECT

public:
    explicit OctalWindow(QWidget *parent = 0);
    ~OctalWindow();

private:
    Ui::OctalWindow *ui;

private slots:
    void on_convertButton_clicked();
};

#endif // OCTALWINDOW_H
