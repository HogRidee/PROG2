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

void leerPedidos(ifstream &archPedidos, struct Libro *&arrLibros, 
        struct Cliente *&arrClientes){
    int dni;
    char buffer[10], c;
    while(true){
        struct LibroSolicitado libroPedido;
        archPedidos >> libroPedido.numeroDePedido;
        if(archPedidos.eof()) break;
        archPedidos.get();
        archPedidos >> dni;
        archPedidos.get();
        archPedidos >> ws;
        while(true){
            for(int i = 0; i < 7; i++){
                archPedidos.get(c);
                buffer[i] = c;
            }
            buffer[7] = '\0';
            strcpy(libroPedido.codigoDelLibro, buffer);
            archPedidos.get(c);
            if(c == '\n' or archPedidos.eof()) break;
            else archPedidos >> ws;
        }
    }
}