#pragma once

template<typename _Type, size_t _Capacity>
class Array {

private:
	_Type m_array[_Capacity];
	size_t m_size;
private:
	void outOfBoundary_excep() {
		try {
			throw std::length_error("the index is out of boundary");
		}
		catch (const std::exception& error) {
			std::cerr << "Access Violation: " << error.what() << std::endl;
			std::exit(0);
		}
	}

	void swap(_Type& first, _Type& second) {
		_Type temp = first;
		first = second;
		second = temp;
	}
public:

	Array()
		:m_size(0){}


	size_t size() {
		return m_size;
	}

	void add(const _Type data) {
		if (m_size >= _Capacity) {
			std::cout << "the array is full!";
			return;
		}
		m_array[m_size++] = data;
	}

	void replace(const _Type& data, const _Type& target) {
		for (int i = 0; i < m_size; i++) {
			if (m_array[i] == target) {
				m_array[i] = data;
			}
		}
	}

	void fill(const _Type& data) {
		for (int i = m_size; i < _Capacity; i++) {
				m_array[i] = data;
				m_size++;
		}
	}

	void reverse() {

		//Reverse operation in time complexity of O(Log n)

		size_t s = m_size - 1;

		for (int i = 0; i < m_size / 2; i++) {
			swap(m_array[i], m_array[s]);
			s--;
		}
	}

	_Type& operator[](const int& index) {
		if(index > _Capacity){
			outOfBoundary_excep();
		}


		if (index >= m_size) {
			m_size++;
		}
		return m_array[index];
	}
};