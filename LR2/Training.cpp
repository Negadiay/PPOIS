#include "Training.h"
#include <iostream>

Training::Training(const std::string& type, int duration, int maxParticipants)
    : type(type), duration(duration), maxParticipants(maxParticipants) {}

void Training::enrollMember() {
    std::cout << "Член клуба записан на тренировку: " << type << "\n";
}

void Training::cancelTraining() {
    std::cout << "Тренировка " << type << " отменена.\n";
}

void Training::showInfo() const {
    std::cout << "Тип тренировки: " << type << ", Продолжительность: " << duration << " минут, Максимум участников: " << maxParticipants << "\n";
}
