#include "Payment.h"
#include <iostream>

Payment::Payment(double amount, const std::string& date, const std::string& paymentMethod)
    : amount(amount), date(date), paymentMethod(paymentMethod) {}

void Payment::processPayment() {
    std::cout << "Платеж на сумму " << amount << " проведен.\n";
}

void Payment::cancelPayment() {
    std::cout << "Платеж на сумму " << amount << " отменен.\n";
}

void Payment::showInfo() const {
    std::cout << "Платеж: Сумма - " << amount << ", Дата - " << date << ", Способ оплаты - " << paymentMethod << "\n";
}
