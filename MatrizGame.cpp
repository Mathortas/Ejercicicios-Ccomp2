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
    int nf = f0, nc = c0;
    
    if (dir == 'a') nc--;
    else if (dir == 'w') nf--;
    else if (dir == 's') nf++;
    else if (dir == 'd') nc++;
    else {
        cout << "Ingresa uno valido!\n";
        return;
    }

    if (nf < 0 || nf >= 3 || nc < 0 || nc >= 3) {
        cout << "No puedes moverte ahi\n";
        return;
    }
    
    swap(*(*(m + f0) + c0), *(*(m + nf) + nc));
    
    f0 = nf;
    c0 = nc;
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
