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
 * se van agregando libros, con nombre y numero de paginas, y sus categorias
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
         oc[i].set_cantidad();
         cout<<"Cuantas categorias agregaras? (Numero)";
         int num;
         cin>>num;
         cout<<"A que categoria pertenece ej:Accion,Magia,Terror";
         string cats[num];
        for(int j=0;j<num;j++){
            cout<<"Escribe:";
            cin>>cats[j];
        }
         oc[i].set_categoria(cats,num);
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
 * categoria
 * Busca entre los libros la categoria deseada  
 * @param  Libro, tamaño de los objetos
 * @return
*/
void categoria(Libro oc[],int y){
    cout<<"Escoge categoria (Escribe el nombre, 1 solo una a la vez)\n";
    cout<<"Fantasia,Misterio,Magia,Adolescentes,Mitologia,Ficcion,Accion,Aventura,Novela,Religion,Thriller";
    string x;
    cin>>x;
    cout<<"Libros con dicha categoria:\n";
    for(int i=0;i<y;i++){
        oc[i].searching(x);
    }

}
/*
 * catalogo
 * menu donde se imprime e ordena por numero de paginas los libros, y puedes buscar por categorias 
 * @param Libro, int:tamaño 
 * @return
*/
void catalogo(Libro oc[],int y){
    int flag=0;
    while (flag==0){
        cout<<"Welcome to Catalog\n Que desea hacer? \n 1.-Imprimir libros \n 2.-Ordenar por paginas \n 3.-Ordenar por cantidad en stock \n 4.-Buscar por categoria \n 5.-Salir del Catalogo \n";
       int x;
       cin>>x;
       if (x==1){
            for (int i=0;i<y;i++){
            cout<<i+1<<".-"<<oc[i].get_name()<<" pages: "<<oc[i].get_pages()<<"\n"<<"Tags: "<<"\n";
            oc[i].get_categoria();
            cout<<"\n";
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
       }else if (x==3){
           int x=cantidad_tree(oc,y);
        }else if (x==4){
           categoria(oc,y);
       }else if(x==5){
           flag=1;
       }else{
           cout<< "Opcion Invalidad,ingrese nuevamente";
       }
   }
}

int cantidad_tree(Libro oc[],int y){
    BST<int> bst;
    //generate bst
    int max=oc[0].get_cantidad();
    int ct=oc[0].get_cantidad();
    for (int i=0;i<y;i++){
        if (max<oc[i].get_cantidad()){
            max=oc[i].get_cantidad();
        }else if (max>oc[i].get_cantidad()){
        }
        ct=oc[i].get_cantidad();
        bst.add(ct);
        }
    bool x=bst.find(max);
    if (x){
        for (int i=0;i<y;i++){
            if (max==oc[i].get_cantidad()){
                cout<<"The books with more copies is "<<oc[i].get_name()<<"\n";
            }
        }
    }
    int *orden;
    orden=bst.inorder();
    cout<<"Orden de menor a mayor cantidad ";
    for (int i=0;i<y;i++){
        for (int j=0;j<y;j++){
            if (oc[j].get_cantidad()==*(orden+i)){
                cout<<oc[j].get_name()<<" ";
            }
        }
        cout<<*(orden+i);
    }
    return y;
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
     oc[0].set_cantidads(10);
     string cats0[4]={"Fantasia","Magia","Adolescentes",};
     oc[0].set_categoria(cats0,4);
    
     oc[1].set_names("PercyJackson");
     oc[1].set_paginas(377);
     oc[1].set_cantidads(5);
     string cats1[4]={"Fantasia","Magia","Adolescentes","Mitologia"};
     oc[1].set_categoria(cats1,4);

     oc[2].set_names("HungerGames");
     oc[2].set_paginas(374);
     oc[2].set_cantidads(12);
     string cats2[3]={"Ficcion","Adolescentes","Accion"};
     oc[2].set_categoria(cats2,3);

     oc[3].set_names("ElSalvaje");
     oc[3].set_paginas(696);
     oc[3].set_cantidads(7);
     string cats3[3]={"Ficcion","Novela","Aventura"};
     oc[3].set_categoria(cats3,3);

     oc[4].set_names("Bible");
     oc[4].set_paginas(1200);
     oc[4].set_cantidads(2);
     string cats4[1]={"Religion"};
     oc[4].set_categoria(cats4,1);

     oc[5].set_names("TheAnalyst");
     oc[5].set_paginas(521);
     oc[5].set_cantidads(9);
     string cats5[3]={"Ficcion","Thriller","Magia"};
     oc[5].set_categoria(cats5,3);
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
           tamano=cantidad_tree(oc,tamano);
       }else if (x==4){
        flag=1;
       }else{
           cout<< "Opcion Invalidad,ingrese nuevamente";
       }
   }
   cout<<"Hasta luego";
}
