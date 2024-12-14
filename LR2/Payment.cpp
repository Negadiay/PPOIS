#include "Payment.h"
#include <iostream>

Payment::Payment(double amount, const std::string& date, const std::string& paymentMethod)
    : amount(amount), date(date), paymentMethod(paymentMethod) {}

void Payment::processPayment() {
    std::cout << "������ �� ����� " << amount << " ��������.\n";
}

void Payment::cancelPayment() {
    std::cout << "������ �� ����� " << amount << " �������.\n";
}

void Payment::showInfo() const {
    std::cout << "������: ����� - " << amount << ", ���� - " << date << ", ������ ������ - " << paymentMethod << "\n";
}
