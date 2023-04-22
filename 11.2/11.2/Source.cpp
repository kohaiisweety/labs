#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;

struct Point {
    string key;
    Point* next = nullptr;
    Point* pred = nullptr;
};

struct List {
    int size = 0;
    Point* head = nullptr;
    Point* tail = nullptr;
};

bool ListIsEmpty(List* list);
void PushBack(List* list, string str);
void PushFront(List* list, string str);
List* CreateList(int size);
void ShowList(List* list);
void RemoveElement(List* list, string k);
void RemoveElement(List* list, int n);
Point* FindElement(List* list, string k);
Point* FindElement(List* list, int n);
void AddElements(List* list, int count, int number);
void PrintInFile(string filename, List* list);
void PrintFromFile(string filename, List* list, const int size);

void ShowMenu() {
    cout << "\t\t����\n";
    cout << "������� 0 ��� ���������� ������ ���������.\n";
    cout << "������� 1 ��� �������� ������.\n";
    cout << "������� 2 ��� ������ ������.\n";
    cout << "������� 3 ��� ���������� �������� � ������ ������.\n";
    cout << "������� 4 ��� ���������� �������� � ����� ������.\n";
    cout << "������� 5 ��� �������� �������� � ������� ������.\n";
    cout << "������� 6 ��� ���������� ���������� ��������� ����� ��������� � ������� �������.\n";
    cout << "������� 7, ����� ������� ������.\n";
    cout << "������� 8, ����� �������� ������ � ����.\n";
    cout << "������� 9, ����� �������� ������ �� ����� � ������.\n";
}

void menu() {
    int switch_n, size_list, number, count;
    string key, file = "MyFile.txt";
    List* list = new List;
    do {
        system("pause");
        system("cls");
        ShowMenu();
        cin >> switch_n;
        switch (switch_n) {
        case 0:
            cout << "������ ���������!";
            break;
        case 1:
            cout << "������� ������ ������: ";
            cin >> size_list;
            while (size_list < 1) {
                cout << "������ ������ ������ ���� �� ������ � ����� ���������! ������� ������: ";
                cin >> size_list;
            }
            list = CreateList(size_list);
            break;
        case 2:
            ShowList(list);
            break;
        case 3:
            cout << "������� ����� ������:\n";
            getline(cin, key); getline(cin, key);
            PushFront(list, key);
            break;
        case 4:
            cout << "������� ����� ������:\n";
            getline(cin, key); getline(cin, key);
            PushBack(list, key);
            break;
        case 5:
            cout << "������� ����: ";
            getline(cin, key); getline(cin, key);
            RemoveElement(list, key);
            break;
        case 6:
            cout << "������� ����� ��������� ��������: ";
            cin >> number;
            while (!(number > 0 && number <= list->size)) {
                cout << "����� ������ ���� ������ ���� � ������ " << list->size + 1 << "! ������� ����� : ";
                cin >> number;
            }
            cout << "������� ���-�� �������� ���������: ";
            cin >> count;
            while (count < 1) {
                cout << "���-�� ������ ���� ������ ����! ������� ���-�� ���������: ";
                cin >> count;
            }
            AddElements(list, count, number);
            break;
        case 7:
            while (!ListIsEmpty(list)) {
                RemoveElement(list, 1);
            }
            cout << "������ �����!\n";
            break;
        case 8:
            if (!ListIsEmpty(list)) {
                size_list = list->size;
                PrintInFile(file, list);
                cout << "������ �������!\n";
            }
            else
                cout << "������ �� ������!";
            break;
        case 9:
            PrintFromFile(file, list, size_list);
            cout << "������ �� ����� ��������!\n";
            break;
        }
    } while (switch_n != 0);
}

bool ListIsEmpty(List* list) {
    return list == nullptr || list->size == 0;
}

void PushBack(List* list, string str) {
    Point* new_point = new Point;
    new_point->key = str;
    new_point->pred = nullptr;
    new_point->next = nullptr;
    if (ListIsEmpty(list)) {
        list->head = new_point;
        list->tail = new_point;
    }
    else if (list->size == 1) {
        list->tail->next = new_point;
        list->tail = new_point;
        list->head->next = list->tail;
        list->tail->pred = list->head;
    }
    else {
        list->tail->next = new_point;
        new_point->pred = list->tail;
        list->tail = new_point;
    }
    list->size++;
}

void PushFront(List* list, string str) {
    Point* new_point = new Point;
    new_point->key = str;
    new_point->pred = nullptr;
    new_point->next = nullptr;
    if (ListIsEmpty(list)) {
        list->head = new_point;
        list->tail = new_point;
    }
    else if (list->size == 1) {
        list->head->pred = new_point;
        list->head = new_point;
        list->tail->pred = list->head;
        list->head->next = list->tail;
    }
    else {
        list->head->pred = new_point;
        new_point->next = list->head;
        list->head = new_point;
    }
    list->size++;
}

List* CreateList(int size) {
    List* list = new List;
    string str;
    cout << "������� ����� ���������:\n"; getline(cin, str);
    for (int i = 0; i < size; i++) {
        cout << i + 1 << '\t'; getline(cin, str);
        PushBack(list, str);
    }
    return list;
}

void ShowList(List* list) {
    if (ListIsEmpty(list)) cout << "������ ����!\n";
    else {
        int i = 1;
        Point* temp = list->head;
        cout << "---------------------------\n";
        cout << "\t������\n";
        do {
            cout << i++ << '\t' << temp->key << endl;
            temp = temp->next;
        } while (i <= list->size);
        cout << "---------------------------\n";
    }
}

Point* FindElement(List* list, string k) {
    Point* temp = list->head;
    while (temp != nullptr) {
        if (temp->key == k) return temp;
        temp = temp->next;
    }
    return temp;
}

Point* FindElement(List* list, int n) {
    Point* temp = list->head;
    int i = 1;
    while (i <= list->size) {
        if (i == n) return temp;
        temp = temp->next;
        i++;
    }
}

void RemoveElement(List* list, string k) {
    Point* temp = FindElement(list, k);
    if (temp == nullptr) cout << "������� �� ������!\n";
    else {
        if (temp->next != nullptr) (temp->next)->pred = temp->pred;
        if (temp->pred != nullptr) (temp->pred)->next = temp->next;
        if (list->head == temp) list->head = temp->next;
        if (list->tail == temp) list->tail = temp->pred;
        delete temp;
        list->size--;
        cout << "������� �����!\n";
    }
}
void RemoveElement(List* list, int n) {
    Point* temp = FindElement(list, n);
    if (temp == nullptr) cout << "������� �� ������!\n";
    else {
        if (temp->next != nullptr) (temp->next)->pred = temp->pred;
        if (temp->pred != nullptr) (temp->pred)->next = temp->next;
        if (list->head == temp) list->head = temp->next;
        if (list->tail == temp) list->tail = temp->pred;
        delete temp;
        list->size--;
    }
}

void AddElements(List* list, int count, int number) {
    int i = 1;
    string key;
    Point* temp = list->head;
    while (i != number) {
        temp = temp->next;
        i++;
    }
    getline(cin, key);
    for (int j = 1; j <= count; j++) {
        cout << "������� ����� ���� " << j << ": ";
        getline(cin, key);
        Point* new_point = new Point;
        new_point->next = temp;
        new_point->pred = temp->pred;
        temp->pred = new_point;
        if (new_point->pred == nullptr && temp->next) list->head = new_point;
        else (new_point->pred)->next = new_point;
        new_point->key = key;
        list->size++;
    }
}

void PrintInFile(string filename, List* list) {
    ofstream fout(filename);
    Point* temp = list->head;
    if (!fout.is_open())
        cout << "�� ������� ������� ����!\n";
    else {
        while (!ListIsEmpty(list)) {
            temp = list->head;
            fout << temp->key;
            fout << '\n';
            RemoveElement(list, 1);
        }
    }
    fout.close();
}

void PrintFromFile(string filename, List* list, const int size) {
    ifstream fin(filename);
    string key;
    if (!fin.is_open())
        cout << "�� ������� ������� ����!\n";
    else {
        for (int i = 1; i <= size; i++) {
            fin >> key;
            PushBack(list, key);
        }
    }
    fin.close();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    menu();
    return 0;
}