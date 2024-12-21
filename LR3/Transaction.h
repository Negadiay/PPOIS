#pragma once
#include <string>
#include <iostream>

// ��������������� ���������� ������ Account
class Account;

class Transaction {
private:
    Account* account;  // ������ �� �������, � ������� ����������� ��������
    std::string type;  // ��� ����������: ���������� ��� ������
    double amount;     // ����� ��������
    std::string timestamp;  // ����� ����������

public:
    // �����������
    Transaction(Account* account, const std::string& type, double amount, const std::string& timestamp);

    // ����� ��� ���������� ����������
    void execute();

    // �������
    const std::string& getType() const;
    double getAmount() const;
    const std::string& getTimestamp() const;
};
