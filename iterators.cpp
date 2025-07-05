#include <iostream>
#include <bits/stdc++.h>  // Incluye todas las bibliotecas estándar (no recomendado en producción)
using namespace std;

// =============================================
// Clase Iterator: Implementación de un iterador personalizado
// =============================================
template <class T>
class Iterator {
    T* it;  // Puntero interno que realiza el seguimiento de la posición actual
public:
    Iterator(T* p) : it(p) {}  // Constructor que inicializa el puntero
    
    // Sobrecarga del operador de dereferencia (para acceder al valor)
    T operator*() {
        return *it;
    }
    
    // Sobrecarga del operador de pre-incremento (++iterador)
    void operator++() {
        ++it;
    }
    
    // Sobrecarga del operador de post-incremento (iterador++)
    void operator++(T) {  // El parámetro int dummy diferencia post-incremento
        it++;
    }
    
    // Sobrecarga del operador de desigualdad
    bool operator!=(Iterator o) {
        return it != o.it;
    }
};

// =============================================
// Clase Contenedor: Implementación simple de un contenedor
// =============================================
template<class T>
class Contenedor {
    T datos[5];  // Array interno de tamaño fijo
    
public:
    // Constructor que inicializa el array con valores 0, 10, 20, 30, 40
    Contenedor() {
        for (int i = 0; i < 5; i++) {
            datos[i] = i * 10;
        }
    }
    
    // Métodos para obtener iteradores al inicio y final
    T* begin() { return &datos[0]; }
    T* end() { return &datos[5]; }  // Puntero al elemento después del último
};

// =============================================
// Función principal (main)
// =============================================
int main() {
    // Primera parte: Uso del Iterator personalizado con un array dinámico
    int ctr = 0;
    int* Arr = new int[5];
    
    // Inicialización del array con valores 0, 1, 2, 3, 4
    for(int* p = Arr; p < Arr+5; p++) {
        *p = ctr;
        ctr++;
    }
    
    // Creación de iteradores para el array
    Iterator<int> iterador(Arr);          // Iterador al inicio
    Iterator<int> iteradorfinal(Arr+5);   // Iterador al final
    
    // Recorrido del array usando el iterador personalizado
    while(iterador != iteradorfinal) {
        cout << *iterador << " ";
        ++iterador;
    }
    cout << endl;
    
    // Segunda parte: Uso del Contenedor personalizado
    Contenedor<int> c;
    int* it = c.begin();  // Iterador al inicio (puntero directo)
    int* fin = c.end();   // Iterador al final
    
    // Recorrido del contenedor usando punteros como iteradores
    while(it != fin) {
        cout << *it << " ";
        ++it;
    }
    
    // Nota: Falta liberar la memoria del array dinámico 'Arr'
    // delete[] Arr;  // Esto debería estar al final del main
}