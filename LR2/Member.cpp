#include "Member.h"
#include "Membership.h"

Member::Member(const std::string& name, int age)
    : name(name), age(age), membership(nullptr) {}

void Member::registerInClub(Membership* m) {
    membership = m;
    std::cout << name << " ��������������� � ����� � �����������.\n";
}

void Member::cancelMembership() {
    membership = nullptr;
    std::cout << name << " ������� ��������.\n";
}

void Member::showInfo() const {
    std::cout << "���: " << name << ", �������: " << age << "\n";
}

std::string Member::getName() const {
    return name;  
}

Membership* Member::getMembership() const {
    return membership;
}