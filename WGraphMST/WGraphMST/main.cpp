#include <iostream>
#include "WGraphMST.h"

using namespace std;

int main() {
    WGraphMST g;

    // 그래프 파일 로드
    g.load("../graph.txt");

    cout << "입력 그래프: graph.txt" << endl;
    g.display();

    // 1. Kruskal 알고리즘 테스트
    cout << "==========================================" << endl;
    cout << "MST By Kruskal's Algorithm" << endl;
    cout << "==========================================" << endl;
    g.Kruskal();
    cout << endl;

    // 2. Prim 알고리즘 테스트 (0번 정점 시작)
    cout << "==========================================" << endl;
    cout << "MST By Prim's Algorithm (Starting from vertex 0)" << endl;
    cout << "==========================================" << endl;
    cout << "정점 방문 순서: ";
    g.Prim(0);
    cout << "==========================================" << endl;

    return 0;
}