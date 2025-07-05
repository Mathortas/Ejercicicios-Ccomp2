#include <iostream>
using namespace std;
const int a = 10;
const int b = 5;

// =============================================
// Clase Calculadora con operaciones básicas
// =============================================
class Calculadora{
    public:
    int sumar(int x, int y){ return x+y; }
    int restar(int x, int y){ return x-y; }
    int multiplicar(int x, int y){ return x*y; }
    int dividir(int x, int y){ return x/y; }
    
    // Método estático para calcular potencias
    static int potencia(int base, int exp){
        int n = base;
        for(int i = 0; i < exp; i++){
            n = n*base;
        }
        return n;
    }
};

// =============================================
// Clase Rectangulo simple con atributos públicos
// =============================================
class Rectangulo{
    public:
    int ancho;
    int alto;
};

// =============================================
// Clase Procesador para imprimir valores
// =============================================
class Procesador{
    public:
    void imprimir(int x){
        cout << x << " ";
    }
};

// Función para aplicar un método de Procesador múltiples veces
void aplicar(int valor, Procesador* obj, void(Procesador::*pmeto)(int)){
    for(int i = 0; i < valor; i++){
        (obj->*pmeto)(i);
    }
}

// =============================================
// Jerarquía de clases Figura con método virtual puro
// =============================================
class Figura{
    public:
    virtual float area(int,int) = 0;
};

class Circle : public Figura{
    float area(int x, int zero) override{
        return x*3.14; // Cálculo aproximado del área de un círculo
    }
};

class Cuadrado : public Figura{
    float area(int x, int y) override {
        return x*y; // Área de un cuadrado/rectángulo
    }
};

class Triangulo : public Figura{
    float area(int x, int y) override {
        return (x*y)/2; // Área de un triángulo
    }
};

// =============================================
// Función principal (main)
// =============================================
int main(){
    // Demostración de punteros a métodos de clase
    Calculadora calcu;
    int(Calculadora::*pf)(int,int);
    
    pf = &Calculadora::sumar;
    cout << (calcu.*pf)(a,b) << endl;
    
    pf = &Calculadora::restar;
    cout << (calcu.*pf)(a,b) << endl;
    
    // Demostración de punteros a miembros de datos
    Rectangulo rect;
    int Rectangulo::*pm;
    pm = &Rectangulo::ancho;
    rect.*pm = 15;
    cout << rect.ancho << endl;
    
    Rectangulo* pc = new Rectangulo();
    pc->*pm = 20;
    cout << pc->ancho << endl;
    
    // Array de punteros a métodos
    int(Calculadora::*operaciones[])(int, int) = {
        &Calculadora::sumar, 
        &Calculadora::restar, 
        &Calculadora::multiplicar, 
        &Calculadora::dividir
    };
    
    for(int i = 0; i < 4; i++){
        cout << (calcu.*operaciones[i])(a,b) << endl;
    }
    
    // Puntero a método estático
    static int (*pEst)(int, int);
    pEst = Calculadora::potencia;
    cout << pEst(a,b) << endl;
    
    // Uso de puntero a método con función aplicadora
    Procesador proce;
    void(Procesador::*Pproce)(int);
    Pproce = &Procesador::imprimir;
    aplicar(5,&proce,Pproce);
    cout << endl;
    
    // Polimorfismo con punteros a métodos virtuales
    Figura* circ = new Circle();
    Figura* cuad = new Cuadrado();
    Figura* tri = new Triangulo();
    
    Figura* arr[3] = {circ, cuad, tri};
    float (Figura::*PunteroFiguras)(int,int);
    PunteroFiguras = &Figura::area;
    
    for(int i = 0; i < 3; i++){
        cout << (arr[i].*PunteroFiguras)(a,b) << endl;
    }
    
    // Nota: El código original tiene un error en esta línea:
    // cout << (*arr[i].*PunteroFiguras)(a,b) << endl;
    // Debería ser: cout << (arr[i]->*PunteroFiguras)(a,b) << endl;
}