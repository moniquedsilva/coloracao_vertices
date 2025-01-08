#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

// Função para encontrar a cor mínima disponível para um vértice
int encontrarCorMinima(int vertice, const vector<list<int>>& listaAdjacencia, const vector<int>& cores) {
    vector<bool> coresUsadas(cores.size(), false);

    // Marcar as cores usadas pelos vértices adjacentes
    for (int verticeAdjacente : listaAdjacencia[vertice]) {
        if (cores[verticeAdjacente] != -1) {
            coresUsadas[cores[verticeAdjacente]] = true;
        }
    }

    // Encontrar a primeira cor não usada
    for (int cor = 0; cor < coresUsadas.size(); ++cor) {
        if (!coresUsadas[cor]) {
            return cor;
        }
    }

    // Se todas as cores estiverem usadas, retornar uma nova cor
    return coresUsadas.size();
}

void coloracaoGulosa(const vector<list<int>>& listaAdjacencia, int numVertices, const vector<string>& nomesVertices) {
    vector<int> cores(numVertices, -1); // Inicializar todas as cores como não atribuídas
    cores[0] = 0; // Colorir o primeiro vértice com a primeira cor

    // Colorir os vértices restantes
    for (int vertice = 1; vertice < numVertices; ++vertice) {
        int cor = encontrarCorMinima(vertice, listaAdjacencia, cores);
        cores[vertice] = cor;
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

    coloracaoGulosa(listaAdjacencia, numVertices, nomesVertices);

    return 0;
}
