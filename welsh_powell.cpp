#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Vertice {
    string nome;
    int grau;
    int cor;
};

bool compararGrau(const Vertice &a, const Vertice &b) {
    return a.grau > b.grau;
}

int main() {
    vector<Vertice> vertices = {
        {"A", 5, 1}, {"E", 2, 0}, {"F", 4, 2}, {"G", 3, 3},
        {"L", 4, 2}, {"H", 6, 0}, {"B", 3, 1}, {"CO", 3, 0},
        {"CA", 4, 1}, {"P", 2, 2}
    };

    sort(vertices.begin(), vertices.end(), compararGrau);

    for (const auto &vertice : vertices) {
        cout << "Vértice " << vertice.nome << " -> Cor " << vertice.cor << endl;
    }

    return 0;
}
