#include <iostream>
#include <thread>
using namespace std;

int main(){
    int*** A = new int**[3];
    for (int*** B = A ; B < A+3 ; B++){
        *B = new int*[3];
        for (int** C = *B; C < *B+3; C++){
            *C = new int[3];
            for(int* D = *C; D < *C+3; D++){
                *D = (B-A) +(C-*B)*10 + (D-*C)*100;
                cout << *D<< " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
}