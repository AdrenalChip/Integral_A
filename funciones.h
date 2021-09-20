/*
 *Proyecto Integral A
 *Jorge Guerrero Díaz
 *A01411752
 *20/09/2021
*/

/*
 * Sorts
 * Archivo para ordenamiento de vectores con sus funciones pertinentes
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <string>
#ifndef sorts_h
#define sorts_h
using namespace std;

template <class T>
class Sorts{
	//Declaracion de funciones
    private:
     void swap(vector<T> &, int,int);
    public:
     void ordenaBurbuja( vector<T>&);
	

};
/*
 * swap 
 * @param vector:&v, int:posicion, int: posicion
 * @return
*/
template <class T>
void Sorts<T>::swap(vector<T> &v , int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
};
/*
 * ordenaBurbuja  
 * @param vector:&v
 * @return
*/
template <class T>
void Sorts<T>::ordenaBurbuja( vector<T>&v){
	for (int i= v.size()-1; i> 0; i--){
		for (int j=0; j<i; j++)
		if (v[j]>v[j+1]){
			swap(v,j,j+1);
		}
	}

};

#endif