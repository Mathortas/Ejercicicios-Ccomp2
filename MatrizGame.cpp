#include <iostream>
using namespace std;

void printMatriz(int (*matriz)[3]) {
    for(int (*fila)[3] = matriz; fila < matriz + 3; fila++) {
        for(int *elemento = *fila; elemento < *fila + 3; elemento++) {
            cout << *elemento << " ";
        }
        cout << endl;
    }
}

bool verificarVictoria(int (*matriz)[3]) {
    int contador = 0;
    for(int (*fila)[3] = matriz; fila < matriz + 3; fila++) {
        for(int *elemento = *fila; elemento < *fila + 3; elemento++) {
            if(*elemento != contador++) {
                return false;
            }
        }
    }
    return true;
}

void moverCero(int (*matriz)[3], char direccion, int &fila0, int &col0) {
    // Calcular nueva posición basada en la posición actual del 0
    int nuevaFila = fila0;
    int nuevaCol = col0;
    
    if(direccion == 'a') nuevaCol--;      // Izquierda
    else if(direccion == 'w') nuevaFila--; // Arriba
    else if(direccion == 's') nuevaFila++; // Abajo
    else if(direccion == 'd') nuevaCol++;  // Derecha
    else {
        cout << "Direccion no valida!\n";
        return;
    }

    // Verificar límites
    if(nuevaFila < 0 || nuevaFila >= 3 || nuevaCol < 0 || nuevaCol >= 3) {
        cout << "Movimiento no permitido!\n";
        return;
    }

    int *pos0 = *(matriz + fila0) + col0;
    int *nuevaPos = *(matriz + nuevaFila) + nuevaCol;
    
    // Realizar el intercambio
    *pos0 = *nuevaPos;
    *nuevaPos = 0;
    
    // Actualizar posición del 0
    fila0 = nuevaFila;
    col0 = nuevaCol;
}

int main() {

    int Mat[3][3] = { {1, 3, 5}, {2, 8, 6}, {4, 7, 0} };
    
    int fila0 = 2, 
    int col0 = 2;
    
    while(!verificarVictoria(Mat)) {
        printMatriz(Mat);
        
        cout << "Ingrese movimiento (a=izq, w=arriba, s=abajo, d=der): ";
        char movimiento;
        cin >> movimiento;
        
        moverCero(Mat, movimiento, fila0, col0);
        system("cls || clear"); 
    }
    
    printMatriz(Mat);
    cout << "Wenaaaa" << endl;
    
    return 0;
}
