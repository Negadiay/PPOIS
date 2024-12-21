#pragma once
#include <string>
#include <vector>

// ��������������� ���������� ������ Transaction
class Transaction;

class Account {
private:
    int id;  // ���������� ID ��������
    double balance;  // ������ ��������
    std::vector<Transaction*> transactions;  // ������ ����������, ��������� � ���������

public:
    // �����������
    Account(int id, double initialBalance);

    // �������
    int getId() const;
    double getBalance() const;

    // ������ ��� ���������� � ������ �������
    void deposit(double amount);
    void withdraw(double amount);

    // ����� ��� ���������� ����������
    void addTransaction(Transaction* transaction);
};