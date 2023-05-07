#include "Vector.h"

Vector::Vector() {
	beg = nullptr;
	size = 0;
	cur = 0;
}

Vector::~Vector(void) {
	if (beg != 0) delete[] beg;
	beg = 0;
}

Vector::Vector(int n) {
	beg = new Object * [n];
	cur = 0;
	size = n;
}

void Vector::Get_Name() {
	Object** p = beg;
	for (int i = 0; i < cur; i++) {
		cout << (*p)->Get_name() << endl;
		p++;
	}
}

void Vector::Add() {
	Object* p;
	cout << "1.Print" << endl;
	cout << "2.Magazin" << endl;
	int y;
	cin >> y;
	if (y == 1) { 
		Print* a = new (Print);
		a->Input();
		p = a;
		if (cur < size) {
			beg[cur] = p; 
			cur++;
		}
	}
	else if (y == 2) { 
		Magazin* b = new Magazin;
		b->Input();
		p = b;
		if (cur < size) {
			beg[cur] = p;
			cur++;
		}
	}
	else return;
}

void Vector::Show() {
	if (cur == 0) cout << "Empty" << endl;
	Object** p = beg;  
	for (int i = 0; i < cur; i++) {
		(*p)->Show(); 
		p++;  
	}
}

int Vector::operator ()() {
	return cur;
}

void Vector::Del() {
	if (cur == 0) return;
	cur--;
}