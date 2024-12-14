#include "Membership.h"
#include <iostream>

Membership::Membership(const std::string& type, double price, int duration)
    : type(type), price(price), duration(duration) {}

void Membership::renew() {
    duration += 30;  
    std::cout << "Абонемент продлён на 30 дней.\n";
}

void Membership::freeze() {
    std::cout << "Абонемент заморожен.\n";
}

void Membership::showInfo() const {
    std::cout << "Тип абонемента: " << type << ", Стоимость: " << price << ", Срок действия: " << duration << " дней\n";
}

int Membership::getDuration() const {
    return duration;
}

