#include "AdjMatGraph.h"
#include <stdio.h>

int main() {
    AdjMatGraph g;
    

    // 정점 삽입
    for (int i = 0; i < 7; i++) {
        g.insertVertex('A' + i);
    }

    // 간선 삽입
    g.insertEdge(0, 1);
    g.insertEdge(0, 3);
    g.insertEdge(1, 2);
    g.insertEdge(1, 3);
    g.insertEdge(2, 3);
    g.insertEdge(4, 5);
    g.insertEdge(3, 6);
    g.insertEdge(4, 6);

    printf("인접 행렬로 표현한 그래프\n");
    g.display();

    // 파일 출력
    FILE* fp;
    fopen_s(&fp, "../text_out.txt", "w");

    if (fp != NULL) {
        g.display(fp);
        fclose(fp);
    }
    else {
        printf("파일 열기 실패\n");
    }

    // 가중치 그래프
    WGraph wg;

    wg.load("../graph.txt");

    printf("\n가중치 그래프\n");
    wg.display();


   
    return 0;


 
}

