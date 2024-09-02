#include <iostream>
#include <string>
#include "Lista/ListaDoble.h"
using namespace std;

void paginaActual(const ListaDoble<string> & historial, int posActual){
    if(posActual>= 0 && posActual<historial.getTamanio()){
        cout<<"pagina actual: "<<historial.getDato(posActual);
    }
    else{
        cout<<"No hay ninguna pagina actual\n";
    }
}
void retroceder(ListaDoble<string> &historial, int & posActual){
    if(posActual>0){
        --posActual;
        paginaActual(historial, posActual);
    }
    else{
        cout << "No hay paginas anteriores en el historial.\n";
    }
}

void adelantar(ListaDoble<string> &historial, int &posActual){
    if(posActual>=0 && posActual<historial.getTamanio()-1){
        ++posActual;
        paginaActual(historial, posActual);
    }
    else{
        cout << "No hay paginas siguientes en el historial.\n";
    }
}

void mostrarHistorial(ListaDoble<string>& historial){
    historial.imprimir();
}

void anadirPagina(ListaDoble<string>& historial, int& posActual) {
    string url;
    cout << "Ingrese la URL de la pagina: ";
    getline(cin, url);
    historial.insertarUltimo(url);
   
    if (historial.getTamanio() == 1) {
        posActual = 0;
    } else {
        posActual = historial.getTamanio() - 1;
    }
}

void mostrarMenu() {
    cout << "Menu:" << endl;
    cout << "1. Anadir pagina" << endl;
    cout << "2. Mostrar historial" << endl;
    cout << "3. Retroceder" << endl;
    cout << "4. Avanzar" << endl;
    cout << "5. Salir" << endl;
}

int main() {
    ListaDoble<string> historial;
    int posicionActual = -1;
    int opcion;

    do {
        paginaActual(historial, posicionActual);
        cout<<endl;
        mostrarMenu();
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // Para ignorar el salto de línea después de la entrada de número

        switch (opcion) {
            case 1:
                anadirPagina(historial, posicionActual);
                break;
            case 2:
                mostrarHistorial(historial);
                break;
            case 3:
                retroceder(historial, posicionActual);
                break;
            case 4:
                adelantar(historial, posicionActual);
                break;
            case 5:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 5);

    return 0;
}