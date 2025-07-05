#include <iostream>
using namespace std;


void procesar(int valor, auto f){
    cout<< f(valor) << endl;
}
int main(){
    auto doble = [](auto x){return x*2;};
    cout << doble(1200.51) << endl;
    
    auto hola =[](){
        cout << "hola mundo" << endl;
    };
    hola();
    int a = 5;
    auto suma=[a](auto x){
        return a+x;
    };
    
    cout << suma(10)<< endl;
    
    int b = 45;
    
    auto resta = [&b](auto x){
        b = b-x;
    };
    resta(1);
    resta(2);
    cout << b << endl;
    
    int x = 15;
    procesar(x,suma);
    
    auto generador= [](int factor){
        return [factor](int x){
            return x*factor;
        };  
    };
    
    auto por5 = generador(5);
    cout << por5(10) << endl;
    auto funcion = [x,b](int a){
        return a*x + b ;
    };
    cout << funcion(1) << endl;
    
    auto funcion2 =  [&x, &b](int c){
        x = x+c;
        b = b+c;
    };
    cout << x << " " << b << " " << endl;
    funcion2(2);
    cout << x << " " << b << " " << endl;
}