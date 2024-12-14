#include "Administrator.h"
#include <iostream>

Administrator::Administrator(const std::string& name, const std::string& workSchedule)
    : name(name), workSchedule(workSchedule) {}

void Administrator::processClientRequest() {
    std::cout << "��������� ������� �������.\n";
}

void Administrator::assignTrainerToSession() {
    std::cout << "���������� ������� �� ����������.\n";
}

void Administrator::showInfo() const {
    std::cout << "�������������: " << name << ", ������ ������: " << workSchedule << "\n";
}
