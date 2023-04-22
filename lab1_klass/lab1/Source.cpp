#include <iostream>
#include <cmath>

using namespace std;

class Progression {
private:
	double first;
	int second;

public:
	Progression(double a0 = 0, int r = 0) {
		first = a0;
		second = r;
	}
    void init(double a0, int r) {
        first = a0;
        second = r;
    }

    void read() {
        cout << "Введите первый элемент: ";
        cin >> first;
        cout << "Введите постоянное отношение: ";
        cin >> second;
    }

    void show() {
        cout << "Первый элемент: " << first << endl;
        cout << "Постоянное отношение: " << second << endl;
    }

    double element(int j) {
        return first * pow(second, j);
    }

    double power(double base, int exponent) {
        return pow(base, exponent);
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    Progression progression;
    int choice;
    do {
        cout << "\nМеню\n";
        cout << "1. Инициализировать объект класса Progression\n";
        cout << "2. Вывести значения объекта класса Progression\n";
        cout << "3. Прочитать значения объекта класса Progression\n";
        cout << "4. Найти n-ый элемент\n";
        cout << "5. Вычислить степень числа\n";
        cout << "6. Выход\n";
        cout << "Выберите (1-6): ";
        cout << endl;
        cin >> choice;
        switch (choice) {
        case 1: {
            double a0;
            int r;
            cout << "Введите первый элемент: ";
            cin >> a0;
            cout << "Введите постоянное отношение: ";
            cin >> r;
            progression.init(a0, r);
            break;
        }
        case 2: {
            progression.show();
            break;
        }
        case 3: {
            progression.read();
            break;
        }
        case 4: {
            int n;
            cout << "Введите какой элемент надо найти: ";
            cin >> n;
            cout << n << "-ый элемент: " << progression.element(n - 1) << endl;
            break;
        }
        case 5: {
            double base;
            int exponent;
            cout << "Введите основание степени: ";
            cin >> base;
            cout << "Введите показатель степени: ";
            cin >> exponent;
            cout << base << " в степени " << exponent << " равно " << progression.power(base, exponent) << endl;
            break;
        }
        case 6:
            cout << "конец\n";
            break;
        default:
            cout << "неправильное значение\n";
            break;
        }
    } while (choice != 6);
    return 0;
}

