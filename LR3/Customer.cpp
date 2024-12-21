#include "Customer.h"

// ����������� �������
Customer::Customer(int id, const std::string& name)
    : id(id), name(name) {}

// �������
int Customer::getId() const {
    return id;
}

const std::string& Customer::getName() const {
    return name;
}

// ����� ��� ���������� ��������
void Customer::addAccount(Account* account) {
    accounts.push_back(account);
}

// �������� ������ ��������� �������
const std::vector<Account*>& Customer::getAccounts() const {
    return accounts;
}
