#include "Transaction.h"
#include "Account.h"  // ���������� Account

// ����������� ����������
Transaction::Transaction(Account* account, const std::string& type, double amount, const std::string& timestamp)
    : account(account), type(type), amount(amount), timestamp(timestamp) {}

// ����� ��� ���������� ����������
void Transaction::execute() {
    if (type == "���������") {
        account->deposit(amount);
    }
    else if (type == "�����") {
        account->withdraw(amount);
    }
    else {
        std::cout << "�������� ��� ����������!" << std::endl;
    }
    std::cout << "�������� " << type << " �� ����� " << amount << " ��������� �� ���� ID: " << account->getId() << std::endl;
}

// �������
const std::string& Transaction::getType() const {
    return type;
}

double Transaction::getAmount() const {
    return amount;
}

const std::string& Transaction::getTimestamp() const {
    return timestamp;
}
