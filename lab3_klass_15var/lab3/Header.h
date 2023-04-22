#pragma once
#include <iostream>
using namespace std;

class Pair {
	int one;
	double two;
public:
	Pair() { one = 0; two = 0; }
	Pair(int n, double m) { one = n; two = m; }
	Pair(const Pair& t) { one = t.one; two = t.two; }
	int get_one() { return one; }
	double get_two() { return two; }
	void set_one(int n) { one = n; }
	void set_two(double m) { two = m; }
	Pair& operator=(const Pair&);
	friend istream& operator>>(istream& in, Pair& t);
	friend ostream& operator<<(ostream& out, const Pair& t);
	Pair operator-(const Pair& t);
	Pair operator+(const double& d);
	Pair operator+(const int& n);
};
