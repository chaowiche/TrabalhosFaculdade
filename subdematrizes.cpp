#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> subtraiMatrizes(const vector<vector<int>>& matrizA, const vector<vector<int>>& matrizB) {
    int linhas = matrizA.size();
    int colunas = matrizA[0].size();

    vector<vector<int>> resultado(linhas, vector<int>(colunas, 0));

    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            resultado[i][j] = matrizA[i][j] - matrizB[i][j];
        }
    }

    return resultado;
}

void imprimeMatriz(const vector<vector<int>>& matriz) {
    for (const auto& linha : matriz) {
        for (int elemento : linha) {
            cout << elemento << " ";
        }
        cout << endl;
    }
}

int main() {
    int linhas, colunas;

    cout << "Digite o número de linhas: ";
    cin >> linhas;

    cout << "Digite o número de colunas: ";
    cin >> colunas;

    cout << "Digite os elementos da primeira matriz:" << endl;
    vector<vector<int>> matrizA(linhas, vector<int>(colunas));
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            cin >> matrizA[i][j];
        }
    }

    cout << "Digite os elementos da segunda matriz:" << endl;
    vector<vector<int>> matrizB(linhas, vector<int>(colunas));
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            cin >> matrizB[i][j];
        }
    }

    vector<vector<int>> resultado = subtraiMatrizes(matrizA, matrizB);

    cout << "Matriz Resultante:" << endl;
    imprimeMatriz(resultado);

    return 0;
}
