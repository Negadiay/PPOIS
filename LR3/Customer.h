#pragma once
#include <vector>
#include <string>
#include "Account.h"  // ���������� Account

class Customer {
private:
    int id;  // ���������� ID �������
    std::string name;  // ��� �������
    std::vector<Account*> accounts;  // ������ ��������� �������

public:
    // �����������
    Customer(int id, const std::string& name);

    // �������
    int getId() const;
    const std::string& getName() const;

    // ������ ��� ���������� ��������
    void addAccount(Account* account);

    // �������� ������ ��������� �������
    const std::vector<Account*>& getAccounts() const;
};
