#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;

struct Node {
    string key;
    Node* next = nullptr;
};

struct Queue {
    int size = 0;
    Node* head = nullptr;
    Node* tail = nullptr;
};

bool QueueIsEmpty(Queue* Queue);
void Push(Queue* Queue, string str);
void Pop(Queue* queue);
Queue* CreateQueue(int size);
void ShowQueue(Queue* Queue);
void RemoveElement(Queue* Queue, string k);
void AddElements(Queue* Queue, int count, int number);
void PrintInFile(string filename, Queue* Queue);
void PrintFromFile(string filename, Queue* Queue, const int size);

void ShowMenu() {
    cout << "\t\t����\n";
    cout << "������� 0 ��� ���������� ������ ���������.\n";
    cout << "������� 1 ��� �������� �������.\n";
    cout << "������� 2 ��� ������ �������.\n";
    cout << "������� 3 ��� ���������� �������� � ������ �������.\n";
    cout << "������� 4 ��� ���������� �������� � ����� �������.\n";
    cout << "������� 5 ��� �������� �������� � ������� ������.\n";
    cout << "������� 6 ��� ���������� ���������� ��������� ����� ��������� � ������� �������.\n";
    cout << "������� 7, ����� ������� �������.\n";
    cout << "������� 8, ����� �������� ������ � ����.\n";
    cout << "������� 9, ����� �������� ������ �� ����� � �������.\n";
}

void menu() {
    int switch_n, size_queue, number, count;
    string key, file = "MyFile.txt";
    Queue* queue = new Queue;
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
            cout << "������� ������ �������: ";
            cin >> size_queue;
            while (size_queue < 1) {
                cout << "������ ������ ������ ���� �� ������ � ����� ���������! ������� ������: ";
                cin >> size_queue;
            }
            queue = CreateQueue(size_queue);
            break;
        case 2:
            ShowQueue(queue);
            break;
        case 3:
            AddElements(queue, 1, 1);
            break;
        case 4:
            cout << "������� ����� ������:\n";
            getline(cin, key); getline(cin, key);
            Push(queue, key);
            break;
        case 5:
            cout << "������� ����: ";
            getline(cin, key); getline(cin, key);
            RemoveElement(queue, key);
            break;
        case 6:
            cout << "������� ����� ��������� ��������: ";
            cin >> number;
            while (number < 1 || number > queue->size) {
                cout << "����� ������ ���� ������ ���� � ������ " << queue->size + 1 << "!������� ����� : ";
                cin >> number;
            }
            cout << "������� ���-�� �������� ���������: ";
            cin >> count;
            while (count < 1) {
                cout << "���-�� ������ ���� ������ ����! ������� ���-�� ���������: ";
                cin >> count;
            }
            AddElements(queue, count, number);
            break;
        case 7:
            while (!QueueIsEmpty(queue)) Pop(queue);
            cout << "������� ������!\n";
            break;
        case 8:
            if (!QueueIsEmpty(queue)) {
                size_queue = queue->size;
                PrintInFile(file, queue);
                cout << "������ �������!\n";
            }
            else
                cout << "������� �� �������!\n";
            break;
        case 9:
            if (size_queue != 0) {
                PrintFromFile(file, queue, size_queue);
                cout << "������ �� ����� ��������!\n";
            }
            break;
        }
    } while (switch_n >= 0 && switch_n <= 9);
}

bool QueueIsEmpty(Queue* queue) {
    return queue == nullptr || queue->size == 0;
}

void Push(Queue* queue, string str) {
    if (!QueueIsEmpty(queue)) {
        Node* new_node = new Node;
        queue->size++;
        new_node->key = str;
        new_node->next = nullptr;
        queue->tail->next = new_node;
        queue->tail = new_node;
    }
    else {
        Node* new_node = new Node;
        queue->size = 1;
        new_node->key = str;
        queue->head = new_node;
        queue->tail = new_node;
    }
}

void Pop(Queue* queue) {
    Node* temp = queue->head;
    queue->head = temp->next;
    queue->size--;
    delete temp;
}

Queue* CreateQueue(int size) {
    Queue* queue = new Queue;
    string str;
    cout << "������� ����� ���������:\n"; getline(cin, str);
    for (int i = 0; i < size; i++) {
        cout << i + 1 << '\t'; getline(cin, str);
        Push(queue, str);
    }
    return queue;
}

void ShowQueue(Queue* queue) {
    if (QueueIsEmpty(queue)) cout << "������� �����!\n";
    else {
        Node* temp = queue->head;
        cout << "---------------------------\n";
        cout << "������ -> ";
        while (temp != nullptr) {
            cout << temp->key << " -> ";
            temp = temp->next;
        }
        cout << "�����\n---------------------------\n";
    }
}

void RemoveElement(Queue* queue, string k) {
    if (QueueIsEmpty(queue)) {
        cout << "������� �����!\n";
        return;
    }
    int i = 1;
    while (i <= queue->size) {
        if (queue->head->key != k) {
            Push(queue, queue->head->key);
            Pop(queue);
            i++;
        }
        else
            Pop(queue);
    }
}

void AddElements(Queue* queue, int count, int number) {
    int i = 1;
    while (i < number) {
        Push(queue, queue->head->key);
        Pop(queue);
        i++;
    }
    string key;
    getline(cin, key);
    for (int j = 1; j <= count; j++) {
        cout << "������� ����� ����: ";
        getline(cin, key);
        Push(queue, key);
    }
    for (i; i <= queue->size - count; i++) {
        Push(queue, queue->head->key);
        Pop(queue);
    }
}

void PrintInFile(string filename, Queue* queue) {
    ofstream fout;
    fout.open(filename);
    if (!fout.is_open()) {
        cout << "�� ������� ������� ����!\n";
    }
    else {
        while (!QueueIsEmpty(queue)) {
            fout << queue->head->key;
            fout << '\n';
            Pop(queue);
        }
    }
    fout.close();
}

void PrintFromFile(string filename, Queue* queue, const int size) {
    ifstream fin;
    fin.open(filename);
    string key;
    if (!fin.is_open()) {
        cout << "�� ������� ������� ����!\n";
    }
    else {
        for (int i = 1; i <= size; i++) {
            fin >> key;
            Push(queue, key);
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
