#include "Account.h"
#include "Transaction.h"  // Подключаем Transaction

// Конструктор аккаунта
Account::Account(int id, double initialBalance)
    : id(id), balance(initialBalance) {}

// Геттеры
int Account::getId() const {
    return id;
}

double Account::getBalance() const {
    return balance;
}

// Методы для пополнения и снятия средств
void Account::deposit(double amount) {
    balance += amount;
}

void Account::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
    }
    else {
        // Обработка ошибки недостаточного баланса
        std::cout << "Ошибка: Недостаточно средств для снятия!" << std::endl;
    }
}

// Метод для добавления транзакции
void Account::addTransaction(Transaction* transaction) {
    transactions.push_back(transaction);
}
