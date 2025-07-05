// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

// =============================================
// Sección 1: Funciones matemáticas básicas
// =============================================

// Funciones aritméticas binarias básicas
int suma(int x, int y) { return x+y; }
int resta(int x, int y) { return x-y; }
int mult(int x, int y) { return x*y; }
int divs(int x, int y) { return x/y; }

// Funciones para operaciones unarias (elevar al cuadrado y al cubo)
int cuadrado(int x) { return x*x; }
int cubo(int x) { return x*x*x; }

// =============================================
// Sección 2: Funciones de operación con punteros
// =============================================

// Aplica una función unaria a un valor
int operar(int x, int (*f)(int)) {
    return f(x);
}

// Aplica una función binaria a dos valores
int operados(int x, int y, int(*bin)(int,int)) {
    return bin(x,y);
}

// =============================================
// Sección 3: Funciones para manipulación de arrays
// =============================================

// Aplica una función a cada elemento de un array
void mapear(int* arr, int tam, int(*Fun)(int)) {
    for (int* p = arr; p < arr + tam; p++) {
        *p = Fun(*p);
    }
}

// Ordena un array usando una función de comparación
void bubblesort(int* arr, int tam, bool(*PF)(int,int)) {
    for(int* p = arr; p < arr+tam; p++) {
        for(int* q = p+1; q < arr+tam; q++) {
            if(PF(*p, *q)) {
                swap(*p, *q);
            }
        }
    }
}

// Funciones de comparación para ordenamiento
bool asc(int x, int y) { return x < y; }  // Orden ascendente
bool desc(int x, int y) { return x > y; } // Orden descendente

// =============================================
// Sección 4: Funciones para matrices
// =============================================

// Procesa una matriz aplicando una función unaria a cada elemento
void procesarMatriz(int** Matriz, int fil, int col, int FunUni(int)) {
    for(int** A = Matriz; A < Matriz + fil; A++) {
        int* i = *A;
        for(int* j = i; j < i + col; j++) {
            *j = FunUni(*j);
            cout << *j << " ";
        }
        cout << endl;
    }
}

// =============================================
// Sección 5: Funciones de filtrado
// =============================================

// Función de filtro (verifica si un número es múltiplo de 7)
bool multi7(int x) { return (x % 7); }

// Filtra elementos de un array según una condición
int filtrar(int* origen, int* destino, int tam, bool(*filtro)(int)) {
    int counter = 0;
    int* q = destino;
    for(int* p = origen; p < origen + tam; p++) {
        if(!(filtro(*p))) {
            *q = *p;
            q++;
            counter++;
        }
    }
    return counter;
}

// =============================================
// Sección 6: Constantes y variables globales
// =============================================
const int A = 20;
const int B = 5;
int c = 1;

// Definición de tipo para punteros a funciones binarias
typedef int (*PunFun)(int,int);

// =============================================
// Sección 7: Función principal (main)
// =============================================
int main() {
    // Demostración de punteros a funciones
    int (*pf)(int) = cuadrado;
    cout << pf(5) << endl; // Imprime 25 (5 al cuadrado)
    
    int(*pf2)(int, int PF(int)) = operar;
    int (*pf3)(int) = cubo;
    cout << (*pf2)(5, pf3) << endl; // Imprime 125 (5 al cubo)
    
    int (*PF4)(int, int, int pf(int,int)) = operados;
    cout << PF4(A,B,suma) << endl;  // 20+5 = 25
    cout << PF4(A,B,resta) << endl; // 20-5 = 15
    cout << PF4(A,B,mult) << endl;  // 20*5 = 100
    cout << PF4(A,B,divs) << endl;  // 20/5 = 4
    
    // Array de punteros a funciones
    PunFun arr[4] = {suma, resta, mult, divs};
    PunFun* ptr = arr;
    for(int i = 0; i < 4; i++) {
        cout << (*(ptr+i))(A, B) << endl; // Ejecuta todas las operaciones
    }
    
    // Creación y manipulación de un array
    int* Array = new int[10];
    for (int* p = Array; p < Array + 10; p++, c++) {
        *p = c;
    }
    
    // Aplica cubo a cada elemento del array
    mapear(Array, 10, cubo);
    for (int* p = Array; p < Array + 10; p++) {
        cout << *p << " ";
    }
    cout << endl;
    
    // Ordena el array en forma ascendente
    bubblesort(Array, 10, asc);
    for (int* p = Array; p < Array + 10; p++) {
        cout << *p << " ";
    }
    cout << endl;
    
    // Ordena el array en forma descendente
    bubblesort(Array, 10, desc);
    for (int* p = Array; p < Array + 10; p++) {
        cout << *p << " ";
    }
    cout << endl;
    
    // Creación y procesamiento de una matriz
    int** A = new int*[5];
    for(int** i = A; i < A+5; i++) {
        *i = new int[4];
        for(int* j = *i; j < *i+4; j++, c++) {
            *j = c;
            cout << *j << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    // Aplica cuadrado a cada elemento de la matriz
    procesarMatriz(A,5,4,cuadrado);
    cout << endl;
    
    // Demostración de filtrado
    int a[10] = {1,7,14,21,22,23,28,35,40,42};
    int b[10] = {0,0,0,0,0,0,0,0,0,0};
    cout << filtrar(a,b,10,multi7); // Cuenta los múltiplos de 7
    cout << endl;
    for(int i = 0; i < 10; i++) {
        cout << b[i] << " "; // Muestra los números filtrados
    }
    
    return 0;
}