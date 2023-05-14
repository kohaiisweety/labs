#pragma once
#include"header.h"

void plus_mid2(multiset<Pair>& mlst)	//���������� � ��������� �������� �� ������� �������������� ���������
{
	Pair midl = 0;
	for (auto& i : mlst)
		midl = midl + i;
	mlst.insert(midl / mlst.size());
}

void searchAndDel2(multiset<Pair>& mlst)	//����� � �������� ������ � �������� ���������
{
	Pair min, max;
	cout << "������� �������� ��� ������ (Pair):\n" << "min: "; cin >> min;
	cout << "max: "; cin >> max;
	auto left = mlst.lower_bound(min);
	auto right = mlst.upper_bound(max);
	mlst.erase(left, right);
}

void plusMinMax2(multiset<Pair>& mlst)		//����������� ������� �������� ������������� � ������������ ���������
{
	multiset<Pair> temp;
	Pair min = *mlst.begin(), max = *mlst.begin();
	for (auto& i : mlst)			//��� ���� �������� ������
	{								//������ ��� ���� ������� � ��������
		if (i < min) min = i;
		if (!(i < max)) max = i;
	}
	for (auto& i : mlst)			//������ ��� ���������� ����� multiset
		temp.insert(i + min + max);
	mlst.swap(temp);			//������ ������ � multiset��
}

void number2()
{
	Pair pr;
	multiset<Pair> mlst;
	int n;
	cout << "������� ����� ���������� ������� �������������: "; cin >> n;
	for (int i = 0; i < n; i++)		//���������� ���������� ����������� �������
		mlst.insert(pr.randomGener());
	cout << endl << "���������� multiset:" << endl; n = 0;
	for (auto& i : mlst)			//����� 
		cout << ++n << ". " << i << endl;
	cout << endl << "������ ������� �������������� �������� � ������� ��� � ���������." << endl;
	plus_mid2(mlst);			//���������� �������� �� ������� ��������������
	cout << endl << "���������� multiset:" << endl; n = 0;
	for (auto& i : mlst)			//����� 
		cout << ++n << ". " << i << endl;
	cout << endl << "������� �������� � ������ ������ �� ���������� � ������ ���������." << endl;
	searchAndDel2(mlst);			// ����� � �������� ��������� � �������� ���������
	cout << endl << "���������� multiset:" << endl; n = 0;
	for (auto& i : mlst)			//����� 
		cout << ++n << ". " << i << endl;
	cout << endl << "� ������� �������� ���������� ������� max � min ������� ����������." << endl;
	plusMinMax2(mlst);				//����� ������������� � ������������ � ���������� � ������� ��������
	cout << endl << "���������� multiset:" << endl; n = 0;
	for (auto& i : mlst)			//����� 
		cout << ++n << ". " << i << endl;
}