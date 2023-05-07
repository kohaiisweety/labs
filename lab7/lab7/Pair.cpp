#include "Pair.h"

Pair::Pair(void)
{
    first = 0;
    second = 0;
}

Pair::Pair(int f, double s)
{
    first = f;
    second = s;
}

Pair::Pair(const Pair& t)
{
    first = t.first;
    second = t.second;
}

Pair& Pair::operator =(const Pair& t)
{
    first = t.first;
    second = t.second;
    return*this;
}

ostream& operator<<(ostream& out, const Pair& t)
{
    out << t.first << " : " << t.second;
    return out;
}

istream& operator>>(istream& in, Pair& t)
{
    cout << "\nfirst?";
    in >> t.first;
    cout << "\nsecond?";
    in >> t.second;
    return in;
}

Pair Pair::operator*(const double k) const
{
    return Pair(first * k, second * k);
}

Pair Pair::operator+(const Pair& p) const
{
    return Pair(first + p.first, second + p.second);
}

Pair Pair::operator-(const Pair& p) const
{
    return Pair(first - p.first, second - p.second);
}

Pair Pair::operator*(const Pair& p) const
{
    return Pair(first * p.first, second * p.second);
}

Pair Pair::operator/(const Pair& p) const
{
    return Pair(first / p.first, second / p.second);
}

Pair& Pair::operator[](int index)
{
    if (index == 0)
        return *this;
    else {
        cout << "Неверный индекс элемента.\n";
        // Возвращаем ссылку на текущий объект,
        // чтобы избежать ошибок компиляции.
        return *this;
    }
}

