#include <QApplication>
#include "calculator.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Calculator calculator;
    calculator.setWindowTitle("Simple Calculator");
    calculator.show();
    return app.exec();
}
