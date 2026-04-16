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
        cout << i + 1 << "번째 학생 정보 입력(학번 이름 학과): "; //학생 정보 입력
        cin >> id >> name >> dept;  //학번 이름 학과  각 변수 명에 저장

        Student s(id, name, dept); // 입력받은 정보로 학생 객체 생성
        stack.push(s);             // 스택에 학생 객체 삽입
    }

    cout << "\n--- 현재 스택 상태 ---" << endl;
    stack.display(); //stack.display(); 하면 stack안에 쌓인게 다 출력이 되네.

    // 2. pop 연산 수행
    cout << "\n--- 데이터 꺼내기(Pop) 시작 ---" << endl;
    while (!stack.isEmpty()) { // 스택이 빌 때까지 안전하게 pop
        Student s = stack.pop();
        cout << "꺼낸 데이터 -> ";
        s.display();
    }
    cout << "\n--- 최종 스택 상태 ---" << endl;
    stack.display();

    cout << "\n[알림] 이제 스택이 비었습니다. 에러를 확인하기 위해 한 번 더 pop합니다." << endl;
    stack.pop();

 
    return 0;
}