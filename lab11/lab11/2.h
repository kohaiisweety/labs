#pragma once
#include "Header.h"

void number_2()
{
	list<Pair> lst;
	Pair temp;
	int size;
	cout << "������� ���������� ��������� � ������: "; cin >> size;
	for (int i = 0; i < size; i++)
		lst.push_back(temp.randomGener());
	cout << "���������� ������:" << endl;
	Show(lst);
	cout << "������� ������� �������������� �������� ������ � ����� �����:" << endl;
	lst.push_back(SearchMidVal(lst));
	cout << "���������� ������:" << endl;
	Show(lst);
	cout << "������ ������� �� �������� � �������� ���������." << endl;
	DelElem(lst);
	cout << "���������� ������:" << endl;
	Show(lst);
	cout << "������� ����� min � max ��������� � ������� ��������." << endl;
	plusMinMax(lst);
	cout << "���������� ������:" << endl;
	Show(lst);
	return;
}