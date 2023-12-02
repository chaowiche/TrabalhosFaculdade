
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void imprimeMatriz(const vector<vector<double>>& matriz) {
    for (const auto& linha : matriz) {
        for (double elemento : linha) {
            cout << fixed << setprecision(0) << elemento << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void pivoteamentoParcial(vector<vector<double>>& matriz, int indiceLinha) {
    int indiceLinhaMax = indiceLinha;
    for (int i = indiceLinha + 1; i < matriz.size(); ++i) {
        if (matriz[i][indiceLinha] > matriz[indiceLinhaMax][indiceLinha]) {
            indiceLinhaMax = i;
        }
    }
    swap(matriz[indiceLinha], matriz[indiceLinhaMax]);
}

void escalonamentoLinha(vector<vector<double>>& matriz, int indiceLinha) {
    double pivo = matriz[indiceLinha][indiceLinha];
    for (double& elemento : matriz[indiceLinha]) {
        elemento /= pivo;
    }
}

void eliminacaoLinha(vector<vector<double>>& matriz, int indicePivo) {
    for (int i = 0; i < matriz.size(); ++i) {
        if (i != indicePivo) {
            double fator = matriz[i][indicePivo];
            for (int j = 0; j < matriz[i].size(); ++j) {
                matriz[i][j] -= fator * matriz[indicePivo][j];
            }
        }
    }
}

void eliminacaoGaussJordan(vector<vector<double>>& matriz) {
    cout << "Matriz Inicial:" << endl;
    imprimeMatriz(matriz);

    for (int i = 0; i < matriz.size(); ++i) {
        pivoteamentoParcial(matriz, i);
        cout << "Pivoteamento Parcial (linha " << i + 1 << " trocada com linha " << i + 2 << "):" << endl;
        imprimeMatriz(matriz);

        escalonamentoLinha(matriz, i);
        cout << "Escalonamento (linha " << i + 1 << " dividida por " << matriz[i][i] << "):" << endl;
        imprimeMatriz(matriz);

        eliminacaoLinha(matriz, i);
        cout << "Eliminacao:" << endl;
        imprimeMatriz(matriz);
    }
}

int main() {
    int n;
    cout << "Digite a ordem da matriz quadrada: ";
    cin >> n;

    vector<vector<double>> matriz(n, vector<double>(n));
    cout << "Digite os elementos da matriz:" << endl;
    for (auto& linha : matriz) {
        for (double& elemento : linha) {
            cin >> elemento;
        }
    }

    eliminacaoGaussJordan(matriz);

    cout << "Matriz Resultante:" << endl;
    for (auto& linha : matriz) {
        for (double& elemento : linha) {
            if (elemento == -0) {
                elemento = 0;
            }
        }
    }

    imprimeMatriz(matriz);

    return 0;
}
