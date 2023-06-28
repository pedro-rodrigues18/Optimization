#ifndef GRAPH_HPP
#define GRAPH_HPP

#include<bits/stdc++.h>
#include <chrono>

using namespace std;

const int INF = 0x3f3f3f3f;

int randomRange(int min, int max);

vector<vector<int>> generateGraph(int vertices, int edges, char negativeEdges);

void printMatrix(vector<vector<int>>& mat);

void printVector(vector<int>& vec);

#endif