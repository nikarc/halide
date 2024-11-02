#include "halide.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Halide w;
    w.show();
    return a.exec();
}
