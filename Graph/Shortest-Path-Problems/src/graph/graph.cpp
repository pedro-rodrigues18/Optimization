#include "graph.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int randomRange(int min, int max) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    // using nanosec instead sec
    srand((time_t)ts.tv_nsec);
    return min + rand() % (max - min + 1);
}

vector<vector<int>> generateGraph(int vertices, int edges, char negativeEdges) {
    vector<vector<int>> graph(vertices, vector<int>(vertices, 0));

    for (int i = 0; i < edges; i++) {
        int source = randomRange(0, vertices - 1);
        int destiny = randomRange(0, vertices - 1);
        
        int weight = (negativeEdges == 's') ? randomRange(-5, 10) : randomRange(1, 10);

        if (graph[source][destiny] == 0 && source != destiny) {
            graph[source][destiny] = weight;
        }
    }

    return graph;
}

void printMatrix(vector<vector<int>>& mat) {
    int vertices = mat.size();
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if(mat[i][j] != INF)
                cout << mat[i][j] << " ";
            else cout << "INF" << " ";
        }
        cout << endl;
    }
}

void printVector(vector<int>& vec){
    int vertices = vec.size();
    for (int i = 0; i < vertices; i++) {
        if(vec[i] != INF)
            cout << vec[i] << " ";
        else cout << "INF" << " ";
    }
    cout << endl;
}

