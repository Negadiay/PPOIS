#include "PersonalTraining.h"
#include <iostream>

PersonalTraining::PersonalTraining(Member* client, Coach* coach, const std::string& dateTime)
    : client(client), coach(coach), dateTime(dateTime) {}

void PersonalTraining::scheduleTraining() {
    std::cout << "������������ ���������� ��������� ��: " << dateTime << "\n";
}

void PersonalTraining::rescheduleTraining(const std::string& newDateTime) {
    dateTime = newDateTime;
    std::cout << "������������ ���������� ���������� ��: " << dateTime << "\n";
}

void PersonalTraining::showInfo() const {
    std::cout << "������: " << client->getName() << ", ������: " << coach->getName()
        << ", ���� � ����� ����������: " << dateTime << "\n";
}

std::string PersonalTraining::getDateTime() const {
    return dateTime;  
}