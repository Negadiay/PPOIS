#include "Account.h"
#include "Transaction.h"  // ���������� Transaction

// ����������� ��������
Account::Account(int id, double initialBalance)
    : id(id), balance(initialBalance) {}

// �������
int Account::getId() const {
    return id;
}

double Account::getBalance() const {
    return balance;
}

// ������ ��� ���������� � ������ �������
void Account::deposit(double amount) {
    balance += amount;
}

void Account::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
    }
    else {
        // ��������� ������ �������������� �������
        std::cout << "������: ������������ ������� ��� ������!" << std::endl;
    }
}

// ����� ��� ���������� ����������
void Account::addTransaction(Transaction* transaction) {
    transactions.push_back(transaction);
}
