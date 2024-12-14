#include "Training.h"
#include <iostream>

Training::Training(const std::string& type, int duration, int maxParticipants)
    : type(type), duration(duration), maxParticipants(maxParticipants) {}

void Training::enrollMember() {
    std::cout << "���� ����� ������� �� ����������: " << type << "\n";
}

void Training::cancelTraining() {
    std::cout << "���������� " << type << " ��������.\n";
}

void Training::showInfo() const {
    std::cout << "��� ����������: " << type << ", �����������������: " << duration << " �����, �������� ����������: " << maxParticipants << "\n";
}
