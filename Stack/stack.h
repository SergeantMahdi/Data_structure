#pragma once

#include <iostream>

template<typename _Type>
struct Node {
	_Type data;
	Node<_Type>* nextElement;

	Node()
		:data(nullptr), nextElement(nullptr) {}

	Node(const _Type& data)
		:data(data), nextElement(nullptr) {}
};

template<typename _Type>
class Stack {
private:
	Node<_Type>* m_head;
	size_t m_size;

private:
	

public:
	Stack()
		:m_head(nullptr), m_size(0) {}
	void push(_Type&& data) {
		Node<_Type>* newNode = new Node<_Type>(data);

		if (m_head == nullptr) {
			m_head = newNode;
			m_size++;
			return;
		}

		newNode->nextElement = m_head;
		m_head = newNode;
		m_size++;
	}

	_Type pop() {
		try {
			if (m_head == nullptr || m_size == 0) {
				throw std::runtime_error("Stack is empty!");
			}
		}
		catch (const std::runtime_error& err) {
			std::cout << "Access Violation: " << err.what() << std::endl;
			return _Type();
		}

		Node<_Type>* temp = m_head;
		_Type data = temp->data;
		m_head = m_head->nextElement;
		delete temp;
		m_size--;
		return data;
	}

	bool search(const _Type& data) {
		try {
			if (m_head == nullptr || m_size == 0) {
				throw std::runtime_error("Stack is empty!");
			}
		}
		catch (const std::runtime_error& err) {
			std::cout << "Access Violation: " << err.what() << std::endl;
			return false;
		}
		Node<_Type>* temp = m_head;

		while (temp != nullptr) {
			if (temp->data == data) {
				return true;
			}
			temp = temp->nextElement;
		}
		return false;
	}

	const size_t size() const {
		return m_size;
	}

	const bool isEmpty() const {
		return m_size == 0;
	}

};