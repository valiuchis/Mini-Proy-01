#include "ListArray.h"

int main(){
    
    int capacidad; // tamaño arreglo b
    int n_datos;
    std:: cout << "Ingrese el tamaño del arreglo: ";
    std:: cin >> capacidad;
    std:: cout << "Ingrese el numero de datos: ";
    std:: cin >> n_datos;
    ListArray l_a(capacidad);

    for(int i = 0; i < n_datos; i++){
        l_a.insert_right(i);
    }

    l_a.print();
    return 0;
    
}