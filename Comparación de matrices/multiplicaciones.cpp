#include <iostream>
#include <chrono>
#include <vector>

using namespace std;


vector<vector<int>> multiplicacion_clasica(vector<vector<int>> A,vector<vector<int>> B){
    int N = A.size();
    int M = A[0].size();
    int K = B[0].size();
    
    vector<vector<int>> resultado(N, vector<int>(K, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            for (int k = 0; k < M; ++k) {
                resultado[i][j] += A[i][k] * B[k][j];
            }
        }
    }
  
    return resultado;
}

vector<vector<int>> multiplicacion_por_bloques(vector<vector<int>> A,vector<vector<int>> B, int blockSize) {
    int N = A.size();
    int M = B[0].size();
    int K = B.size(); 
  
    vector<vector<int>> resultado(N, vector<int>(M, 0));
  
    for (int i = 0; i < N; i += blockSize) {
        for (int j = 0; j < M; j += blockSize) {
            for (int k = 0; k < K; k += blockSize) {
                for (int x = i; x < min(N, i + blockSize); ++x) {
                    for (int y = j; y < min(M, j + blockSize); ++y) {
                        for (int z = k; z < min(K, k + blockSize); ++z) {
                            resultado[x][y] += A[x][z] * B[z][y];
                        }
                    }
                }
            }
        }
    }
  return resultado;
}

int main() {
    
    int N = 600;  // Número de filas de A
    int K = 600;  // Número de columnas de A y filas de B
    int M = 600;  // Número de columnas de B
    vector<vector<int>> A(N, vector<int>(K, 3));  // Matriz A con 4s
    vector<vector<int>> B(K, vector<int>(M, 4));  // Matriz B con 2s
  
    auto start = std::chrono::system_clock::now();
    vector<vector<int>> resultado = multiplicacion_clasica(A, B);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<float, std::milli> duration = end - start;
    std::cout << duration.count() << "s" << endl;

    /*/ Imprimir el resultado
    for (const auto& fila : resultado) {
        for (int elemento : fila) {
            cout << elemento << " ";
        }
        cout << endl;
    }*/
    start = std::chrono::system_clock::now();
    vector<vector<int>> resultado2 = multiplicacion_por_bloques(A, B, 10);
    end = std::chrono::system_clock::now();
    duration = end - start;
    std::cout << duration.count() << "s" << endl;
    /* / Imprimir el resultado
    for (const auto& fila : resultado2) {
        for (int elemento : fila) {
            cout << elemento << " ";
        }
        cout << endl;
    }*/
    
    return 0;
}
