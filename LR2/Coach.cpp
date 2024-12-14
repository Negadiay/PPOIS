#include "Coach.h"
#include <iostream>

Coach::Coach(const std::string& name, const std::string& specialization, int experience)
    : name(name), specialization(specialization), experience(experience) {}

void Coach::conductTraining() {
    std::cout << name << " проводит тренировку.\n";
}

void Coach::developPlan() {
    std::cout << name << " разрабатывает индивидуальный план.\n";
}

void Coach::evaluateProgress() {
    std::cout << name << " оценивает прогресс клиента.\n";
}

void Coach::showInfo() const {
    std::cout << "Имя: " << name << ", Специализация: " << specialization << ", Стаж работы: " << experience << " лет\n";
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
