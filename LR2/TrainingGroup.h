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
        addMember(member);  // ��������� ��������� ����� � ������
    }

    void addMember(Member* member) {
        members.push_back(member);
        std::cout << "�������� �������� � ������: " << groupName << std::endl;
    }

    void removeMember(Member* member) {
        auto it = std::find(members.begin(), members.end(), member);
        if (it != members.end()) {
            members.erase(it);
            std::cout << "�������� ������ �� ������: " << groupName << std::endl;
        }
    }

    void showInfo() const {
        std::cout << "������: " << groupName << ", ����������: " << members.size() << std::endl;
    }
};