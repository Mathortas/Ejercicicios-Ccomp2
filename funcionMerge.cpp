#include <iostream>
using namespace std;

void Merge(int *p, int *q) {
    int *fin = p + (q - p) * 2;
    while (p < q && q < fin) {
        if (*p < *q) {
            p++;
        } else {
            // Rotar elementos desde p hasta q
            for (int *r = p; r < q; r++) {
                swap(*r, *q);
            }
            q++;
            p++;
        }
    }
}
void imprimirArray(int *arr, int size) {
    for (int *ptr = arr; ptr < arr + size; ptr++) {
        cout << *ptr << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 3, 5, 7, 2, 4, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int *mitad = arr;
    while (mitad < arr + n && *mitad % 2 != 0) {
        mitad++;
    }
    cout << "Array original:" << endl;
    imprimirArray(arr, n);
    Merge(arr, mitad);
    cout << "Array ordenado:" << endl;
    imprimirArray(arr, n);
    
    return 0;
}
