#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "../graph/graph.hpp"

int minDistance(vector<int> distance, vector<bool>visited);

void dijkstra(vector<vector<int>>& graph, int source);

#endif