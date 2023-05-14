// Implementation file: List.cpp
#include "Header.h"

// Constructor
List::List() : head_(nullptr) {}

// Copy constructor
List::List(const List& other) {
	if (other.head_ == nullptr) {
		head_ = nullptr;
	}
	else {
		head_ = new Node(other.head_->getValue());
		Node* thisNode = head_;
		Node* otherNode = other.head_->getNext();
		while (otherNode != nullptr) {
			thisNode->setNext(new Node(otherNode->getValue()));
			thisNode = thisNode->getNext();
			otherNode = otherNode->getNext();
		}
	}
}

// Destructor
List::~List() {
	while (head_ != nullptr) {
		Node* temp = head_;
		head_ = head_->getNext();
		delete temp;
	}
}

// Assignment operator
List& List::operator=(const List& other) {
	if (this != &other) {
		List temp(other);
		std::swap(head_, temp.head_);
	}
	return *this;
}

// Output operator
std::ostream& operator<<(std::ostream& os, const List& list) {
	List::Node* current = list.head_;
	while (current != nullptr) {
		os << current->getValue() << " ";
		current = current->getNext();
	}
	return os;
}

// Input operator
std::istream& operator>>(std::istream& is, List& list) {
	int size, i = 0;
	std::cout << "Enter size: "; std::cin >> size;
	int value;
	while (i++ < size) {
		is >> value;
		list.head_ = new List::Node(value, list.head_);
	}
	return is;
}

// Index operator
int List::operator[](int index) const {
	Node* current = head_;
	for (int i = 0; i < index; ++i) {
		current = current->getNext();
		if (current == nullptr) {
			throw std::out_of_range("Index out of range");
		}
	}
	return current->getValue();
}

// Size method
int List::size() const {
	int count = 0;
	Node* current = head_;
	while (current != nullptr) {
		++count;
		current = current->getNext();
	}
	return count;
}

// Multiply operator
int operator*(const List& a, const List& b) {
	if (a.size() != b.size()) {
		throw std::invalid_argument("Lists must have the same size");
	}
	int result = 0;
	List::Node* currentA = a.head_;
	List::Node* currentB = b.head_;
	while (currentA != nullptr) {
		result += currentA->getValue() * currentB->getValue();
		currentA = currentA->getNext();
		currentB = currentB->getNext();
	}
	return result;
}

// Iterator methods
List::Iterator List::Iterator::operator+(int n) const {
	Iterator result(node_);
	for (int i = 0; i < n; ++i) {
		++result;
	}
	return result;
}

List::Iterator& List::Iterator::operator++() {
	if (node_ != nullptr) {
		node_ = node_->getNext();
	}
	return *this;
}