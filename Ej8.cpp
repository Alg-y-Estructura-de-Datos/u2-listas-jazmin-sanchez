#include <iostream>
#include <string>
#include "Lista/CircList.h"
#include <thread>
#include <chrono>

using namespace std;

template <typename T>
void mostrarfrases(CircList<T> &lista) {
    if(lista.esVacia()){
        cout<<"No hay frase para mostrar.\n";
        return ;
    }
    int pos=0;
    while(true){
        cout<<lista.getDato(pos);
       pos++;
       if(pos==lista.getTamanio()){
        pos=0;
       }
       this_thread::sleep_for(chrono::seconds(3)); // Retraso de 1 segundo
    }
}

int main(){
    CircList<string> lista;

    lista.insertarUltimo("Hola!\n");
    lista.insertarUltimo("mi nombre es jazmin\n");
    lista.insertarUltimo("mucho gusto\n");
    lista.insertarUltimo("chau!\n");
    cout<<"MOSTRANDO FRASES: \n\n";
    mostrarfrases(lista);
    return 0;
}