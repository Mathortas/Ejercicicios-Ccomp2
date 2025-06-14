#include <iostream>
using namespace std;


float rectangulo(float base, float altura) {
    return base * altura;
}

float circulo(float radio, float) {
    const float pi = 3.1416;
    return pi * radio * radio;
}

float triangulo(float base, float altura) {
    return (base * altura) / 2;
}

float cuadrado(float lado, float) {
    return lado * lado;
}


typedef float (*PF)(float, float);


void ejecuta(PF* funciones, float (*parametros)[2], char (*nombres)[11]) {
    for (int i = 0; i < 4; i++) {
        float valor1 = *(*(parametros + i) + 0);
        float valor2 = *(*(parametros + i) + 1);
        float area = (*(funciones + i))(valor1, valor2);

        
        char* ptrNombre = *(nombres + i);
        cout << "Figura: ";
        while (*ptrNombre != '\0') {
            cout << *ptrNombre;
            ptrNombre++;
        }
        cout << " - Área: " << area << " metros" << endl;
    }
}


int main() {
    PF funciones[4] = {rectangulo, circulo, triangulo, cuadrado};

    float parametros[4][2] = {
        {5.0, 3.0},   // rectángulo
        {4.0, 0.0},   // círculo
        {6.0, 2.0},   // triángulo
        {3.5, 0.0}    // cuadrado
    };

    char nombres[4][11] = {"rectangulo", "circulo", "triangulo", "cuadrado"};

    ejecuta(funciones, parametros, nombres);

    return 0;
}