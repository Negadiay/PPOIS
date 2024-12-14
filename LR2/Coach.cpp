#include "Coach.h"
#include <iostream>

Coach::Coach(const std::string& name, const std::string& specialization, int experience)
    : name(name), specialization(specialization), experience(experience) {}

void Coach::conductTraining() {
    std::cout << name << " �������� ����������.\n";
}

void Coach::developPlan() {
    std::cout << name << " ������������� �������������� ����.\n";
}

void Coach::evaluateProgress() {
    std::cout << name << " ��������� �������� �������.\n";
}

void Coach::showInfo() const {
    std::cout << "���: " << name << ", �������������: " << specialization << ", ���� ������: " << experience << " ���\n";
}

std::string Coach::getName() {
    return name;
}

std::string Coach::getSpecialization() {
    return specialization;
}

int Coach::getExperience() {
    return experience;
}
