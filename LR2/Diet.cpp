#include "Diet.h"
#include <iostream>

Diet::Diet(const std::string& name, const std::vector<std::string>& foods, const std::string& recommendations)
    : name(name), foods(foods), recommendations(recommendations) {}

void Diet::createDiet() {
    std::cout << "����� \"" << name << "\" �������.\n";
}

void Diet::modifyRecommendations() {
    std::cout << "������������ ��� ����� \"" << name << "\" ��������.\n";
}

void Diet::showInfo() const {
    std::cout << "�����: " << name << ", ��������: ";
    for (const auto& food : foods)
        std::cout << food << " ";
    std::cout << ", ������������: " << recommendations << "\n";
}
