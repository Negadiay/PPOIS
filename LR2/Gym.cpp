#include "Gym.h"
#include <iostream>

Gym::Gym(const std::string& name, size_t capacity)
    : name(name), capacity(capacity) {}

void Gym::addEquipment(const GymEquipment& equipment) {
    if (equipments.size() < capacity) {
        equipments.push_back(equipment);
        std::cout << "�������� �������� � ���.\n";
    }
    else {
        std::cout << "��� ������ ������������ �����������.\n";
    }
}

void Gym::listEquipments() const {
    if (equipments.empty()) {
        std::cout << "� ���� ��� ����������.\n";
    }
    else {
        std::cout << "��������� � ���� " << name << ":\n";
        for (const auto& equipment : equipments) {
            equipment.showInfo();
        }
    }
}

bool Gym::isAvailable() const {
    return !equipments.empty();
}

void Gym::showInfo() const {
    std::cout << "�������� ����: " << name << "\n"
        << "�����������: " << capacity << "\n"
        << "����� ����������: " << equipments.size() << "\n";
}