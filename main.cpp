#include <iostream>
#include "Heap/MinHeap.h"


int main() {
	MinHeap<int> heap;

	heap.push(10);
	heap.push(18);
	heap.push(7);
	heap.push(0);
	heap.push(4);
	std::cout << "\nPrint\n";
	heap.print();

	std::cout << "\nPopping\n";
	std::cout << heap.pop() << std::endl;
	std::cout << heap.pop() << std::endl;
	std::cout << heap.pop() << std::endl;
	std::cout << heap.pop() << std::endl;
	std::cout << heap.pop() << std::endl;
}