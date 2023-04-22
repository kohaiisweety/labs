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
        cout << "������� ������ �������: ";
        cin >> first;
        cout << "������� ���������� ���������: ";
        cin >> second;
    }

    void show() {
        cout << "������ �������: " << first << endl;
        cout << "���������� ���������: " << second << endl;
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
        cout << "\n����\n";
        cout << "1. ���������������� ������ ������ Progression\n";
        cout << "2. ������� �������� ������� ������ Progression\n";
        cout << "3. ��������� �������� ������� ������ Progression\n";
        cout << "4. ����� n-�� �������\n";
        cout << "5. ��������� ������� �����\n";
        cout << "6. �����\n";
        cout << "�������� (1-6): ";
        cout << endl;
        cin >> choice;
        switch (choice) {
        case 1: {
            double a0;
            int r;
            cout << "������� ������ �������: ";
            cin >> a0;
            cout << "������� ���������� ���������: ";
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
            cout << "������� ����� ������� ���� �����: ";
            cin >> n;
            cout << n << "-�� �������: " << progression.element(n - 1) << endl;
            break;
        }
        case 5: {
            double base;
            int exponent;
            cout << "������� ��������� �������: ";
            cin >> base;
            cout << "������� ���������� �������: ";
            cin >> exponent;
            cout << base << " � ������� " << exponent << " ����� " << progression.power(base, exponent) << endl;
            break;
        }
        case 6:
            cout << "�����\n";
            break;
        default:
            cout << "������������ ��������\n";
            break;
        }
    } while (choice != 6);
    return 0;
}

