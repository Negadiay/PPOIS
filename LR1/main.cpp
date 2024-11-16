#include <iostream>
#include "Rectangle.h"

void displayMenu() {
    std::cout << "\n=== ���� ===\n";
    std::cout << "1. ���������� ����� ����������\n";
    std::cout << "2. �������� ������\n";
    std::cout << "3. �������� �����\n";
    std::cout << "4. �������� ������� ��������������\n";
    std::cout << "5. �������� �������������� (==)\n";
    std::cout << "6. ��������� ������� (++ �������/��������)\n";
    std::cout << "7. ��������� ������� (-- �������/��������)\n";
    std::cout << "8. ����������� ��������������� (+/+=)\n";
    std::cout << "9. ������� ��� �������������� (-/-=)\n";
    std::cout << "10. �������� ������� �������������\n";
    std::cout << "0. �����\n";
    std::cout << "������� ����� ��������: ";
}

int main() {

    setlocale(LC_ALL, "Russian");

    Rectangle rect1(0, 0, 4, 3); 
    Rectangle rect2(2, 1, 5, 7); 
    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int x, y;
            std::cout << "������� ����� ���������� (x y): ";
            std::cin >> x >> y;
            rect1.setNewLocation(x, y);
            std::cout << "���������� ���������.\n";
            break;
        }
        case 2: {
            int newHeight;
            std::cout << "������� ����� ������: ";
            std::cin >> newHeight;
            rect1.changeHeight(newHeight);
            std::cout << "������ ���������.\n";
            break;
        }
        case 3: {
            int newLength;
            std::cout << "������� ����� �����: ";
            std::cin >> newLength;
            rect1.changeLength(newLength);
            std::cout << "����� ���������.\n";
            break;
        }
        case 4: {
            std::cout << "������� ��������������:\n";
            std::cout << "������ �����: (" << rect1.getBottomLeft().x << ", " << rect1.getBottomLeft().y << ")\n";
            std::cout << "������ ������: (" << rect1.getBottomRight().x << ", " << rect1.getBottomRight().y << ")\n";
            std::cout << "������� �����: (" << rect1.getTopLeft().x << ", " << rect1.getTopLeft().y << ")\n";
            std::cout << "������� ������: (" << rect1.getTopRight().x << ", " << rect1.getTopRight().y << ")\n";
            break;
        }
        case 5: {
            std::cout << (rect1 == rect2 ? "�������������� �����.\n" : "�������������� �� �����.\n");
            break;
        }
        case 6: {
            rect1++;
            std::cout << "������� ���������.\n";
            break;
        }
        case 7: {
            rect1--;
            std::cout << "������� ���������.\n";
            break;
        }
        case 8: {
            Rectangle result = rect1 + rect2;
            std::cout << "��������� ��������:\n" << result;
            break;
        }
        case 9: {
            Rectangle result = rect1 - rect2;
            std::cout << "��������� ���������:\n" << result;
            break;
        }
        case 10: {
            std::cout << "������� �������������:" << std::endl << rect1;
            break;
        }
        case 0:
            std::cout << "����� �� ���������.\n";
            break;
        default:
            std::cout << "�������� �����. ���������� �����.\n";
        }

    } while (choice != 0);

    return 0;
}
