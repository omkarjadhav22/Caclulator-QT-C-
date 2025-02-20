#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QDoubleValidator>

class Calculator : public QWidget {
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = nullptr);

private slots:
    void add();
    void subtract();
    void multiply();
    void divide();
    void clear();

private:
    QLineEdit *num1;
    QLineEdit *num2;
    QLabel *resultLabel;
};

#endif // CALCULATOR_H
