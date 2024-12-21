#include "Customer.h"

// Конструктор клиента
Customer::Customer(int id, const std::string& name)
    : id(id), name(name) {}

// Геттеры
int Customer::getId() const {
    return id;
}

const std::string& Customer::getName() const {
    return name;
}

// Метод для добавления аккаунта
void Customer::addAccount(Account* account) {
    accounts.push_back(account);
}

// Получить список аккаунтов клиента
const std::vector<Account*>& Customer::getAccounts() const {
    return accounts;
}
