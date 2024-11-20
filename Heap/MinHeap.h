
#pragma once


template<typename _Type>
class MinHeap {
private:

	_Type* m_array;
	size_t m_size;
	size_t m_capacity;

private:

	//Making a dynamic array
	void reallocation() {
		_Type* temp = new _Type[m_capacity];
		m_capacity *= 2;

		for (int i = 0; i < m_size; i++) {
			temp[i] = m_array[i];
		}

		delete[] m_array;

		m_array = new _Type[m_capacity];

		for (int i = 0; i < m_size; i++) {
			m_array[i] = temp[i];
		}
		delete[] temp;
	}

	//return index of parent
	int parent(const int& index) {
		return ((index - 1) / 2);
	}

	//index of left child
	int leftChild(const int& index) {
		return ((index * 2) + 1);
	}

	//index of right child
	int rightChild(const int& index) {
		return ((index * 2) + 2);
	}

	void swap(_Type& first, _Type& second) {
		_Type temp;
		temp = first;
		first = second;
		second = temp;
	}

	//sort the element from smallest to largest
	void minHeapSort(const int& index) {
		int smallest = index;

		while (smallest == index) {

			if (m_size > 1 && m_array[smallest] > m_array[leftChild(index)]) {
				smallest = leftChild(index);
			}
			if (m_size > 1 && m_array[smallest] > m_array[rightChild(index)]) {
				smallest = rightChild(index);
			}
			if (smallest != index) {
				swap(m_array[index], m_array[smallest]);
			}
			else break;
		}
	}
public:

	MinHeap()
		:m_size(0), m_capacity(10) {
		m_array = new _Type[m_capacity];
	}

	void push(const _Type& data) {
		if (m_size == m_capacity)
		{
			reallocation();
		}

		m_array[m_size++] = data;

		int tempSize = m_size - 1;

		//sort if the new data is smaller than its parent
		while (m_size > 1 && m_array[parent(tempSize)] > m_array[tempSize]) {
			swap(m_array[tempSize], m_array[parent(tempSize)]);
			tempSize = parent(tempSize);
		}

	}

	_Type& pop() {
		if (!isEmpty()) {

			if (m_size == 1) {
				return m_array[0];
			}
			_Type root = m_array[0];
			m_array[0] = m_array[m_size - 1];
			m_size--;
			minHeapSort(0);
			return root;
		}
	}

	void print() {
		for (int i = 0; i < m_size;i++) {
			std::cout << m_array[i] << std::endl;
		}
	}

	size_t size() {
		return m_size;
	}

	_Type peek() {
		return m_array[0];
	}

	bool isEmpty() {
		return m_size == 0;
	}
	~MinHeap() {
		delete[] m_array;
	}
};
