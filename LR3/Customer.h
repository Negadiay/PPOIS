#pragma once
#include <vector>
#include <string>
#include "Account.h"  // Подключаем Account

class Customer {
private:
    int id;  // Уникальный ID клиента
    std::string name;  // Имя клиента
    std::vector<Account*> accounts;  // Список аккаунтов клиента

public:
    // Конструктор
    Customer(int id, const std::string& name);

    // Геттеры
    int getId() const;
    const std::string& getName() const;

    // Методы для добавления аккаунта
    void addAccount(Account* account);

    // Получить список аккаунтов клиента
    const std::vector<Account*>& getAccounts() const;
};
