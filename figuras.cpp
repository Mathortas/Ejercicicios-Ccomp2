#include <iostream>
using namespace std;

float rectangulo(float base, float altura) {
    cout << "El area del rectangulo es: " << base * altura << endl;
    return base * altura;
}

float circulo(float radio, float) {
    float pi = 3.1416;
    cout << "El area del circulo es: " << pi * (radio * radio) << endl;
    return pi * (radio * radio);
}

float triangulo(float base, float altura) {
    cout << "El area del triangulo es: " << (base * altura) / 2 << endl;
    return (base * altura) / 2;
}

float cuadrado(float lado, float) {
    cout << "El area del cuadrado es: " << lado * lado << endl;
    return lado * lado;
}

typedef float (*PF)(float, float); // puntero a función

int main() {
    PF funciones[4] = {rectangulo, circulo, triangulo, cuadrado};

    float figuras[4][2] = {
        {2, 0},   // para cuadrado (indice 3)
        {3, 5},   // para triangulo (indice 2)
        {10, 0},  // para circulo (indice 1)
        {5, 3}    // para rectangulo (indice 0)
    };

    int ordenFiguras[4] = {3, 2, 1, 0}; // índice de funciones

    for (int i = 0; i < 4; i++) {
        int idx = ordenFiguras[i];
        float base = figuras[i][0];
        float altura = figuras[i][1];

        funciones[idx](base, altura);
    }

    return 0;
}
