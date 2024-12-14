#include "Service.h"
#include <iostream>

Service::Service(const std::string& name, double price)
    : name(name), price(price) {}

void Service::addService() {
    std::cout << "Услуга \"" << name << "\" добавлена.\n";
}

void Service::removeService() {
    std::cout << "Услуга \"" << name << "\" удалена.\n";
}

void Service::showInfo() const {
    std::cout << "Услуга: " << name << ", Стоимость: " << price << "\n";
}
