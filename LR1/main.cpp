#include <iostream>
#include "Rectangle.h"

void displayMenu() {
    std::cout << "\n=== Меню ===\n";
    std::cout << "1. Установить новые координаты\n";
    std::cout << "2. Изменить высоту\n";
    std::cout << "3. Изменить длину\n";
    std::cout << "4. Получить вершины прямоугольника\n";
    std::cout << "5. Сравнить прямоугольники (==)\n";
    std::cout << "6. Увеличить размеры (++ префикс/постфикс)\n";
    std::cout << "7. Уменьшить размеры (-- префикс/постфикс)\n";
    std::cout << "8. Объединение прямоугольников (+/+=)\n";
    std::cout << "9. Вычесть два прямоугольника (-/-=)\n";
    std::cout << "10. Показать текущий прямоугольник\n";
    std::cout << "0. Выход\n";
    std::cout << "Введите номер действия: ";
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
            std::cout << "Введите новые координаты (x y): ";
            std::cin >> x >> y;
            rect1.setNewLocation(x, y);
            std::cout << "Координаты обновлены.\n";
            break;
        }
        case 2: {
            int newHeight;
            std::cout << "Введите новую высоту: ";
            std::cin >> newHeight;
            rect1.changeHeight(newHeight);
            std::cout << "Высота обновлена.\n";
            break;
        }
        case 3: {
            int newLength;
            std::cout << "Введите новую длину: ";
            std::cin >> newLength;
            rect1.changeLength(newLength);
            std::cout << "Длина обновлена.\n";
            break;
        }
        case 4: {
            std::cout << "Вершины прямоугольника:\n";
            std::cout << "Нижний левый: (" << rect1.getBottomLeft().x << ", " << rect1.getBottomLeft().y << ")\n";
            std::cout << "Нижний правый: (" << rect1.getBottomRight().x << ", " << rect1.getBottomRight().y << ")\n";
            std::cout << "Верхний левый: (" << rect1.getTopLeft().x << ", " << rect1.getTopLeft().y << ")\n";
            std::cout << "Верхний правый: (" << rect1.getTopRight().x << ", " << rect1.getTopRight().y << ")\n";
            break;
        }
        case 5: {
            std::cout << (rect1 == rect2 ? "Прямоугольники равны.\n" : "Прямоугольники не равны.\n");
            break;
        }
        case 6: {
            rect1++;
            std::cout << "Размеры увеличены.\n";
            break;
        }
        case 7: {
            rect1--;
            std::cout << "Размеры уменьшены.\n";
            break;
        }
        case 8: {
            Rectangle result = rect1 + rect2;
            std::cout << "Результат сложения:\n" << result;
            break;
        }
        case 9: {
            Rectangle result = rect1 - rect2;
            std::cout << "Результат вычитания:\n" << result;
            break;
        }
        case 10: {
            std::cout << "Текущий прямоугольник:" << std::endl << rect1;
            break;
        }
        case 0:
            std::cout << "Выход из программы.\n";
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова.\n";
        }

    } while (choice != 0);

    return 0;
}
