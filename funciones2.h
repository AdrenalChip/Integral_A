#include <vector>
#include <iostream>
#include "Libros.h"
#include "funciones.h"

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
                cout<<oc[j].get_name()<<": ";
            }
        }
        cout<<*(orden+i)<<" ";
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
     oc[0].set_cantidads(1);
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