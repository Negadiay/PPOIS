#include "PersonalTraining.h"
#include <iostream>

PersonalTraining::PersonalTraining(Member* client, Coach* coach, const std::string& dateTime)
    : client(client), coach(coach), dateTime(dateTime) {}

void PersonalTraining::scheduleTraining() {
    std::cout << "Персональная тренировка назначена на: " << dateTime << "\n";
}

void PersonalTraining::rescheduleTraining(const std::string& newDateTime) {
    dateTime = newDateTime;
    std::cout << "Персональная тренировка перенесена на: " << dateTime << "\n";
}

void PersonalTraining::showInfo() const {
    std::cout << "Клиент: " << client->getName() << ", Тренер: " << coach->getName()
        << ", Дата и время тренировки: " << dateTime << "\n";
}

std::string PersonalTraining::getDateTime() const {
    return dateTime;  
}