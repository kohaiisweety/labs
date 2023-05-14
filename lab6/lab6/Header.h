// Header file: List.h
#ifndef LIST_H
#define LIST_H

#include <iostream>

class List {
public:
	// Inner class Node
	class Node {
	public:
		Node(int value, Node* next = nullptr) : value_(value), next_(next) {}
		int getValue() const { return value_; }
		Node* getNext() const { return next_; }
		void setNext(Node* next) { next_ = next; }
	private:
		int value_;
		Node* next_;
	};
	// Constructor and destructor
	List();
	List(const List& other);
	~List();

	// Assignment operator
	List& operator=(const List& other);

	// Input and output operators
	friend std::ostream& operator<<(std::ostream& os, const List& list);
	friend std::istream& operator>>(std::istream& is, List& list);

	// Index operator
	int operator[](int index) const;

	// Size method
	int size() const;

	// Multiply operator
	friend int operator*(const List& a, const List& b);

	// Iterator class
	class Iterator {
	public:
		Iterator(Node* node = nullptr) : node_(node) {}
		int operator*() const { return node_->getValue(); }
		Iterator operator+(int n) const;
		Iterator& operator++();
		bool operator==(const Iterator& other) const { return node_ == other.node_; }
		bool operator!=(const Iterator& other) const { return !(*this == other); }
	private:
		Node* node_;
	};

	// Begin and end methods for iterator
	Iterator begin() const { return Iterator(head_); }
	Iterator end() const { return Iterator(nullptr); }
private:
	Node* head_;
};

#endif // LIST_H