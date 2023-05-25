#pragma once


void Show(priority_queue<Pair> q);

Pair SearchMidVal(priority_queue<Pair>& q);

void DelElem(priority_queue<Pair>& q);

void plusMinMax(priority_queue<Pair>& q);

/*
� ������� � ���������� ��� ����������, � ����� � ��� �� ����� �����������������
������� �� ���������� algorithm, ������ ��� ��� �������� �� ���, ��� ��� ��������
� �����������. ������� ������, ������� ������� � �������� ����� 15 ���������� ���������
��������, ������� ����������. ���� ������-���� �������� ������������ ������� ��� ���� ��
�����������.
����� ������� ������ �������!!!
������� ���������� ������� ������� �� ������������ ������ ����� 11 - �� ��� �����.
*/


void number2()			//��� � ���� �� ���� ���������. ���� ����� ���������, �� ���� � 11 ���� ��� ��� 4 ������
{						//������ ����, ��� ����� ���� ����� ���������
	Pair temp;			//������������ �������
	priority_queue<Pair> pq;	//� ��� ���� ��������� ���
	int size;
	cout << "������� ���������� ��������� � �������: "; cin >> size;
	for (int i = 0; i < size; i++)
		pq.push(temp.randomGener());
	cout << "���������� �������:" << endl;
	Show(pq);
	cout << "������� ������� �������������� �������� �������:" << endl;
	pq.push(SearchMidVal(pq));
	cout << "���������� �������:" << endl;
	Show(pq);
	cout << "������ ������� �� ��������." << endl;
	DelElem(pq);
	cout << "���������� �������:" << endl;
	Show(pq);
	cout << "������� ����� min � max ��������� � ������� ��������." << endl;
	plusMinMax(pq);
	cout << "���������� �������:" << endl;
	Show(pq);
	return;
}



void Show(priority_queue<Pair> q)
{
	int j = 0;
	while (!q.empty())
	{
		cout << j++ << ". " << q.top() << endl;
		q.pop();
	}
}


Pair SearchMidVal(priority_queue<Pair>& q)
{
	priority_queue<Pair> temp(q);
	Pair mid = 0;
	while (!temp.empty())
	{
		mid = mid + temp.top();
		temp.pop();
	}
	return mid / q.size();
}


void DelElem(priority_queue<Pair>& q)
{
	Pair key, k;
	priority_queue<Pair> temp;
	cout << "������� ���� ��� ������: "; cin >> key;
	while (!q.empty())
	{
		k = q.top();
		if (key == k)
			q.pop();
		else

		{
			temp.push(k);
			q.pop();
		}
	}
	q.swap(temp);
}

void plusMinMax(priority_queue<Pair>& q)
{
	Pair k;
	Pair loc_min = q.top(), loc_max = 0;
	priority_queue<Pair> temp(q);
	while (!temp.empty())
	{
		k = temp.top();
		if (loc_max < k)
		{
			loc_max = k;
			temp.pop();
		}
		else if (loc_min > k)
		{
			loc_min = k;
			temp.pop();
		}
		else temp.pop();
	}
	cout << "min element: " << loc_min << endl;
	cout << "max element: " << loc_max << endl;
	temp.swap(q);
	while (!temp.empty())
	{
		k = temp.top();
		q.push(k + loc_min + loc_max);
		temp.pop();
	}
}