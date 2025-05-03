#include <iostream>
using namespace std;

void printMatriz(int (*m)[3]) {
    for (int (*f)[3] = m; f < m + 3; f++, cout << endl) 
        for (int *e = *f; e < *f + 3; e++) 
            cout << *e << " ";
}

bool verificarVictoria(int (*m)[3]) {
    for (int (*f)[3] = m, c = 0; f < m + 3; f++) 
        for (int *e = *f; e < *f + 3; e++) 
            if (*e != c++) 
                return false;
    return true;
}

void moverCero(int (*m)[3], char dir, int &f0, int &c0) {
    int *ptr1 = *(m + f0) + c0; 
    int *ptraux = nullptr; 

    switch (dir) {
        case 'a': 
            if (c0 > 0) 
                ptraux = ptr1 - 1;
            break;
        case 'w': 
            if (f0 > 0) 
                ptraux = *(m + f0 - 1) + c0;
            break;
        case 's': 
            if (f0 < 2) 
                ptraux = *(m + f0 + 1) + c0;
            break;
        case 'd': 
            if (c0 < 2) 
                ptraux = ptr1 + 1;
            break;
        default:
            cout << "Ingresa una dirección válida (a, w, s, d)\n";
            return;
    }
    if (ptraux == nullptr) {
        cout << "No puedes moverte ahí\n";
        return;
    } 
    *ptr1 = *ptraux;
    *ptraux = 0;   
    switch (dir) {
        case 'a': c0--; break;
        case 'w': f0--; break;
        case 's': f0++; break;
        case 'd': c0++; break;
    }
}

int main() {
    int Mat[3][3] = {
        {1, 3, 5}, 
        {2, 8, 6}, 
        {4, 7, 0}
    };
    int f0 = 2, c0 = 2;
    
    while (!verificarVictoria(Mat)) {
        printMatriz(Mat);
        cout << "\nMovimiento (a=izquierda, w=arriba, s=abajo, d=derecha): ";
        char mov;
        cin >> mov;
        moverCero(Mat, mov, f0, c0);
        system("cls||clear");
    }
    
    printMatriz(Mat);
    cout << "\n¡Ganaste! Felicidades!\n";
    return 0;
}
