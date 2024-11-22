#include <iostream>
#include <array>
#include "Array/staticArray.h"


int main() {

	Array<int, 10> arr;
	arr.fill(10);

	std::cout << "\n+===============+\n";
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << std::endl;
	}

	arr.replace(100, 1);
	std::cout << "\n+===============+\n";
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << std::endl;
	}
}
