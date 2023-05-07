#pragma once
#include <iostream> 
using namespace std; 
class Pair
{
public:
    Pair(void);
    Pair(int, double);
    Pair(const Pair&);
    Pair& operator=(const Pair&);

    //������������� �������� �����-������
    friend ostream& operator<< (ostream& out, const Pair&);
    friend istream& operator>> (istream& in, Pair&);

    //�������� ��������� �� �����
    Pair operator*(const double k) const;
    //�������� ��������
    Pair operator+(const Pair& p) const;
    //�������� ���������
    Pair operator-(const Pair& p) const;
    //�������� ���������
    Pair operator*(const Pair& p) const;
    //�������� �������
    Pair operator/(const Pair& p) const;
    // ������� ������� �� �������
    Pair& operator[](int index);
public:
    virtual ~Pair(void) {};
private:
    int first;
    double second;
};
