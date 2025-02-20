#include "calculator.h"

Calculator::Calculator(QWidget *parent) : QWidget(parent) {
    // Input Fields
    num1 = new QLineEdit(this);
    num2 = new QLineEdit(this);
    resultLabel = new QLabel("Result: 0", this);

    // Apply number validation
    QDoubleValidator *validator = new QDoubleValidator(this);
    num1->setValidator(validator);
    num2->setValidator(validator);

    // Buttons
    QPushButton *addButton = new QPushButton("+", this);
    QPushButton *subButton = new QPushButton("-", this);
    QPushButton *mulButton = new QPushButton("×", this);
    QPushButton *divButton = new QPushButton("÷", this);
    QPushButton *clearButton = new QPushButton("C", this);

    // Set Styles (Modern Design)
    QString buttonStyle = "QPushButton {"
                          "background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #6a11cb, stop:1 #2575fc);"
                          "color: white;"
                          "font-size: 20px;"
                          "font-weight: bold;"
                          "border: none;"
                          "border-radius: 10px;"
                          "padding: 10px;"
                          "transition: all 0.3s ease;"
                          "}"
                          "QPushButton:hover {"
                          "background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #2575fc, stop:1 #6a11cb);"
                          "box-shadow: 0px 4px 10px rgba(0, 0, 0, 0.2);"
                          "}";

    QString inputStyle = "QLineEdit {"
                         "font-size: 20px;"
                         "padding: 10px;"
                         "border: 2px solid #6a11cb;"
                         "border-radius: 10px;"
                         "background-color: #FFFFFF;"
                         "color: #333;"
                         "text-align: center;"
                         "transition: all 0.2s ease;"
                         "}"
                         "QLineEdit:focus {"
                         "border-color: #2575fc;"
                         "background-color: #FFFFFF;"
                         "box-shadow: 0px 0px 8px rgba(37, 117, 252, 0.5);"
                         "}";

    QString labelStyle = "QLabel {"
                         "font-size: 20px;"
                         "font-weight: bold;"
                         "color: #333;"
                         "text-align: center;"
                         "background-color: #FFFFFF;"
                         "border-radius: 10px;"
                         "padding: 10px;"
                         "box-shadow: 0px 4px 10px rgba(0, 0, 0, 0.1);"
                         "}";

    QString windowStyle = "QWidget {"
                          "background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #f3e5f5, stop:1 #e3f2fd);"
                          "border-radius: 15px;"
                          "padding: 20px;"
                          "}";

    addButton->setStyleSheet(buttonStyle);
    subButton->setStyleSheet(buttonStyle);
    mulButton->setStyleSheet(buttonStyle);
    divButton->setStyleSheet(buttonStyle);
    clearButton->setStyleSheet(buttonStyle);
    num1->setStyleSheet(inputStyle);
    num2->setStyleSheet(inputStyle);
    resultLabel->setStyleSheet(labelStyle);
    setStyleSheet(windowStyle);

    // Layouts
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setSpacing(15);
    mainLayout->setAlignment(Qt::AlignCenter);

    // Add input fields directly
    mainLayout->addWidget(num1);
    mainLayout->addWidget(num2);

    // Buttons Layout
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(subButton);
    buttonLayout->setSpacing(15);
    mainLayout->addLayout(buttonLayout);

    buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(mulButton);
    buttonLayout->addWidget(divButton);
    buttonLayout->setSpacing(15);
    mainLayout->addLayout(buttonLayout);

    // Clear Button
    mainLayout->addWidget(clearButton);

    // Result label
    mainLayout->addWidget(resultLabel);

    setLayout(mainLayout);

    // Set fixed size for the calculator
    setFixedSize(300, 400);

    // Button Click Connections
    connect(addButton, &QPushButton::clicked, this, &Calculator::add);
    connect(subButton, &QPushButton::clicked, this, &Calculator::subtract);
    connect(mulButton, &QPushButton::clicked, this, &Calculator::multiply);
    connect(divButton, &QPushButton::clicked, this, &Calculator::divide);
    connect(clearButton, &QPushButton::clicked, this, &Calculator::clear);
}

// Operations
void Calculator::add() {
    double val1 = num1->text().toDouble();
    double val2 = num2->text().toDouble();
    resultLabel->setText("Result: " + QString::number(val1 + val2));
}

void Calculator::subtract() {
    double val1 = num1->text().toDouble();
    double val2 = num2->text().toDouble();
    resultLabel->setText("Result: " + QString::number(val1 - val2));
}

void Calculator::multiply() {
    double val1 = num1->text().toDouble();
    double val2 = num2->text().toDouble();
    resultLabel->setText("Result: " + QString::number(val1 * val2));
}

void Calculator::divide() {
    double val1 = num1->text().toDouble();
    double val2 = num2->text().toDouble();
    if (val2 == 0) {
        resultLabel->setText("Cannot divide by zero");
        return;
    }
    resultLabel->setText("Result: " + QString::number(val1 / val2));
}

void Calculator::clear() {
    num1->clear();
    num2->clear();
    resultLabel->setText("Result: 0");
}
