#include "Student.h" 
#include <iostream>
using namespace std;

int main() // void main보다는 int main이 표준입니다.
{
    int id;
    char name[MAX_STRING], dept[MAX_STRING];
    StudentStack stack; // 아까 만든 스택 클래스 이름

    // 1. 데이터 입력받아 push 하기
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << "번째 학생 정보 입력(학번 이름 학과): ";
        cin >> id >> name >> dept;

        Student s(id, name, dept); // 입력받은 정보로 학생 객체 생성
        stack.push(s);             // 스택에 학생 객체 삽입
    }

    cout << "\n--- 현재 스택 상태 ---" << endl;
    stack.display();

    // 2. pop 연산 수행
    cout << "\n--- 데이터 꺼내기(Pop) 시작 ---" << endl;
    while (!stack.isEmpty()) { // 스택이 빌 때까지 안전하게 pop
        Student s = stack.pop();
        cout << "꺼낸 데이터 -> ";
        s.display();
    }

    cout << "\n--- 최종 스택 상태 ---" << endl;
    stack.display();

    return 0;
}