#include <iostream>

void merge(int* arr, int n) {

    bool empiezaConPares = (arr[0] % 2 == 0);
    //Puntero de referencia para no pasarse de par a impar o de impar a par o fuera de indice :V
    int* ptrSegundaMitad = arr;
    
    while (ptrSegundaMitad < arr + n && ((*ptrSegundaMitad % 2 == 0) == empiezaConPares)) {
        ptrSegundaMitad++;
    }
    
    // Crear array auxiliar
    int aux[n];
    int* ptrAux = aux;
    
    // Punteros para pares e impares
    int* ptr1 = arr;
    int* ptr2 = ptrSegundaMitad;
    
    // Comparar cual es menor, el menor lo manda al aux y de ahi avanzar el ptr del menor hasta el final
    while (ptr1 < ptrSegundaMitad && ptr2 < arr + n) {
        if (*ptr1 <= *ptr2) {
            *ptrAux++ = *ptr1++;
        } else {
            *ptrAux++ = *ptr2++;
        }
    }
    
    // Copiar los elementos restantes de pares/impares
    while (ptr1 < ptrSegundaMitad) {
        *ptrAux++ = *ptr1++;
    }
    
    // Copiar los elementos restantes de impares/pares
    while (ptr2 < arr + n) {
        *ptrAux++ = *ptr2++;
    }
    
    // Copiar del auxiliar al original
    for (int i = 0; i < n; i++) {
        arr[i] = aux[i];
    }
}

int main() {
    int arr[] = {2, 4 , 6 , 1 , 3 , 5 ,7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    
    std::cout << "Array original: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    merge(arr, n);
    
    std::cout << "Array ordenado: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
