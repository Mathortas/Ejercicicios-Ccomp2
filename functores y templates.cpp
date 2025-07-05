#include <iostream>
using namespace std;
int cuadrado(int x){
    return x*x;
}
class SumaConstante{
    int incremento;
    public:
        SumaConstante(int  x) : incremento(x){}
        int operator()(int val){
            return val + incremento;
        }
};

class CuadradoFunct{
    public:
    int operator()(int x){
        return x*x;
    }
};

template <class T>
class Multiplica{
    T factor;
    public:
        Multiplica(T f) : factor(f) {}
        T operator ()(T x){
            return x*factor;
        }
};

template < class T>
T aplicar(T valor, T (*f)(T) ){
    return (*f)(valor);
}

template<class Functor>
void procesarArray(int* A, int tam, Functor f){
    for(int* p = A; p < A+tam ; p++){
        *p = f(*p);
    }
}

class Incremento{
    int inc;
    public:
        Incremento(int i ) : inc(i) {}
        int operator()(int x){
            return inc+x;
        }
};

class Transformador{
    Incremento inc;
    public:
    Transformador(Incremento i) : inc(i){}
    int operator()(int x){
        return inc(x) * 2;
    }
}; 

template<class F>
class ContenedorFunctor{
    public:
    F f;
    ContenedorFunctor(F fu) : f(fu){}
    int aplicar(int x){
        return f(x);
    } 
};
int main(){
    int (*PF)(int) = cuadrado;
    SumaConstante sum(5);
    cout << sum(10) << endl;

    Multiplica<int> mult1(12);
    Multiplica<float> mult2(4.5);
    
    cout << mult1(10) << endl;
    cout << mult2(10) << endl;
    cout << aplicar<int>(10, *PF) << endl;
    
    CuadradoFunct functor1;
    int arr[5] = {1,2,3,4,5};
    procesarArray<CuadradoFunct>(arr, 5, functor1);
    for(int i = 0 ; i < 5 ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    Incremento inc(5);
    Transformador trans(inc);
    
    cout << trans(inc(3)) << endl;
    
    ContenedorFunctor<SumaConstante> conte(sum);
    cout << conte.aplicar(10) << endl;
}