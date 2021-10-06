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
        List<string> cats;
    public:
    //Constructores
        Libro(string nombre,int paginas):name(nombre),pages(paginas){};
        Libro():name("-"),pages(0){};
    //Declaracion de funciones    
        string get_name();  
        int get_pages();
        void get_categoria();
        void set_categoria(string cat[],int y);
        void set_name();
        void set_pages();
        void set_names(string);
        void set_paginas(int);
        void searching(string);

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
}

void Libro::get_categoria(){
    string x;
    x=cats.toString();
    cout<<x;
}
void Libro::set_categoria(string cat[],int y){ //tamaño y
    string x;
    for (int i=0;i<y;i++){
        x=cat[i];
        cats.insertion(x);
    }
}

void Libro::searching(string cat){
    int x=cats.search(cat);
    if (x !=-1){
        cout<<name<<"\n";
    }
}

#endif
