#include <QtGui/QApplication>
#include "number_converter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NUMBER_CONVERTER w;
    w.show();

    return a.exec();
}
