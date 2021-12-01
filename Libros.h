/*
 *Proyecto Integral A
 *Clase Libros
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
        int cantidad;
    public:
    //Constructores
        Libro(string nombre,int paginas,int cants):name(nombre),pages(paginas),cantidad(cants){};
        Libro():name("-"),pages(0){};
        Libro(string nombre,int paginas):name(nombre),pages(paginas),cantidad(1){};
    //Declaracion de funciones    
        string get_name();  
        int get_pages();
        void get_categoria();
        void set_categoria(string cat[],int y);
        void set_name();
        void set_pages();
        void set_names(string);
        void set_paginas(int);
        string searching(string);
        void set_cantidad();
        int get_cantidad();
        void set_cantidads(int);

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
 *set_cantidad
 *@param
 *return
*/
void Libro::set_cantidad(){
    cout<<"Cuantas copias de este libro?";
    int x;
    cin>>x;
    cantidad=cantidad+x;
}
void Libro::set_cantidads(int cantidads){
    cantidad=cantidads;
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

int Libro::get_cantidad(){
    return cantidad;
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

string Libro::searching(string cat){
    stringstream aux;
    int x=cats.search(cat);
    if (x !=-1){
        aux<<name<<"\n";
    }
    return aux.str();
}

#endif
