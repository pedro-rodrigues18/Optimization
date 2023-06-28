#include "graph/graph.hpp"
#include "dijkstra/dijkstra.hpp"
#include "bellman_ford/bellman_ford.hpp"
#include "floyd_warshall/floyd_warshall.hpp"


using namespace std;

void menu(int *op){
    cout << "Selecione qual algoritmo de caminho mínimo você deseja executar sobe o grafo gerado: " << endl;
    cout << "[1] - Algoritmo de Dijkstra (Grafo com arestas positivos)" << endl;
    cout << "[2] - Algoritmo de Bellman-Ford (Grafo com arestas positivos e negativas)" << endl;
    cout << "[3] - Algoritmo de Floyd-Warshall (Grafo com arestas positivos e negativas)" << endl;
    cout << "[0] - Sair" << endl;
    cout << ">> ";
    cin >> *op;
}

int main(){
    int vertices, edge, op, source;
    char runAgain, negativeEdges;

    cout << "Você deseja gerar um grafo com arestas negativas? [s] - sim | [n] - não" << endl;
    cout << ">> ";
    cin >> negativeEdges;

    cout << "Insira o número de vértices do grafo: ";
    cin >> vertices;
    cout << "Insira o número de arestas do grafo: ";
    cin >> edge;

    vector<vector<int>> graph = generateGraph(vertices, edge, negativeEdges);

    cout << "\nMatriz de adjacência do grafo gerado:\n" << endl;
    printMatrix(graph);
    cout << endl;

    menu(&op);
    
    do{
        switch (op){
            case 1:
                if(negativeEdges == 'n'){
                    cout << "\nInsira o vértice de origem: "; cin >> source;

                    dijkstra(graph, source);

                    cout << "\nDeseja executar outro algoritmo? [s] - sim | [n] - não" << endl;
                    cout << ">> ";
                    cin >> runAgain;
                    if(runAgain == 's')
                        menu(&op);
                    else if(runAgain == 'n')
                        op = 0;
                    else {
                        cout << "Opção inválida!" << endl;
                        op = 0;
                    }
                    break;
                }else{
                    cout << "O algoritmo de Dijkstra não resolve o caminho mínimo para grafos com aresta negativa." << endl;
                    cout << "Tente executar o algoritmo de Bellman-Ford ou de Floyd-Warshall.\n" << endl;
                    menu(&op);
                }
                break;
            case 2:
                cout << "\nInsira o vértice de origem: "; cin >> source;

                bellmanFord(graph, source);

                cout << "Deseja executar outro algoritmo? [s] - sim | [n] - não" << endl;
                cout << ">> ";
                cin >> runAgain;
                if(runAgain == 's')
                    menu(&op);
                else if(runAgain == 'n')
                    op = 0;
                else {
                    cout << "Opção inválida!" << endl;
                    op = 0;
                }
                break;
            case 3:
                cout << endl;

                floydWarshall(graph);
                
                cout << "Deseja executar outro algoritmo? [s] - sim | [n] - não" << endl;
                cout << ">> ";
                cin >> runAgain;
                if(runAgain == 's')
                    menu(&op);
                else if(runAgain == 'n')
                    op = 0;
                else {
                    cout << "Opção inválida!" << endl;
                    op = 0;
                }
                break;
            case 0:
                cout << "Saindo..." << endl;
                exit(0);
                break;
            default:
                cout << "Opção inválida." << endl;
                break;
        }
    }while(op != 0 && runAgain == 's');
    
    return 0;
}