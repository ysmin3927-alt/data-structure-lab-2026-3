#include "ArrayStack.h" //ArrayStack 클래스 포함
#include <string.h>
#include <iostream>
using namespace std;

void main()
{
	int choice;
	ArrayStack stack; 
	for (int i = 1; i < 5; i++) {
		//stack.push(i);
		cin >> choice;
		stack.push(choice);
	}
	stack.display();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.display();

}