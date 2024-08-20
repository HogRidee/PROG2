#include "FuncionesFinal.h"

void leerLibros(ifstream &archLibros, struct Libro *arrLibros){
    int n = 0;
    while(true){
        if(not (archLibros >> arrLibros[n])){
            strcpy(arrLibros[n].codigo, "FIN");
            break;
        }
        n++;
    }
}

void leerClientes(ifstream &archClientes, struct Cliente *arrClientes){
    int n = 0;
    while(true){
        if(not (archClientes >> arrClientes[n])){
            break;
        }
        n++;
    }
}

void leerPedidos(ifstream &archPedidos, struct Libro *arrLibros, 
        struct Libro *arrClientes){
    
}