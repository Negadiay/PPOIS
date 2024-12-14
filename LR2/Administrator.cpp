#include "Administrator.h"
#include <iostream>

Administrator::Administrator(const std::string& name, const std::string& workSchedule)
    : name(name), workSchedule(workSchedule) {}

void Administrator::processClientRequest() {
    std::cout << "Обработка запроса клиента.\n";
}

void Administrator::assignTrainerToSession() {
    std::cout << "Назначение тренера на тренировку.\n";
}

void Administrator::showInfo() const {
    std::cout << "Администратор: " << name << ", График работы: " << workSchedule << "\n";
}
