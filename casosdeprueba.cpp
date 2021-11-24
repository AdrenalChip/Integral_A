#include <iostream>
#include "Libros.h"
#include "funciones.h"
#include "funciones2.h"
#include <vector>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;



int main(){
    Libro oc[100]; 
    int tamano;
    tamano=inicializar(oc,6);
    
    //// Bubble Sort
     int arr[tamano+1];
        for(int j=0;j<tamano;j++){
         arr[j]={oc[j].get_pages()};
        }
        vector<int> original1 (arr, arr + sizeof(arr) / sizeof(int) );
        Sorts <int> sorts;
        sorts.ordenaBurbuja(original1);
        arreglararray(original1,oc,tamano);

    //// BST TRESS
    vector<int> original1 (arr, arr + sizeof(arr) / sizeof(int) );
        Sorts <int> sorts;
        sorts.ordenaBurbuja(original1);
        arreglararray(original1,oc,tamano);
    /////Agregar libro

}