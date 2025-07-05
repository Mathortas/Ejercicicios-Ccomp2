#include <iostream>
#include <thread>
using namespace std;

class Operacion{
    public:
    virtual float operator()(float,float) = 0;
};

class Suma : public Operacion{
    public:
    float operator()(float x, float y) override{
        return x+y;
    }
};

class Resta : public Operacion{
    public:
    float operator()(float x, float y) override{
        return x-y;
    }
};

class Multiplica : public Operacion{
    public:
    float operator()(float x, float y) override{
        return x*y;
    }
};

float operativo(float x , float y, Operacion* Pc){
    return (*Pc).operator()(x,y);
}

int main(){
    float x = 10;
    float y = 5;
    float (*Pf)(float,float, Operacion*);
    Pf = operativo;
    
    Operacion* Sum = new Suma();
    Operacion* Res = new Resta();
    Operacion* Mult = new Multiplica();
    Operacion* arr[3] = {Sum, Res, Mult};
    
    for(int i = 0; i < 3 ; i++){
        cout << (*Pf)(x,y,*(arr+i)) << endl;
    }
    
}