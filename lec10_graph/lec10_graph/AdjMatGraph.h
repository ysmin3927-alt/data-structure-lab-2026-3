
#pragma once
#include <stdio.h>
#define INF 9999
#define MAX_VTXS 20


class AdjMatGraph {
protected:
    int size;
    char vertices[MAX_VTXS];
    int adj[MAX_VTXS][MAX_VTXS];

public:
    AdjMatGraph() {
        reset();
    }

    char getVertex(int i) {
        return vertices[i];
    }

    int getEdge(int i, int j) {
        return adj[i][j];
    }

    void setEdge(int i, int j, int val) {
        adj[i][j] = val;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size >= MAX_VTXS;
    }

    // 그래프 초기화
    void reset() {
        size = 0;

        for (int i = 0; i < MAX_VTXS; i++) {
            for (int j = 0; j < MAX_VTXS; j++) {
                setEdge(i, j, 0);
            }
        }
    }

    // 정점 삽입
    void insertVertex(char name) {
        if (!isFull()) {
            vertices[size++] = name;
        }
        else {
            printf("Error: 그래프 정점 개수 초과\n");
        }
    }

    // 간선 삽입: 무방향 그래프
    void insertEdge(int u, int v) {
        setEdge(u, v, 1);
        setEdge(v, u, 1);
    }

    // 간선 삭제
    void deleteEdge(int u, int v) {
        setEdge(u, v, 0);
        setEdge(v, u, 0);
    }

    // 정점 삭제
    void deleteVertex(int v) {
        if (v < 0 || v >= size) {
            return;
        }

        // 정점 배열에서 삭제
        for (int i = v; i < size - 1; i++) {
            vertices[i] = vertices[i + 1];
        }

        // 행 삭제
        for (int i = v; i < size - 1; i++) {
            for (int j = 0; j < size; j++) {
                adj[i][j] = adj[i + 1][j];
            }
        }

        // 열 삭제
        for (int j = v; j < size - 1; j++) {
            for (int i = 0; i < size; i++) {
                adj[i][j] = adj[i][j + 1];
            }
        }

        size--;
    }

    // 인접 정점 배열 반환
    int* adjacent(int v) {
        return adj[v];
    }

    // 그래프 정보 출력
    void display(FILE* fp = stdout) {
        fprintf(fp, "%d\n", size);

        for (int i = 0; i < size; i++) {
            fprintf(fp, "%c ", getVertex(i));

            for (int j = 0; j < size; j++) {
                fprintf(fp, "%6d", getEdge(i, j));
            }

            fprintf(fp, "\n");
        }
    }
};


class WGraph : public AdjMatGraph {
public:
  
    // 1. 간선 삽입 함수
    void insertEdge(int u, int v, int weight) {
        if (weight > INF) {
            weight = INF;
        }
        setEdge(u, v, weight);
    }

    // 2. 간선 존재 여부 확인 함수 (가중치가 INF보다 작으면 간선이 존재함)
    bool hasEdge(int i, int j) {
        return (getEdge(i, j) < INF);
    }

    // 3. 파일에서 그래프 정보를 읽어오는 함수 (인접 행렬 기반 가중치 그래프)
  
    void load(const char* filename) {
        FILE* fp;
        fopen_s(&fp, filename, "r");
        if (fp != NULL) {
            int n;
            // 정점의 전체 개수 읽기
            fscanf_s(fp, "%d", &n);

            for (int i = 0; i < n; i++) {
                char str[80];
                int val;

                // 정점의 이름 읽기 및 삽입
                fscanf_s(fp, "%s", str,(unsigned int)sizeof(str));
                insertVertex(str[0]);

                // 해당 정점과 연결된 간선 정보(가중치 행렬) 읽기 및 삽입
                for (int j = 0; j < n; j++) {
                    fscanf_s(fp, "%d", &val);
                    insertEdge(i, j, val);
                }
            }
            fclose(fp);
        }
    }
    
};


