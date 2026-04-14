#pragma once
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string.h>

#define MAX_STRING 20

class Student {
    int id;
    char name[MAX_STRING];
    char dept[MAX_STRING];
public:
    Student(int i = 0, const char* n = "", const char* d = "") {
        set(i, n, d);
    }
    void set(int i, const char* n, const char* d) {
        id = i;
        strcpy_s(name, n);
        strcpy_s(dept, d);
    }
    void display() {
        printf("학번: %-15d 성명: %-10s 학과: %-20s\n", id, name, dept);
    }
};

const int MAX_STACK_SIZE = 100;

class StudentStack {
    int top;
    Student data[MAX_STACK_SIZE]; // Student 객체를 담는 배열

public:
    StudentStack() { top = -1; }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX_STACK_SIZE - 1; }

    void error(const char* message) {
        printf("%s\n", message);
        exit(1);
    }

    void push(Student e) {
        if (isFull()) error("스택 포화 에러");
        data[++top] = e;
    }

    Student pop() { // 반환형을 int가 아닌 Student로!
        if (isEmpty()) error("스택 공백 에러");
        return data[top--];
    }

    void display() {
        printf("[스택 항목의 수 = %2d]\n", top + 1);
        for (int i = 0; i <= top; i++) {
            data[i].display(); // 각 학생의 display 호출
        }
    }
};