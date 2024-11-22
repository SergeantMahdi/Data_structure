#include <iostream>
#include "Linked-List/singlyLinkedList.h"


int main() {
	Linked_List<int> list;
	list.push(10);
	list.push(20);
	list.push(0);
	list.push(19);
	list.push(16);

	list.print();
	std::cout << "\n============\n";
	list.remove(0);
	list.print();
}
