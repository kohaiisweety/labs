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

    //перегруженные операции ввода-вывода
    friend ostream& operator<< (ostream& out, const Pair&);
    friend istream& operator>> (istream& in, Pair&);

    //операция умножения на число
    Pair operator*(const double k) const;
    //операция сложения
    Pair operator+(const Pair& p) const;
    //операция вычитания
    Pair operator-(const Pair& p) const;
    //операция умножения
    Pair operator*(const Pair& p) const;
    //операция деления
    Pair operator/(const Pair& p) const;
    // функция доступа по индексу
    Pair& operator[](int index);
public:
    virtual ~Pair(void) {};
private:
    int first;
    double second;
};
