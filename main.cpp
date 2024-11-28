#include <iostream>
#include "Stack/stack.h"

int main() {
	Stack<int> stack;

	stack.push(10);
	stack.push(60);
	stack.push(450);
	stack.push(130);
	stack.push(1);


	if (stack.search(60)) {
		std::cout << 60 << " exits\n";
	}
	else {
		std::cout << 60 << " doesn't exit\n";
	}

	while(!stack.isEmpty()) {
		std::cout << stack.pop() << std::endl;
	}

}
