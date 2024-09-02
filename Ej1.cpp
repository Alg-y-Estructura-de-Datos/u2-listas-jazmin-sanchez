/*Implementar una función llamada “printLista” que reciba una lista y una posición “p” e
imprima los elementos de esa lista a partir de la posición “p”. No debe modificarse la lista
original. Ej: listaOriginal: 1->2->3->4->5->6->7->8->9->10 con p=5 Por pantalla se verá:
7->8->9->10*/
#include <iostream>
#include "Lista/Lista.h"
using namespace std;

void print(Lista <int> lista1, int c);

int main(){
    Lista <int> lista1;
    int a,b,c;

    cout<<"ingrese el tamanio de la lista: ";
    cin>>a;

    for(int i=0; i<a; i++){
        cout<<"Ingrese el valor de la posicion:  "<<i<<endl;
        cin>>b;
        lista1.insertarUltimo(b);
    }
    cout<<"Ingrese a partir de que numero quiere ver la lista: ";
    cin>>c;

    print(lista1,c);
    return 0;
}

void print(Lista <int> lista1, int c){
    int t= lista1.getTamanio();
    if(c>t || c<0){
        cout<<"tamano incorrecto\n\n";
    }

    for(int i=c;i<t;i++){
        cout<<lista1.getDato(i)<<"-->";
    }
}