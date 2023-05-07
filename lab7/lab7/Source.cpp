#include <iostream>
#include "Pair.h"
#include "Vector.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    // ������� ������ ���
    Vector<Pair> pairs(3, Pair(0, 0));
    int choice = 0;
    Pair p;
    Pair p2;
    while (true) {
        // ������� ����
        cout << "����:\n";
        cout << "1. �������� ������� � ���������\n";
        cout << "2. �������� ������� 2 � ���������\n";
        cout << "3. ���������\n";
        cout << "4. �������\n";
        cout << "5. ��������\n";
        cout << "6. ���������\n";
        cout << "7. ������� ������ ����� �������� �������\n";
        cout << "8. �����\n";
        cout << "������� ��� �����: ";
        cout << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            // ��������� ����� ���� � ������
            cin >> p;
            pairs = pairs + p;
            break;
        case 2:
            // ������ ������ ����
            cout << "������� �������� ��� ������ ����:\n";
            cin >> p2;
            pairs = pairs + p2;
            break;
        case 3:
            // �������� ���� � ������� ���������
            cout << "p * p2 = " << p*p2 << endl;
            break;
        case 4:
            // ����� ���� � ������� ���������
            cout << "p / p2 = " << p / p2 << endl;
            break;
        case 5:
            // ���������� ���� � ������� ���������
            cout << "p + p2 = " << p + p2 << endl;
            break;
        case 6:
            // �������� ���� � ������� ���������
            cout << "p - p2 = " << p - p2 << endl;
            break;
        case 7:
            // �������� ������� �� ������� � ������� ���������
            int index;
            cout << "������� ������ ��������: ";
            cin >> index;
            if (index >= 0 && index < pairs()) {
                cout << "�������[" << index << "]: " << pairs[index] << endl;
            }
            else {
                cout << "�������� ������ ��������.\n";
            }
            break;
        case 8:
            return 0;
        default:
            cout << "�������� �����. ���������� ��� ���.\n";
            break;
        }
    }

    return 0;
}