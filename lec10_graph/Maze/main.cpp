#include "Location2D.h"
//#include <stack>
#include <deque>
// 앞과 뒤 모두에서 삽입/삭제 자유로운 구조 
#include<cstdio>
using namespace std;

// 미로 크기 정의 (const int 띄어쓰기 수정)
const int MAZE_SIZE = 6;

// 미로 맵 데이터
// 0: 갈 수 있는 길, 1: 벽, x: 출구, e: 입구
char map[MAZE_SIZE][MAZE_SIZE] = {
    {'1', '1', '1', '1', '1', '1'},
    {'e', '0', '1', '0', '0', '1'},
    {'1', '0', '0', '0', '1', '1'},
    {'1', '0', '1', '0', '1', '1'},
    {'1', '0', '1', '0', '0', 'x'},
    {'1', '1', '1', '1', '1', '1'},
};

// (r, c)가 갈 수 있는 위치인지 검사하는 함수
bool isValidLoc(int r, int c)
{
    // 1. 미로 배열의 범위를 벗어나는지 먼저 체크 (Boundary Check)
    if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE) {
        return false;
    }

    // 2. 범위를 벗어나지 않았다면, 갈 수 있는 길('0')이거나 출구('x')인지 확인
    return map[r][c] == '0' || map[r][c] == 'x';
}
/*
int main() { // BFS는 FIFO를 사용
    deque<Location2D> locDeque;          // 위치 덱 객체 생성 // STL의 deque 템플릿 파일 포함
    Location2D entry(1, 0);             // 입구 객체
    locDeque.push_front(entry);          // 덱에 입구 위치 삽입

    while (locDeque.empty() == false) { // 덱이 비어있지 않은 동안
        Location2D here = locDeque.front(); // 덱의 맨 앞(가장 오래된 객체) 꺼내기
        locDeque.pop_front();               // 덱 맨 앞 객체 삭제 (FIFO 구조)

        int r = here.row;
        int c = here.col;

        // 💡 [추가] 그림의 큐에서 '삭제'되어 현재 방문하는 위치를 화면에 찍어줍니다!
        printf("(%d,%d) ", r, c);

        if (map[r][c] == 'x') {          // 출구에 도달했다면 탐색 성공
            printf("BFS 미로 탐색 성공!\n"); // 그림처럼 최종 출구 도달 표시
            return 0;
        }
        else {                           // 출구가 아니면 현재 위치를
            map[r][c] = '.';             // 현재 위치를 "지나옴" 처리

            // 💡 그림의 큐 삽입 순서와 완벽히 똑같이 연동되도록 상-하-좌-우 순서 유지
            if (isValidLoc(r - 1, c)) locDeque.push_back(Location2D(r - 1, c)); // 상
            if (isValidLoc(r + 1, c)) locDeque.push_back(Location2D(r + 1, c)); // 하
            if (isValidLoc(r, c - 1)) locDeque.push_back(Location2D(r, c - 1)); // 좌
            if (isValidLoc(r, c + 1)) locDeque.push_back(Location2D(r, c + 1)); // 우
        }
    }
    printf("미로 탐색 실패\n");
    return 0;
}
*/




int main() {
    deque<Location2D> locDeque;          // 위치 덱 객체 생성 // STL의 deque 템플릿 파일 포함
    Location2D entry(1, 0);             // 입구 객체
    locDeque.push_front(entry);       // 덱에 입구 위치 삽입

    while (locDeque.empty() == false) { // 덱이 비어있지 않은 동안
        Location2D here = locDeque.front(); // 덱의 front 상단 객체 복사
        locDeque.pop_front();               // 덱 상단 객체 삭제

        int r = here.row;
        int c = here.col;

        printf("(%d,%d) ", r, c);
        if (map[r][c] == 'x') {          // 출구에 도달했다면 탐색 성공
            printf("미로 탐색 성공!\n");
            return 0;
        }
        else {                           // 출구가 아니면 현재 위치를
            map[r][c] = '.';             // 현재 위치를 "지나옴" 처리

            if (isValidLoc(r - 1, c)) locDeque.push_front(Location2D(r - 1, c));
            if (isValidLoc(r + 1, c)) locDeque.push_front(Location2D(r + 1, c));
            if (isValidLoc(r, c - 1)) locDeque.push_front(Location2D(r, c - 1));
            if (isValidLoc(r, c + 1)) locDeque.push_front(Location2D(r, c + 1));
        }
    }
    printf("미로탐색실패\n");
    return 0;
}


//오직 한쪽 끝으로만 데이터가 들어오고 나가는 제한된 스택구조
//

/*
int main() { // 
    stack<Location2D> locStack;
    Location2D entry(1, 0);
    locStack.push(entry);

    while (locStack.empty() == false) {
        Location2D  here = locStack.top();
        locStack.pop();

        int r = here.row, c = here.col;
        printf("(%d,%d) ", r, c);
        if (map[r][c] == 'x') {
            printf(" 미로 탐색 성공\n");
            return;
        }
        else {
            map[r][c] = '.';
            if (isValidLoc(r - 1, c)) locStack.push(Location2D(r - 1, c));
            if (isValidLoc(r + 1, c)) locStack.push(Location2D(r + 1, c));
            if (isValidLoc(r, c - 1)) locStack.push(Location2D(r, c - 1));
            if (isValidLoc(r, c + 1)) locStack.push(Location2D(r, c + 1));
        }
    }
    printf("미로 탐색 실패\n");
}
*/