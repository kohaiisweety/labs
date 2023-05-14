#pragma once
#include "Header.h"

template <typename T>
class List
{
private:
	list<T> lst;
	T SearchMidVal();
	int _size;

public:
	List() { _size = 0; }
	List(int n);
	~List() {};
	void Print();
	void PushMidVal();
	void DelElem();
	int size() { return this->_size; }
	void plusMinMax();
};

template<class T>
List<T>::List(int n)
{
	T a;
	cout << "�����: " << endl;
	for (size_t i = 0; i < n; i++)
	{
		cout << i << ". ";
		cin >> a;
		this->lst.push_back(a);
	}
	_size = n;
}

template<class T>
void List<T>::Print()
{
	int j = 0;
	for (const auto& i : lst)
		cout << j++ << ")\t" << i << endl;
}

template<class T>
T List<T>::SearchMidVal()
{
	T mid = 0;
	for (auto& i : lst)
		mid = mid + i;
	return mid / lst.size();
}

template<typename T>
void List<T>::PushMidVal()
{
	lst.push_back(SearchMidVal());
	this->_size = lst.size();
}

template<typename T>
void List<T>::DelElem()
{
	T key;
	int start, end;
	auto it_start = lst.begin(), it_end = lst.begin();
	cout << "������� ���� ��� ������: "; cin >> key;
	cout << "������� �������� ��� ������ (�������) (start : end): "; cin >> start >> end;
	if (start > end) std::swap(start, end);
	std::advance(it_start, start);
	std::advance(it_end, end);
	do
	{
		if (*it_start == key) it_start = lst.erase(it_start);
		else ++it_start;
	} while (it_start != it_end);
	this->_size = lst.size();
}

template<typename T>
void List<T>::plusMinMax()
{
	T loc_min = 0, loc_max = 0;
	for (auto& i : lst)
	{
		if (i < loc_min)
		{
			loc_min = i;
		}
		else if (i > loc_max)
		{
			loc_max = i;
		}
	}
	cout << "min element: " << loc_min << endl;
	cout << "max elem: " << loc_max << endl;
	for (auto& i : lst)
	{
		i = i + loc_min + loc_max;
	}
}


void number_3()
{
	int n;
	cout << "������� ����� ������: "; cin >> n;
	List<Pair> lst(n);
	cout << "���������� ������:" << endl;
	lst.Print();
	cout << "������� ������� �������������� �������� ������ � ����� �����:" << endl;
	lst.PushMidVal();
	cout << "���������� ������:" << endl;
	lst.Print();
	cout << "������ ������� �� �������� � �������� ���������." << endl;
	lst.DelElem();
	cout << "���������� ������:" << endl;
	lst.Print();
	cout << "������� ����� min � max ��������� � ������� ��������." << endl;
	lst.plusMinMax();
	cout << "���������� ������:" << endl;
	lst.Print();
}