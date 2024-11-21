#pragma once
//Note: vector is a dynamic array in standard library
/*Time complexity:
*push_back & emplace_back: O(1)
* pop_back: O(1)
* contains: O(N)
* at: O(1)
* clear: O(1);
*/
template<typename _Type>
class DynamicArray {
private:
	_Type* m_array;
	//size of the array
	size_t m_size;
	//capacity of the entire array
	size_t m_capacity;

private:

	void realloc() {
		std::cout << "\nreallocation\n";
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

	void outOfBoundary_excep() {
		try {
			throw std::length_error("the index is out of boundary");
		}
		catch (const std::exception& error) {
			std::cerr << "Access Violation: " << error.what() << std::endl;
			std::exit(0);
		}
	}

public:
	//capacity set to 10 to avoid re-allocating memory for the first 10 elements
	DynamicArray()
		:m_size(0), m_capacity(10) {
		m_array = new _Type[m_capacity];
	}

	void push_back(const _Type& data) {
		if (m_size == m_capacity)
			realloc();

		m_array[m_size++] = data;
	}

	void emplace_back(_Type&& data) {
		if (m_size == m_capacity)
			realloc();

		m_array[m_size++] = std::move(data);
	}
	void pop_back() {
		m_array[m_size--] = 0;
	}

	size_t size() {
		return m_size;
	}

	bool isEmpty() {
		return m_size == 0;
	}

	void clear() {
		delete[] m_array;
		m_size = 0;

		m_array = new _Type[m_capacity];
	}

	bool contains(const _Type& data) {
		for (int i = 0; i < m_size; i++) {
			if (m_array[i] == data)
				return true;
		}
		return false;
	}

	_Type& at(const _Type& index) {
		if (index >= m_size) {
			outOfBoundary_excep();
		}
		return m_array[index];
	}
	_Type& operator[](const int& index) {
		if (index >= m_size) {
			outOfBoundary_excep();
		}
		return m_array[index];
	
	}


};