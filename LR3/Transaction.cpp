#include "Transaction.h"
#include "Account.h"  // Подключаем Account

// Конструктор транзакции
Transaction::Transaction(Account* account, const std::string& type, double amount, const std::string& timestamp)
    : account(account), type(type), amount(amount), timestamp(timestamp) {}

// Метод для выполнения транзакции
void Transaction::execute() {
    if (type == "Пополнить") {
        account->deposit(amount);
    }
    else if (type == "Снять") {
        account->withdraw(amount);
    }
    else {
        std::cout << "Неверный тип транзакции!" << std::endl;
    }
    std::cout << "Операция " << type << " на сумму " << amount << " выполнена на счет ID: " << account->getId() << std::endl;
}

// Геттеры
const std::string& Transaction::getType() const {
    return type;
}

double Transaction::getAmount() const {
    return amount;
}

const std::string& Transaction::getTimestamp() const {
    return timestamp;
}
