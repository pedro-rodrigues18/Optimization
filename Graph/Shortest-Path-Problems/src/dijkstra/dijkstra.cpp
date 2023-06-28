#include "dijkstra.hpp"

int minDistance(vector<int> distances, vector<bool>visited){
    int min = INF;
    int min_index = -1;
    int vertices = distances.size();

    for(int i=0; i < vertices; i++){
        if(!visited[i] && distances[i] <= min){
            min = distances[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(vector<vector<int>>& graph, int source){
    auto startTime = chrono::steady_clock::now();

    int vertices = graph.size();

    vector<bool> visited(vertices, false); // Conjunto de nós visitados
    vector<int> distances(vertices, INF);  // vetor de distância
    vector<int> predecessors(vertices);    // vetor de predecessors
    
    distances[source] = 0;

    for (int i = 0; i < vertices - 1; i++) {
        int u = minDistance(distances, visited); // retorna o vertice vizinho com aresta de menor peso
        visited[u] = true;
        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && graph[u][v] != 0 && distances[u] != INF && distances[u] + graph[u][v] < distances[v]) {
                distances[v] = distances[u] + graph[u][v];
                predecessors[v] = u;
            }
        }
    }

    auto endTime = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();

    cout << "\nVetor de distancias:\n";
    printVector(distances);

    cout << "\nVetor de predecessores:\n";
    printVector(predecessors);

    cout << "Tempo de execução: " << duration << " milisegundos." << endl;
}