#include "Vector.h"
#include "Dialog.h"
#include "Event.h"
#include "Magazin.h"
#include "Object.h"
#include "Print.h"
#include <Windows.h>

int main() {
	SetConsoleCP(1251); SetConsoleOutputCP(1251);
	cout << "m: Добавить элемент\n";
	cout << "+: Добавить элемент\n";
	cout << "-: Удалить элемент\n";
	cout << "s: Информация о членах группы\n";
	cout << "z: Информация о названиях элементов группы\n";
	cout << "q: Конец работы\n";
	Dialog D;
	D.Execute();
	return 0;
}