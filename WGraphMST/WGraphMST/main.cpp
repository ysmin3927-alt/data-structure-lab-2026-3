#include <iostream>
#include "WGraphMST.h"

using namespace std;

int main() {
    {
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
        cout << endl; // 레이아웃 조정을 위한 줄바꿈
    }

    {
        WGraphDijkstra g;
        g.load("../graph_sp.txt");

        // 🛑 교수님 화면 출력 순서 그대로 코드 추가 및 주석 해제
        cout << "graph_sp.txt 파일 생성 및 저장 완료" << endl << endl;
        printf("Dijkstra의 최단경로 탐색을 위한 그래프: graph_sp.txt\n");

        g.display();

        printf("Shortest Path By Dijkstra Algorithm\n");
        g.ShortestPath(0);
    }

    return 0;
    
}
