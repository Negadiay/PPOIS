#include "Membership.h"
#include <iostream>

Membership::Membership(const std::string& type, double price, int duration)
    : type(type), price(price), duration(duration) {}

void Membership::renew() {
    duration += 30;  
    std::cout << "��������� ������ �� 30 ����.\n";
}

void Membership::freeze() {
    std::cout << "��������� ���������.\n";
}

void Membership::showInfo() const {
    std::cout << "��� ����������: " << type << ", ���������: " << price << ", ���� ��������: " << duration << " ����\n";
}

int Membership::getDuration() const {
    return duration;
}

