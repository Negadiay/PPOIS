#include "GymEquipment.h"
#include <iostream>

GymEquipment::GymEquipment(const std::string& name, const std::string& type)
    : name(name), type(type), isWorking(true) {}

void GymEquipment::checkCondition() {
    if (isWorking)
        std::cout << "�������� " << name << " � ������� ���������.\n";
    else
        std::cout << "�������� " << name << " �� ��������.\n";
}

void GymEquipment::repair() {
    isWorking = true;
    std::cout << "�������� " << name << " ��������������.\n";
}

void GymEquipment::showInfo() const {
    std::cout << "��������: " << name << ", ���: " << type << ", ���������: " << (isWorking ? "��������" : "����������") << "\n";
}

bool GymEquipment::getIsWorking() const {
    return isWorking;
}

