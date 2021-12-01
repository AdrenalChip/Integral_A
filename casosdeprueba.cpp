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
    string ans= arreglararray(original1,oc,tamano);
    string answer="1-HarryPotter\n2-HungerGames\n3-PercyJackson\n4-TheAnalyst\n5-ElSalvaje\n6-Bible\n";
    cout << "\n" <<"Esperada:\n" << answer << "\nPrograma:\n" << ans << "\n";
    cout <<	(!answer.compare(ans) ? "success\n" : "fail\n");

    //// BST TRESS
    string anstre = cantidad_tree(oc,tamano);
    string answertre= "HarryPotter: 1 Bible: 2 PercyJackson: 5 ElSalvaje: 7 TheAnalyst: 9 HarryPotter: 1 ";
    cout << "\n" <<"Esperada:\n" << answertre << "\nPrograma:\n" << anstre << "\n";
    cout <<	(!answertre.compare(anstre) ? "success\n" : "fail\n");

    //// Eliminar Libro
    string x="HarryPotter";
    stringstream books;
    int i;
    for (i=0; i<tamano; i++)
        if (oc[i].get_name() == x)
            break;
        if (i < tamano){
        tamano = tamano - 1;
        for (int j=i; j<tamano; j++)
        oc[j] = oc[j+1];
        } 
    
    for (int i=0;i<tamano;i++){
            books<<i+1<<".-"<<oc[i].get_name();
            books<<"\n";
    }
    string ansbook= "1.-PercyJackson\n2.-HungerGames\n3.-ElSalvaje\n4.-Bible\n5.-TheAnalyst\n";
    cout << "\n" <<"Esperada:\n" << ansbook << "\nPrograma:\n" << books.str() << "\n";
    cout <<	(!ansbook.compare(books.str()) ? "success\n" : "fail\n");
    
    ///ADJACENCY LIST
    string y="Fantasia";
    stringstream cats;
    for(int i=0;i<tamano;i++){
        cats<<oc[i].searching(y);
    }
    string anscats="PercyJackson\n";
    cout << "\n" <<"Esperada:\n" << anscats << "\nPrograma:\n" << cats.str() << "\n";
    cout <<	(!anscats.compare(cats.str()) ? "success\n" : "fail\n");
    
}
