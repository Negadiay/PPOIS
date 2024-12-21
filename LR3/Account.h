#pragma once
#include <string>
#include <vector>

// Предварительное объявление класса Transaction
class Transaction;

class Account {
private:
    int id;  // Уникальный ID аккаунта
    double balance;  // Баланс аккаунта
    std::vector<Transaction*> transactions;  // Список транзакций, связанных с аккаунтом

public:
    // Конструктор
    Account(int id, double initialBalance);

    // Геттеры
    int getId() const;
    double getBalance() const;

    // Методы для пополнения и снятия средств
    void deposit(double amount);
    void withdraw(double amount);

    // Метод для добавления транзакции
    void addTransaction(Transaction* transaction);
};