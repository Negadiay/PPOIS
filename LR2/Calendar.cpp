#include "Calendar.h"
#include <iostream>

Calendar::Calendar(const std::string& date) : date(date) {}

void Calendar::addEvent(const std::string& event) {
    events.push_back(event);
    std::cout << "������� \"" << event << "\" ���������.\n";
}

void Calendar::removeEvent(const std::string& event) {
    for (auto it = events.begin(); it != events.end(); ++it) {
        if (*it == event) {
            events.erase(it);
            std::cout << "������� \"" << event << "\" �������.\n";
            return;
        }
    }
}

void Calendar::findEventByDate(const std::string& date) {
    std::cout << "����� ������� �� ����: " << date << "\n";
    for (const auto& event : events) {
        std::cout << event << "\n";
    }
}

void Calendar::showInfo() const {
    std::cout << "����: " << date << ", �������: ";
    if (events.empty()) {
        std::cout << "No events";
    }
    else {
        for (const auto& event : events)
            std::cout << event << " ";
    }
    std::cout << "\n";
}

