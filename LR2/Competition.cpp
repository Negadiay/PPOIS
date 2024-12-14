#include "Competition.h"
#include "Member.h"
#include <iostream>

Competition::Competition(const std::string& name, const std::string& date, double prizeFund)
    : name(name), date(date), prizeFund(prizeFund) {}

void Competition::registerParticipant(Member* member) {
    participants.push_back(member);
    std::cout << "���� ����� ��������������� �� ������������: " << name << "\n";
}

void Competition::publishResults() {
    std::cout << "���������� ������������ \"" << name << "\" ������������.\n";
}

void Competition::cancelCompetition() {
    std::cout << "������������ \"" << name << "\" ��������.\n";
}

void Competition::showInfo() const {
    std::cout << "������������: " << name << ", ����: " << date << ", �������� ����: " << prizeFund << "\n";
}

std::string Competition::getName() const {
    return name;
}

std::string Competition::getDate() const {
    return date;
}
