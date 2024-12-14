#include "Gym.h"
#include <iostream>

Gym::Gym(const std::string& name, size_t capacity)
    : name(name), capacity(capacity) {}

void Gym::addEquipment(const GymEquipment& equipment) {
    if (equipments.size() < capacity) {
        equipments.push_back(equipment);
        std::cout << "Тренажер добавлен в зал.\n";
    }
    else {
        std::cout << "Зал достиг максимальной вместимости.\n";
    }
}

void Gym::listEquipments() const {
    if (equipments.empty()) {
        std::cout << "В зале нет тренажеров.\n";
    }
    else {
        std::cout << "Тренажеры в зале " << name << ":\n";
        for (const auto& equipment : equipments) {
            equipment.showInfo();
        }
    }
}

bool Gym::isAvailable() const {
    return !equipments.empty();
}

void Gym::showInfo() const {
    std::cout << "Название зала: " << name << "\n"
        << "Вместимость: " << capacity << "\n"
        << "Число тренажеров: " << equipments.size() << "\n";
}