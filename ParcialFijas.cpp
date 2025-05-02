#include <iostream> 
using namespace std;

void printMatriz(int (*m)[4]) {
    for (int (*f)[4] = m; f < m + 4; f++, cout << endl) 
        for (int *e = *f; e < *f + 4; e++) 
            cout << *e << " ";
    
}


void KillRepeat(int (*m)[4]){
    for (int (*f)[4] = m; f < m + 3; f++){ 
        for (int *e = *f; e < *f + 4; e++){ 
            int* ptr1 = e;
            int* ptrRepeat = ptr1+4;
            int* inicio = *m+3;
            if ((*ptr1 == *ptrRepeat) ){
                *ptr1= 0;
                *ptrRepeat=0;
                while(ptr1 > inicio) {
                    int* ptr1Arriba = ptr1-4;
                    swap(*ptr1, *ptr1Arriba);
                    ptr1= ptr1Arriba;
                    int* ptrRepeatArriba = ptrRepeat -4;
                    swap(*ptrRepeat , *ptrRepeatArriba);
                    ptrRepeat = ptrRepeatArriba;
                }
                ptr1= e;
                ptrRepeat= ptr1+4;
                }
            }
        }
    }
    

 void PrintArr(int*p, int tam){
     cout << endl;
     for (int*ini = p ; ini< p+tam ; ini++){
         cout << *ini << " ";
     }
     cout << endl;
 }
 
 bool hayRepeticion(int *p, int tam){
     for(int* ini = p ; ini < p+tam; ini++){
         if (*ini == *(ini+1)){
             return true;
         }
     }
     return false;
 }
 void comerArray(int*& x, int& tam){
     if(!hayRepeticion(x, tam)){
         cout << "Ya comimos el array" << endl;
         return;
     }
     else{
         for(int* ini = x ; ini < x+tam; ini++){
             if ((*ini == *(ini+1)) && (*ini != *(ini+2)) && (*ini != 0)){
                 int* rep = ini+1;
                 *ini = 0;
                 *rep = 0;
                 int* ptrAux1 = ini;
                 int* ptrAux2 = rep;
                 while(ptrAux2 < x+tam-1){
                     swap(*ptrAux2 , *(ptrAux2+1));
                     ptrAux2++;
                     swap(*ptrAux1, *(ptrAux1+1));
                     ptrAux1++;
                 }
                 ptrAux1 = ini;
                 ptrAux2 = rep;
                 
             }
             else if ((*ini == *(ini+1)) && (*ini == *(ini+2)) && (*ini != 0)){
                 int* rep = ini+1;
                 int* rep2 = ini+2;
                 *ini = 0;
                 *rep = 0;
                 *rep2 = 0;
                 int* ptrAux1 = ini;
                 int* ptrAux2 = rep;
                 int* ptrAux3 = rep2;
                 while(ptrAux3 < x+tam-1){
                     swap(*ptrAux3 , *(ptrAux3+1));
                     ptrAux3++;
                     swap(*ptrAux2, *(ptrAux2+1));
                     ptrAux2++;
                     swap(*ptrAux1, *(ptrAux1+1));
                     ptrAux1++;
                 }
                 ptrAux1 = ini;
                 ptrAux2 = rep;
                 ptrAux2 = rep2;
             }
         }
         cout << "Array con repeticiones movidas en 0s" ;
         PrintArr(x, tam);
         cout << "/////////////"<<endl;
         int nuevoTam=0;
         for(int* nuevo = x ; nuevo < x+tam ; nuevo++){
             if (*nuevo != 0)
                nuevoTam++;
         }
         int* B = new int[nuevoTam]();
         int* dest = B;
         for(int* src = x; src < x + tam; src++) {
                if (*src != 0) {
                    *dest++ = *src;
                }
            }

         delete[] x;
         x = B;
         tam = nuevoTam;
         cout << "Array  sin repeticiones" << endl;
         PrintArr(x, tam);
         cout << "/////////////"<<endl;
         comerArray(x, tam);
        }
    }
 

int main(){
    int Matriz[4][4] = {{3,1,5,9},
                        {2,1,6,10},
                        {2,4,7,11},
                        {3,4,8,11}
    };
    cout <<" Esta es la parte de la matriz del stack" << endl;
    printMatriz(Matriz);
    KillRepeat(Matriz);
    cout << endl;
    printMatriz(Matriz);
    
    cout << "////////////////////" <<endl;
    
    int*A = new int[10]{1,3,2,2,3,5,5,3,1,5};
    cout << "Esta es la parte del array dinamico";
    int tam= 10;
    PrintArr(A, 10);
    comerArray(A, tam);
    PrintArr(A,tam);
    delete[] A;
}
