#include <iostream>
#include "Array/staticArray.h"


int main() {
	Array<int, 10> arr;
	for (int i = 0; i < 10; i++) {
		arr[i] = i + 1;
	}

	for (int i = 0; i < arr.size() ; i++) {
		std::cout << arr[i] << std::endl;
	}

	std::cout << "====================\n";

	arr.reverse();

	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << std::endl;
	}

}
