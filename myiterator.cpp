#include <iostream>
#include <thread>
using namespace std;

template<class T>
class MyIterator{
    T* it;
    public:
    MyIterator(T* ite) : it(ite) {}
    
    T operator*(){
        return *it;
    }
    
    void operator++(){
        ++it;
    }
    
    bool operator!=(MyIterator o){
        return it != o.it;
    }
    
			T* operator+(int a){
							return it +a;
			}
    
    
    
};

int main(){
    
    int* Arr = new int[10]; 
    MyIterator ite(Arr);
    MyIterator iteFin(Arr+10);
    int counter = 10;
    while(ite != iteFin){
        cout << *ite << endl;
        ++ite;
    }
}