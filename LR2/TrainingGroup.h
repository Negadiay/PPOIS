#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Member.h"


class TrainingGroup {
private:
    Member* member;
    std::string groupName;
    std::vector<Member*> members;

public:    
    TrainingGroup(const std::string& groupName, Member* member) : groupName(groupName) {
        addMember(member);  // Добавляем участника сразу в группу
    }

    void addMember(Member* member) {
        members.push_back(member);
        std::cout << "Участник добавлен в группу: " << groupName << std::endl;
    }

    void removeMember(Member* member) {
        auto it = std::find(members.begin(), members.end(), member);
        if (it != members.end()) {
            members.erase(it);
            std::cout << "Участник удален из группы: " << groupName << std::endl;
        }
    }

    void showInfo() const {
        std::cout << "Группа: " << groupName << ", Участников: " << members.size() << std::endl;
    }
};