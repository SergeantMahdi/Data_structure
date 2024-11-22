#include <iostream>
#include <array>
#include "Array/staticArray.h"


int main() {

	Array<int, 15> arr;
	arr[0] = 1;
	arr[1] = 2;

	std::cout << "Size: " << arr.size() << std::endl;

	arr.fill(10);

	std::cout << "\n+===============+\n";
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << std::endl;
	}
	std::cout << "Size: " << arr.size() << std::endl;
	arr.replace(1, 10);
	std::cout << "\n+===============+\n";
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << std::endl;
	}
	std::cout << "Size: " << arr.size() << std::endl;
}
