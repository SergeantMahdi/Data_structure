#pragma once
//Time Complexity:
//push: O(1) Remove: O(N)  traverse: O(N)
template<typename _Type>
struct Node {
	_Type data;
	Node<_Type>* nextElement;

	Node()
		:data(nullptr), nextElement(nullptr){}

	Node(const _Type& input)
		:data(input), nextElement(nullptr) {}
};

template<typename _Type>
class Linked_List {
private:
	Node<_Type>* m_head;
	size_t m_size;

public:

	Linked_List()
		:m_head(nullptr), m_size(0){}

	void push(const _Type& data) {

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


	void remove(const _Type& data) {
		if (m_size == 0) {
			std::cout << "Linked list is empty\n";
			return;
		}

		Node<_Type>* temp = m_head;

		while (temp != nullptr ) {
			
			Node<_Type>* target;

			//check if data of the next element is equal to our target data
			if (temp->nextElement->data == data) {

				//set target to target node
				target = temp->nextElement;

				//we set the nexElement of the current node to the next element of the target node
				//to avoid data loss
				temp->nextElement = temp->nextElement->nextElement;

				m_size--;
				delete target;
				return;
			}
			temp = temp->nextElement;
		}

	}

	size_t size() {
		return m_size;
	}

	void clear() {
		if (m_size == 0) {
			std::cout << "Linked list is empty\n";
			return nullptr;
		}
		Node<_Type>* temp = m_head;

		while (temp != nullptr) {
			m_head = m_head->nextElement;
			delete temp;
			temp = m_head;
			m_size--;
		}
	}

	void print() {
		//a showcase of how to traverse through linked-list

		Node<_Type>* temp = m_head;

		while (temp != nullptr) {
			std::cout << temp->data << std::endl;
			temp = temp->nextElement;
		}
	}

};