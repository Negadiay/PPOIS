#include "TrainingGroup.h"
#include "Member.h"
#include <iostream>

TrainingGroup::TrainingGroup(const std::string& groupName,Member*member) : groupName(groupName),member(member) {}

void TrainingGroup::addMember(Member* member) {
    members.push_back(member);
    std::cout << "Участник добавлен в группу: " << groupName << "\n";
}

void TrainingGroup::removeMember(Member* member) {
    for (auto it = members.begin(); it != members.end(); ++it) {
        if (*it == member) {
            members.erase(it);
            std::cout << "Участник удален из группы: " << groupName << "\n";
            return;
        }
    }
}

void TrainingGroup::showInfo() const {
    std::cout << "Группа: " << member->getName() << ", Участников: " << members.size() << "\n";
}

