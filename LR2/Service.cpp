#include "Service.h"
#include <iostream>

Service::Service(const std::string& name, double price)
    : name(name), price(price) {}

void Service::addService() {
    std::cout << "������ \"" << name << "\" ���������.\n";
}

void Service::removeService() {
    std::cout << "������ \"" << name << "\" �������.\n";
}

void Service::showInfo() const {
    std::cout << "������: " << name << ", ���������: " << price << "\n";
}
