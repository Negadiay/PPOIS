#pragma once
#include <string>
#include <iostream>

// Предварительное объявление класса Account
class Account;

class Transaction {
private:
    Account* account;  // Ссылка на аккаунт, в котором выполняется операция
    std::string type;  // Тип транзакции: пополнение или снятие
    double amount;     // Сумма операции
    std::string timestamp;  // Время транзакции

public:
    // Конструктор
    Transaction(Account* account, const std::string& type, double amount, const std::string& timestamp);

    // Метод для выполнения транзакции
    void execute();

    // Геттеры
    const std::string& getType() const;
    double getAmount() const;
    const std::string& getTimestamp() const;
};
