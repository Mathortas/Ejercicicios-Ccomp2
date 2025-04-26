#include <iostream>
using namespace std;

const int DIM = 3;

void multiplicarMatrices(int (*A)[DIM], int (*B)[DIM], int (*resultado)[DIM]) {
    for(int (*a)[DIM] = A, (*r)[DIM] = resultado; a < A + DIM; a++, r++) {
        for(int *er = *r; er < *r + DIM; er++) {
            *er = 0; // Inicializar el elemento del resultado
            for(int k = 0; k < DIM; k++) {
                *er += (*(*a + k)) * (*(*(B + k) + (er - *r)));
            }
        }
    }
}

void imprimirMatriz3D(int (*matriz3D)[DIM][DIM]) {
    for(int (*matriz)[DIM][DIM] = matriz3D; matriz < matriz3D + 3; matriz++) {
        cout << "Matriz " << (matriz - matriz3D) << ":\n";
        for(int (*fila)[DIM] = *matriz; fila < *matriz + DIM; fila++) {
            for(int *elemento = *fila; elemento < *fila + DIM; elemento++) {
                cout << *elemento << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main() {
    int matrices[3][DIM][DIM] = {
        {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},  // Matriz A
        {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}},  // Matriz B
        {{}}                                // Espacio para resultado
    };
    
    multiplicarMatrices(matrices[0], matrices[1], matrices[2]);
    imprimirMatriz3D(matrices);

    return 0;
}
