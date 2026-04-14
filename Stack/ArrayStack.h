#pragma once
#include <stdio.h>
#include <cstdlib>
#include <iostream>


const int MAX_STACK_SIZE = 20;

class ArrayStack
{
	int top; //요소의 개수
	int data[MAX_STACK_SIZE];

public:
	ArrayStack() { top = -1; }
	~ArrayStack(){}
	bool isEmpty() { return top == -1; }
	bool isFull() { return top == MAX_STACK_SIZE - 1; }
	
	inline void error(const char* message) { //const 추가
		printf("%s\n", message);
		exit(1);
	}

	void push(int e) {
		if (isFull()) error("스택 포화 에러");//stack이 full인경우
		data[++top] = e;//full이 아닌경우
	}
	int pop() {
		if (isEmpty()) error("스택 공백 에러");
		return data[top--];
	}
	int peek() {
		if (isEmpty()) error("스택 공백 에러");
		return data[top];
	}
	void  display() {
		printf("[스택 항목의 수 = %2d] ==> ", top + 1);
		for (int i = 0; i <= top; i++) {
			printf("<%2d>", data[i]);
			printf("\n");
		}
	}
	
};