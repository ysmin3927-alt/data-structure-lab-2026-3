#pragma once
#include <stdio.h>

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
                fprintf(fp, "%3d", getEdge(i, j));
            }

            fprintf(fp, "\n");
        }
    }
};