#include "Location2D.h"
#include <stack>
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
int main() {
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

