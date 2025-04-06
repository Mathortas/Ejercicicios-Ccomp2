#include <iostream>
using namespace std;

void arrOrdenado(int* arr, int* impar, int* par) {
    int size = (par - impar) * 2;
    int aux[size]; // Array auxiliar estático

    int* fin_impar = par; // Fin de los impares
    int* fin_arr = arr + size; // Fin del array original
    int k = 0; // Índice para aux

    while (impar < fin_impar && par < fin_arr) {
        if (*impar <= *par) {
            aux[k] = *impar;
            impar++;
        } else {
            aux[k] = *par;
            par++;
        }
        k++;
    }

   
    while (impar < fin_impar) {
        aux[k] = *impar;
        impar++;
        k++;
    }

    
    while (par < fin_arr) {
        aux[k] = *par;
        par++;
        k++;
    }

    
    int* p_arr = arr;
    for (int* p_aux = aux; p_aux != aux + size; p_aux++) {
        *p_arr = *p_aux;
        p_arr++;
    }
}

int main() {
    int arr[] = {1, 3, 5, 7, 2, 4, 6, 8};
    int* impar = arr;
    int* par = arr + 4;

    arrOrdenado(arr, impar, par);

    cout << "{ ";
    for (int* p = arr; p != arr + 8; p++) {
        cout << *p << " ";
    }
    cout << " }";
    
    return 0;
}
