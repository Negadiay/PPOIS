#include "Review.h"
#include <iostream>

Review::Review(const std::string& clientName, const std::string& text,Member*member)
    : clientName(clientName), text(text),member(member) {}

void Review::leaveReview() {
    std::cout << "����� �� " << member->getName() << ": " << text << "\n";
}

void Review::deleteReview() {
    std::cout << "����� ������.\n";
}

void Review::showInfo() const {
    std::cout << "����� �� " << member->getName() << ": " << text << "\n"; 

}
