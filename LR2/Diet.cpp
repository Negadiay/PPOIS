#include "Diet.h"
#include <iostream>

Diet::Diet(const std::string& name, const std::vector<std::string>& foods, const std::string& recommendations)
    : name(name), foods(foods), recommendations(recommendations) {}

void Diet::createDiet() {
    std::cout << "Диета \"" << name << "\" создана.\n";
}

void Diet::modifyRecommendations() {
    std::cout << "Рекомендации для диеты \"" << name << "\" изменены.\n";
}

void Diet::showInfo() const {
    std::cout << "Диета: " << name << ", Продукты: ";
    for (const auto& food : foods)
        std::cout << food << " ";
    std::cout << ", Рекомендации: " << recommendations << "\n";
}
