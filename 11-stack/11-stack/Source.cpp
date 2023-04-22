#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;

struct Node {
    string key;
    Node* next = nullptr;
};

struct Stack {
    int size = 0;
    Node* head = nullptr;
};

bool StackIsEmpty(Stack* st);
void Push(Stack* st, string str);
void Pop(Stack* st);
Stack* CreateStack(int size);
void ShowStack(Stack* st);
void RemoveElement(Stack* st, string k);
void AddElements(Stack* st, int count, int number);
void PrintInFile(string filename, Stack* st);
void PrintFromFile(string filename, Stack* st, const int size);

void ShowMenu() {
    cout << "\t\t����\n";
    cout << "������� 0 ��� ���������� ������.\n";
    cout << "������� 1 ��� �������� �����.\n";
    cout << "������� 2 ��� ������ �����.\n";
    cout << "������� 3 ��� ���������� �������� �� ��� �����.\n";
    cout << "������� 4 ��� ���������� �������� �� �������� �����.\n";
    cout << "������� 5 ��� �������� �������� � ������� ������.\n";
    cout << "������� 6 ��� ���������� ���������� ��������� ����� ��������� � ������� �������.\n";
    cout << "������� 7, ����� ������� ����.\n";
    cout << "������� 8, ����� �������� ������ � ����.\n";
    cout << "������� 9, ����� �������� ������ �� ����� � ����.\n";
}

void menu() {
    int switch_n, size_stack, number, count;
    string key, file = "MyFile.txt";
    Stack* st = new Stack;
    do {
        system("pause");
        system("cls");
        ShowMenu();
        cin >> switch_n;
        switch (switch_n) {
        case 0:
            cout << "�� ������������� �����!";
            break;
        case 1:
            cout << "������� ������ �����: ";
            cin >> size_stack;
            while (size_stack < 1) {
                cout << "������ ����� ������ ���� �� ������ � ����� ���������! ������� ������: ";
                cin >> size_stack;
            }
            st = CreateStack(size_stack);
            break;
        case 2:
            ShowStack(st);
            break;
        case 3:
            AddElements(st, 1, 1);
            break;
        case 4:
            cout << "������� ����� ������:\n";
            getline(cin, key); getline(cin, key);
            Push(st, key);
            break;
        case 5:
            cout << "������� ����: ";
            getline(cin, key); getline(cin, key);
            RemoveElement(st, key);
            break;
        case 6:
            cout << "������� ����� ��������� ��������: ";
            cin >> number;
            while (number < 1 || number > st->size) {
                cout << "����� ������ ���� ������ ���� � ������ " << st->size + 1 << "!������� ����� : ";
                cin >> number;
            }
            cout << "������� ���-�� �������� ���������: ";
            cin >> count;
            while (count < 1) {
                cout << "���-�� ������ ���� ������ ����! ������� ���-�� ���������: ";
                cin >> count;
            }
            AddElements(st, count, number);
            break;
        case 7:
            while (!StackIsEmpty(st))
                Pop(st);
            delete st;
            cout << "���� �����!\n";
            break;
        case 8:
            if (!StackIsEmpty(st)) {
                size_stack = st->size;
                PrintInFile(file, st);
                cout << "������ �������!\n";
            }
            else
                cout << "���� �� ������!\n";
            break;
        case 9:
            if (size_stack != 0) {
                PrintFromFile(file, st, size_stack);
                cout << "������ �� ����� ��������!\n";
            }
            break;
        }
    } while (switch_n > 0 && switch_n <= 9);
}

bool StackIsEmpty(Stack* st) {
    return st == nullptr || st->size == 0;
}

void Push(Stack* st, string str) {
    Node* new_node = new Node;
    new_node->key = str;
    new_node->next = st->head;
    st->head = new_node;
    st->size++;
}

void Pop(Stack* st) {
    Node* temp = st->head;
    st->head = temp->next;
    st->size--;
    delete temp;
}

Stack* CreateStack(int size) {
    Stack* st = new Stack;
    string str;
    cout << "������� ����� ���������:\n"; getline(cin, str);
    for (int i = 0; i < size; i++) {
        cout << i + 1 << '\t';
        getline(cin, str);
        Push(st, str);
    }
    return st;
}

void ShowStack(Stack* st) {
    if (StackIsEmpty(st)) cout << "���� ����!\n";
    else {
        Node* temp = st->head;
        int i = st->size;
        cout << "---------------------------\n����:\n";
        while (temp != nullptr) {
            cout << i << '\t' << temp->key << '\n';
            temp = temp->next;
            i--;
        }
        cout << "---------------------------\n";
    }
}

void RemoveElement(Stack* st, string k) {
    if (StackIsEmpty(st)) {
        cout << "���� ����!\n";
        return;
    }
    Stack* new_stack = new Stack;
    while (!StackIsEmpty(st)) {
        if (st->head->key != k) {
            Push(new_stack, st->head->key);
            Pop(st);
        }
        else
            Pop(st);
    }
    while (!StackIsEmpty(new_stack)) {
        Push(st, new_stack->head->key);
        Pop(new_stack);
    }
    delete new_stack;
}

void AddElements(Stack* st, int count, int number) {
    if (number > st->size) return;
    int i = st->size;
    Stack* new_stack = new Stack;
    while (i >= number) {
        Push(new_stack, st->head->key);
        Pop(st);
        i--;
    }
    string key;
    getline(cin, key);
    for (int j = 1; j <= count; j++) {
        cout << "������� ����� ����: ";
        getline(cin, key);
        Push(st, key);
    }
    while (!StackIsEmpty(new_stack)) {
        Push(st, new_stack->head->key);
        Pop(new_stack);
    }
    delete new_stack;
}

void PrintInFile(string filename, Stack* st) {
    ofstream fout;
    fout.open(filename);
    if (!fout.is_open()) {
        cout << "�� ������� ������� ����!\n";
    }
    else {
        while (!StackIsEmpty(st)) {
            fout << st->head->key << '\n';
            Pop(st);
        }
    }
    fout.close();
}

void PrintFromFile(string filename, Stack* st, const int size) {
    ifstream fin;
    fin.open(filename);
    string key;
    Stack* new_stack = new Stack;
    if (!fin.is_open()) {
        cout << "�� ������� ������� ����!\n";
    }
    else {
        for (int i = 1; i <= size; i++) {
            fin >> key;
            Push(new_stack, key);
        }
        while (!StackIsEmpty(new_stack)) {
            Push(st, new_stack->head->key);
            Pop(new_stack);
        }
        delete new_stack;
    }
    fin.close();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    menu();
    return 0;
}