#pragma once
#include"header.h"

void number3()
{
	Pair pr;
	List<Pair> mlst;
	int n;
	cout << "������� ����� ���������� ������� �������������: "; cin >> n;		//���������� ������ ����������� �������
	for (int i = 0; i < n; i++)
		mlst.add(pr.randomGener());
	cout << endl << "���������� list:" << endl;
	mlst.print();	//����� 
	cout << endl << "������ ������� �������������� �������� � ������� ��� � ���������." << endl;
	mlst.plus_mid();	//���������� �������� �� ������� ��������������
	cout << endl << "���������� list:" << endl;
	mlst.print();		//�����
	cout << endl << "������� �������� � ������ ������ �� ���������� � ������ ���������." << endl;
	mlst.searchAndDel();	//����� � �������� ��������� � ���������
	cout << endl << "���������� list:" << endl;
	mlst.print();		//�����
	cout << endl << "� ������� �������� ���������� ������� max � min ������� ����������." << endl;
	mlst.plusMinMax();	//����� ������������� � ������������, ��� ���������� � ������� ��������
	cout << endl << "���������� list:" << endl;
	mlst.print();		//�����
}