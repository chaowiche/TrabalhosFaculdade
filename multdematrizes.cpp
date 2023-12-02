#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> multiplicaMatrizes(const vector<vector<int>>& matrizA, const vector<vector<int>>& matrizB) {
    int linhasA = matrizA.size();
    int colunasA = matrizA[0].size();
    int linhasB = matrizB.size();
    int colunasB = matrizB[0].size();

    if (colunasA != linhasB) {
        cerr << "Erro: As matrizes não podem ser multiplicadas devido às dimensões incorretas." << endl;
        exit(EXIT_FAILURE);
    }

    vector<vector<int>> resultado(linhasA, vector<int>(colunasB, 0));

    for (int i = 0; i < linhasA; ++i) {
        for (int j = 0; j < colunasB; ++j) {
            for (int k = 0; k < colunasA; ++k) {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
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
    int linhasA, colunasA, linhasB, colunasB;

    cout << "Digite o número de linhas da matriz A: ";
    cin >> linhasA;

    cout << "Digite o número de colunas da matriz A: ";
    cin >> colunasA;

    cout << "Digite o número de linhas da matriz B: ";
    cin >> linhasB;

    cout << "Digite o número de colunas da matriz B: ";
    cin >> colunasB;

    if (colunasA != linhasB) {
        cerr << "Erro: As matrizes não podem ser multiplicadas devido às dimensões incorretas." << endl;
        return 1;
    }

    cout << "Digite os elementos da matriz A:" << endl;
    vector<vector<int>> matrizA(linhasA, vector<int>(colunasA));
    for (int i = 0; i < linhasA; ++i) {
        for (int j = 0; j < colunasA; ++j) {
            cin >> matrizA[i][j];
        }
    }

    cout << "Digite os elementos da matriz B:" << endl;
    vector<vector<int>> matrizB(linhasB, vector<int>(colunasB));
    for (int i = 0; i < linhasB; ++i) {
        for (int j = 0; j < colunasB; ++j) {
            cin >> matrizB[i][j];
        }
    }

    vector<vector<int>> resultado = multiplicaMatrizes(matrizA, matrizB);

    cout << "Matriz Resultante:" << endl;
    imprimeMatriz(resultado);

    return 0;
}
