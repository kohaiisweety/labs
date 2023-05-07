#include <iostream>
#include "Pair.h"
#include "Vector.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    // Создаем вектор пар
    Vector<Pair> pairs(3, Pair(0, 0));
    int choice = 0;
    Pair p;
    Pair p2;
    while (true) {
        // Выводим меню
        cout << "Меню:\n";
        cout << "1. Добавить элемент в контейнер\n";
        cout << "2. Добавить элемент 2 в контейнер\n";
        cout << "3. Умножение\n";
        cout << "4. Деление\n";
        cout << "5. Сложение\n";
        cout << "6. Вычитание\n";
        cout << "7. Введите индекс чтобы получить элемент\n";
        cout << "8. Выход\n";
        cout << "Введите ваш выбор: ";
        cout << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            // Добавляем новую пару в вектор
            cin >> p;
            pairs = pairs + p;
            break;
        case 2:
            // Вводим вторую пару
            cout << "Введите значение для второй пары:\n";
            cin >> p2;
            pairs = pairs + p2;
            break;
        case 3:
            // Умножаем пары и выводим результат
            cout << "p * p2 = " << p*p2 << endl;
            break;
        case 4:
            // Делим пары и выводим результат
            cout << "p / p2 = " << p / p2 << endl;
            break;
        case 5:
            // Складываем пары и выводим результат
            cout << "p + p2 = " << p + p2 << endl;
            break;
        case 6:
            // Вычитаем пары и выводим результат
            cout << "p - p2 = " << p - p2 << endl;
            break;
        case 7:
            // Получаем элемент по индексу и выводим результат
            int index;
            cout << "Введите индекс элемента: ";
            cin >> index;
            if (index >= 0 && index < pairs()) {
                cout << "Элемент[" << index << "]: " << pairs[index] << endl;
            }
            else {
                cout << "Неверный индекс элемента.\n";
            }
            break;
        case 8:
            return 0;
        default:
            cout << "Неверный выбор. Попробуйте еще раз.\n";
            break;
        }
    }

    return 0;
}