#include <iostream>
using namespace std;

class asc{
    public:
    bool operator()(int a , int b){
        return a < b;
    }
};

class desc{
    public:
    bool operator()(int a, int b){
        return a > b;
    }
};

template <class T>
class Iterador
{
    T* x;
    public:
    Iterador(T* a):x(a) {};

    void operator = (T* p){
        x=p;
    }

    void operator = (T a){
        *x=a;
    }

    bool operator < (T* p){
        return x<p;
    }

    bool operator > (T* p){
        return x>p;
    }

    T* operator ++ (int){
        x++;
        return x;}
        
    T* operator--(int){
        --x;
        return x;
    }

    T* operator+(int n) const {
        return x + n;}

    T& operator*() {
        return *x;}

    friend ostream  &operator<<(ostream &output, Iterador &it ){
        output<<*(it.x)<<" "; 
        return output;}

};

template<class T, class O>
class sort{
    public:

    O condicion;

    typedef Iterador<T> ite;

    void ordenar(T* inicio, T* final)
    {
        for( ite itr=final; itr>inicio; itr--)
        {
            for( ite itr2 = inicio;itr2 < final-1; itr2++)
            {
                if(condicion(*itr2, *(itr2+1)))
                {
                    swap(*itr2, *(itr2+1)) ;
                }
            }
        }
    }

    void print(T* inicio, T* final){
        for(ite itr = inicio; itr< final; itr++){
            cout<<itr;
        }
    }
};


int main(){
    
    sort <int, asc> ordena_asc;
    sort <int, desc> ordena_des;

    int B[10]={3,5,91,8,1,7,2,4,19, 11}; 
    int C[10]={3,5,91,8,1,7,2,4,19, 11};
    ordena_asc.ordenar(B, B+10);
    ordena_asc.print(B, B+10);
    cout<<endl;
    ordena_des.ordenar(C, C+10);
    ordena_des.print(C, C+10);
}
