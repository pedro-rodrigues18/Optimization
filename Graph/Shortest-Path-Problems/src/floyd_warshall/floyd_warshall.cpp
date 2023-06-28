#include "floyd_warshall.hpp"

void floydWarshall(vector<vector<int>>& graph){
    auto startTime = chrono::steady_clock::now();

    int vertices = graph[0].size();
    vector<vector<int>> distances(vertices, vector<int>(vertices, INF));
    vector<vector<int>> predecessors(vertices, vector<int>(vertices, -1));

    for(int u = 0; u < vertices; u++){
        for(int v = 0; v < vertices; v++){
            if(u == v) distances[u][v] = 0;

            if(graph[u][v] != 0 && graph[u][v] != INF) {
                distances[u][v] = graph[u][v];
                predecessors[u][v] = u;
            }
        }
    }

    for(int k = 0; k < vertices; k++){
        for(int u = 0; u < vertices; u++){
            for(int v = 0; v < vertices; v++){
                if(distances[u][k] + distances[k][v] < distances[u][v]){
                    distances[u][v] = distances[u][k] + distances[k][v];
                    predecessors[u][v] = predecessors[k][v];
                }
            }
        }
    }

    auto endTime = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();

    cout << "Matriz de distâncias: " << endl;
    printMatrix(distances);
    cout << endl;
    cout << "\nMatriz de predecessor: " << endl;
    printMatrix(predecessors);

    cout << "\nTempo de execução: " << duration << " milisegundos." << endl;
}