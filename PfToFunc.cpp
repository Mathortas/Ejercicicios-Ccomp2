#include <iostream>
using namespace std;

class formas{
    public:
    virtual float operator()(float,float)=0;
};

class rectangulo : public formas{
    public:
    float operator()(float base, float altura) override{
        return base*altura;
    }
    };
    
class circulo : public formas{
    public:
    float operator()(float radio, float zero) override{
        return radio*radio*3.1416;
    }
};

class triangle : public formas{
    public:
    float operator()(float base, float altura) override{
        return (base*altura)/2;
    }
};
class cuadrado : public formas{
    public:
    float operator()(float lado, float zero) override{
        return lado*lado;
    }
};

int main(){
    formas* rec = new rectangulo();
    formas* circ = new circulo();
    formas* tri = new triangle();
    formas* cuad = new cuadrado();
    formas* arr[4]= {rec, circ, tri ,cuad};
    float args[4][2] = {{3,5},{2,0} , {10,1}, {5,3}};
    float(*pArgs)[2] = args;
    int op[4] = {0, 1, 2, 3}; // configuración de figuras  
    int* pop = op;
    
    for(int i = 0 ; i < 4 ; i++, pop++, pArgs++){
        cout << arr[*pop]->operator()( (*pArgs)[0] , (*pArgs)[1] ) << endl;
    
}
    return 0;
}