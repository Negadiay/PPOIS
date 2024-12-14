#include "GymEquipment.h"
#include <iostream>

GymEquipment::GymEquipment(const std::string& name, const std::string& type)
    : name(name), type(type), isWorking(true) {}

void GymEquipment::checkCondition() {
    if (isWorking)
        std::cout << "Тренажер " << name << " в хорошем состоянии.\n";
    else
        std::cout << "Тренажер " << name << " не исправен.\n";
}

void GymEquipment::repair() {
    isWorking = true;
    std::cout << "Тренажер " << name << " отремонтирован.\n";
}

void GymEquipment::showInfo() const {
    std::cout << "Тренажер: " << name << ", Тип: " << type << ", Состояние: " << (isWorking ? "Исправен" : "Неисправен") << "\n";
}

bool GymEquipment::getIsWorking() const {
    return isWorking;
}

