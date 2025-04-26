#include <iostream>
using namespace std;

const int DIM = 3;
void sumarMatrices(int (*A)[DIM], int (*B)[DIM], int (*resultado)[DIM]) {
    for(int (*a)[DIM] = A, (*b)[DIM] = B, (*r)[DIM] = resultado; a < A + DIM; a++, b++, r++) {
        for(int *ea = *a, *eb = *b, *er = *r; ea < *a + DIM; ea++, eb++, er++) {
            *er = *ea + *eb;
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
        {{11, 12, 13}, {14, 15, 16}, {17, 18, 19}},  // Matriz A
        {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}},  // Matriz B
        {{}}                               // Espacio para suma
    };
    sumarMatrices(matrices[0], matrices[1], matrices[2]);
    imprimirMatriz3D(matrices);

    return 0;
}
