#include "bellman_ford.hpp"

void bellmanFord(vector<vector<int>>& graph, int source){
    auto startTime = chrono::steady_clock::now();

    int vertices = graph[0].size();
    vector<int> distances(vertices, INF);
    vector<int> predecessors(vertices, -1);
    
    distances[source] = 0;

    for (int i = 0; i < vertices - 1; i++) {
        for (int u = 0; u < vertices; u++) {
            for (int v = 0; v < vertices; v++) {
                if(graph[u][v] != 0 && distances[u] != INF && distances[u] + graph[u][v] < distances[v]) {
                    distances[v] = distances[u] + graph[u][v];
                    predecessors[v] = u;
                }
            }
        }
    }

    for(int u = 0; u < vertices; u++){
        for(int v = 0; v < vertices; v++){
            if(graph[u][v] != 0  && distances[u] != INF && distances[u] + graph[u][v] < distances[v]){
                cout << "Grafo possui ciclo de custo negativo." << endl;
                return;
            }
        }
    }

    auto endTime = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();

    cout << "\nVetor de distancias:\n";
    printVector(distances);

    cout << "\nVetor de predecessores:\n";
    printVector(predecessors);

    cout << "\nTempo de execução: " << duration << " milisegundos." << endl;
}