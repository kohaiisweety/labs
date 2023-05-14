#pragma once
#include"header.h"


void plus_mid(multiset<double>& mlst)
{
	double midl = 0;
	for (auto& i : mlst)
		midl += i;
	mlst.insert(midl / mlst.size());
}

void searchAndDel(multiset<double>& mlst)
{
	double min, max;
	cout << "������� �������� ��� ������:\n" << "min: "; cin >> min;
	cout << "max: "; cin >> max;
	auto left = mlst.lower_bound(min);
	auto right = mlst.upper_bound(max);
	mlst.erase(left, right);
}

void plusMinMax(multiset<double>& mlst)
{
	multiset<double> temp;
	double min = *mlst.begin(), max = *mlst.begin();
	for (auto& i : mlst)
	{
		if (i < min) min = i;
		if (i > max) max = i;
	}
	for (auto& i : mlst)
		temp.insert(i + min + max);
	mlst.swap(temp);
}

void number1()
{
	multiset<double> mlst;
	int n;
	cout << "������� ����� ���������� ������� �������������: "; cin >> n;
	for (int i = 0; i < n; i++)
		mlst.insert((double((rand() % 10000))) / 100 - 50);
	cout << endl << "���������� multiset:" << endl; n = 0;
	for (auto& i : mlst)
		cout << ++n << ". " << i << endl;
	cout << endl << "������ ������� �������������� �������� � ������� ��� � ���������." << endl;
	plus_mid(mlst);
	cout << endl << "���������� multiset:" << endl; n = 0;
	for (auto& i : mlst)
		cout << ++n << ". " << i << endl;
	cout << endl << "������� �������� � ������ ������ �� ���������� � ������ ���������." << endl;
	searchAndDel(mlst);
	cout << endl << "���������� multiset:" << endl; n = 0;
	for (auto& i : mlst)
		cout << ++n << ". " << i << endl;
	cout << endl << "� ������� �������� ���������� ������� max � min ������� ����������." << endl;
	plusMinMax(mlst);
	cout << endl << "���������� multiset:" << endl; n = 0;
	for (auto& i : mlst)
		cout << ++n << ". " << i << endl;
}

