#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

// Função para ordenar os vértices por grau decrescente
vector<int> ordenarVerticesPorGrau(const vector<list<int>>& listaAdjacencia) {
    int numVertices = listaAdjacencia.size();
    vector<int> vertices(numVertices);
    for (int i = 0; i < numVertices; ++i) {
        vertices[i] = i;
    }

    sort(vertices.begin(), vertices.end(), [&listaAdjacencia](int a, int b) {
        return listaAdjacencia[a].size() > listaAdjacencia[b].size();
    });

    return vertices;
}

void coloracaoWelshPowell(const vector<list<int>>& listaAdjacencia, int numVertices, const vector<string>& nomesVertices) {
    vector<int> cores(numVertices, -1); // Inicializar todas as cores como não atribuídas
    vector<int> verticesOrdenados = ordenarVerticesPorGrau(listaAdjacencia);

    int corAtual = 0;
    for (int vertice : verticesOrdenados) {
        if (cores[vertice] == -1) {
            cores[vertice] = corAtual;

            for (int outroVertice : verticesOrdenados) {
                if (cores[outroVertice] == -1) {
                    bool podeColorir = true;
                    for (int adjacente : listaAdjacencia[outroVertice]) {
                        if (cores[adjacente] == corAtual) {
                            podeColorir = false;
                            break;
                        }
                    }
                    if (podeColorir) {
                        cores[outroVertice] = corAtual;
                    }
                }
            }
            ++corAtual;
        }
    }

    // Exibir as cores atribuídas a cada vértice
    for (int vertice = 0; vertice < numVertices; ++vertice) {
        cout << "Vértice " << nomesVertices[vertice] << " -> Cor " << cores[vertice] << endl;
    }
}

int main() {
    int numVertices = 10;
    vector<list<int>> listaAdjacencia(numVertices);
    vector<string> nomesVertices = {"A", "E", "F", "G", "H", "L", "B", "CO", "CA", "P"};

    // Adicionar arestas ao grafo
    listaAdjacencia[0] = {1, 2, 3, 4, 5};
    listaAdjacencia[1] = {0, 5};
    listaAdjacencia[2] = {0, 3, 6, 7};
    listaAdjacencia[3] = {0, 2, 6, 7, 8};
    listaAdjacencia[4] = {0, 5, 8, 9};
    listaAdjacencia[5] = {0, 1, 4, 9};
    listaAdjacencia[6] = {2, 3, 7};
    listaAdjacencia[7] = {2, 3, 6};
    listaAdjacencia[8] = {3, 4, 9};
    listaAdjacencia[9] = {4, 5, 8};

    coloracaoWelshPowell(listaAdjacencia, numVertices, nomesVertices);

    return 0;
}
