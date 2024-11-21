#include <iostream>
#include "Array/dynamicArray.h"


int main() {

	DynamicArray<int> data;
	data.push_back(10);

	data.emplace_back(2);

	for (int i = 0; i < data.size(); i++) {
		std::cout << data[i] << std::endl;
	}

	data.pop_back();

	for (int i = 0; i < data.size(); i++) {
		std::cout << data[i] << std::endl;
	}

	data.clear();

	if (data.isEmpty()) {
		std::cout << "Empty\n";
	}
	
}
