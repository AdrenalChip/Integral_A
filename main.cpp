/*
 *Proyecto Integral A
 *Jorge Guerrero Díaz
 *A01411752
 *20/09/2021
*/

/*
 *Main que contiene las funciones del menu, entre las cuales estan
 *imprimir los datos de los libros, agregar libros e eliminar libros
 *dentro de la funcion catalogo se encuentra otro apartado para imprimir y ordenar por
 *numero de paginas 
*/
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "funciones.h"
#include "Libros.h"

using namespace std;

/*
 * arreglararray
 * toma el vector obtenido de numeros de paginas
 * y busca esos valores dentro de la lista de objetos
 * y cuando los obtiene imprime en pantalla el orden de los libros  
 * @param vector &v, Libro, tamaño de los objetos
 * @return
*/
template <class T>
void arreglararray(vector <T> &v,Libro oc1[],int x){
    string aux[v.size()];
    for(int i=0; i<x; i++){
		for(int j=0; j<x; j++){
            if (v[i]==oc1[j].get_pages()){
                aux[i]=oc1[j].get_name();
                cout<<i+1<<"-"<<aux[i]<<"\n";
                }
        }
    }
}

/*
 * agregar_libro
 * Un ciclo en el cual dependiendo del usuario
 * se van agregando libros, con nombre y numero de paginas
 * @param Libro, int:tamaño del arreglo 
 * @return int:nuevo tamaño del arreglo
*/
int agregar_libro(Libro oc[],int y){
    cout<< "How many books you wish to add? ";
    int x; 
    cin>>x; 
    int z=y+x;
    oc[z]; 
     for(int i=y; i < z; i++){ 
         oc[i].set_name();
         oc[i].set_pages();
         //oc[i].set_categoria();
     }
    
    return z;
    
}

/*
 * eliminar_libro
 * Pregunta al usuario que libro desea eliminar
 * escribiendo el nombre exacto y procede a buscarlo y 
 * modificar el array de objetos clase Libro
 * @param Libro, int:tamaño del arreglo
 * @return int:nuevo tamaño del arreglo
*/
int eliminar_libro(Libro oc[],int y){
    cout<<"Which book do you want to erase? (Write exact name,just the name) \n";
    for(int i=0;i<y;i++){
        cout<<i+1;
        cout<<".- ";
        cout<<oc[i].get_name();
        cout<<"\n";
    }
    string x;
    cin>>x;
    int i;
    for (i=0; i<y; i++)
        if (oc[i].get_name() == x)
            break;
 

        if (i < y){
        y = y - 1;
        for (int j=i; j<y; j++)
        oc[j] = oc[j+1];
        } 
return y;
}
/*
 * catalogo
 * menu donde se imprime e ordena por numero de paginas los libros 
 * @param Libro, int:tamaño 
 * @return
*/
void catalogo(Libro oc[],int y){
    int flag=0;
    while (flag==0){
        cout<<"Welcome to Catalog\n Que desea hacer? \n 1.-Imprimir libros \n 2.-Ordenar por paginas \n 3.-Salir del Catalogo \n";
       int x;
       cin>>x;
       if (x==1){
            for (int i=0;i<y;i++){
            cout<<i+1<<".-"<<oc[i].get_name()<<" pages: "<<oc[i].get_pages()<<"\n";
            }
       }else if (x==2){
           int arr[y+1];
        for(int j=0;j<y;j++){
         arr[j]={oc[j].get_pages()};
        }
        vector<int> original1 (arr, arr + sizeof(arr) / sizeof(int) );
        Sorts <int> sorts;
        sorts.ordenaBurbuja(original1);
        arreglararray(original1,oc,y);
       }else if(x==3){
           flag=1;
       }else{
           cout<< "Opcion Invalidad,ingrese nuevamente";
       }
   }
}
/*
 * inicializar
 * Funcion que inicializa el arreglo de libros, para que 
 * no empiece vacia y ya tenga objetos
 * @param Libro, int: tamaño
 * @return int:tamaño
*/
int inicializar(Libro oc[],int y){
     oc[0].set_names("HarryPotter");
     oc[0].set_paginas(223);
     oc[1].set_names("PercyJackson");
     oc[1].set_paginas(377);
     oc[2].set_names("HungerGames");
     oc[2].set_paginas(374);
     oc[3].set_names("ElSalvaje");
     oc[3].set_paginas(696);
     oc[4].set_names("Bible");
     oc[4].set_paginas(1200);
     oc[5].set_names("TheAnalyst");
     oc[5].set_paginas(521);
     
     
return y;
}
/*
 * main
 * Menu de donde se llaman todas las funciones
 * @param
 * @return 
*/
int main(){    
    Libro oc[100]; 
    int tamano;
    tamano=inicializar(oc,6);
   int flag=0;
   while (flag==0){
       cout<<"HOLA, BIENVENIDO A LA LIBRERIA MATA LA CHANGA \n Que desea hacer? \n 1.-Consultar catalogo \n 2.-Agregar Libro \n 3.-Eliminar un libro\n 4.-Salir\n";
       int x;
       cin>>x;
       if (x==1){
           catalogo(oc,tamano);
       }else if (x==2){
           tamano=agregar_libro(oc,tamano);
       }else if(x==3){
           tamano=eliminar_libro(oc,tamano);
       }else if (x==4){
        flag=1;
       }else{
           cout<< "Opcion Invalidad,ingrese nuevamente";
       }
   }
   cout<<"Hasta luego";
}