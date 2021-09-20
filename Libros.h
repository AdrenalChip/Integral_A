/*
 *Proyecto Integral A
 *Jorge Guerrero Díaz
 *A01411752
 *20/09/2021
*/

/*
 *Clase Libros, se generan los objetos
 *Con nombre y numero de paginas 
 *y cuanta con las funciones para obtener valores y modificarlos
*/
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include "funciones.h"



#ifndef Libros_h
#define Libros_h

using namespace std;

class Libro {
    public:
    //Declaracion de atributos
        string name;
        int pages;
        string categoria[2];
    public:
    //Constructores
        Libro(string nombre,int paginas):name(nombre),pages(paginas){};
        Libro():name("-"),pages(0){};
    //Declaracion de funciones    
        string get_name();  
        int get_pages();
        void get_categoria();
        void set_categoria();
        void set_name();
        void set_pages();
        void set_names(string);
        void set_paginas(int);

};
/*
 * set_paginas  
 * @param int:paginas
 * @return
*/
void Libro::set_paginas(int paginas){
    pages=paginas;
}

/*
 * set_names  
 * @param string:nombre
 * @return
*/
void Libro::set_names(string nombre){
    name=nombre;
}

/*
 * set_name  
 * @param 
 * @return
*/
void Libro::set_name(){
    cout<<"Nombre del libro: ";
    cin>>name;
}
/*
 * set_pages 
 * @param 
 * @return
*/
void Libro::set_pages(){
    cout<<"Numero de paginas: ";
    cin>>pages;
}
/*
 * get_name  
 * @param 
 * @return string:name
*/
string Libro::get_name(){
    return name;
}
/*
 * get_pages  
 * @param 
 * @return int:pages
*/
int Libro::get_pages(){
    return pages;
}/*
void Libro::get_categoria(){
    vector <string> original2 (categoria,categoria + sizeof(categoria)/ sizeof(int));
    //cout<<arrayToString(original2);
}
void Libro::set_categoria(){
    cout<<"A que categorias pertenece el libro";
    cout<< "\n 1.-Fantasia, 2.-Terror, 3.-Sobrenatural";
    cout<<"4.-Aventura,5.-Romance,6.-Misterio \n";
    for (int i=0;i<10;i++){
        cout<<"Ingrese el numero correspondiente:";
        int x;
        cin>>x;
         if (x==1){
           categoria[i]="Fantasia";
       }else if (x==2){
           categoria[i]="Terror";
       }else if(x==3){
           categoria[i]="Sobrenatural";
       }else if (x==4){
           categoria[i]="Aventura";
       }else if (x==5){
           categoria[i]="Romance";
       }else if (x==6){
           categoria[i]="Misterio";
       }else{
           cout<< "Opcion Invalidad,ingrese nuevamente";
       }
        cout<<"Agregar una categoria mas? \n 1.-Si 2.-No";
        cin>>x;
        if (x==2){
            break;
        }
    }
}
*/
#endif