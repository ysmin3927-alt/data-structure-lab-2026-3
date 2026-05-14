#include "AdjMatGraph.h"

int main() {
    //AdjMatGraph g; // 새로운 그래프 객체 생성
    SrchAMGraph g;
    // 정점 삽입: 'A', 'B', 'C', 'D' (0, 1, 2, 3번에 대응)
    for (int i = 0; i < 7; i++) {
        g.insertVertex('A' + i);
    }

    // 간선 삽입
    g.insertEdge(0, 1); // A - B
    g.insertEdge(0, 3); // A - D
    g.insertEdge(1, 2); // B - C
    g.insertEdge(1, 3); // B - D
    g.insertEdge(2, 3); // C - D
    g.insertEdge(4, 5);
    g.insertEdge(3, 6);
    g.insertEdge(4, 6);

    // 결과 출력
    printf("인접 행렬로 표현한 그래프\n");
    g.display();

    FILE* fp;
        fopen_s(&fp, "../text_out.txt", "w"); //..한단계위의 파일 폴더에 라이트 모드로 
    g.display(fp);
    fclose(fp);

    printf("DFS==>");
    g.resetVisited();
    g.DFS(0);
    printf("\n");


    return 0;
}