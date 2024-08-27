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
            arrClientes[n].dni = 0;
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
            procesarPedido(libroPedido, arrLibros, arrClientes, dni);
            archPedidos.get(c);
            if(c == '\n' or archPedidos.eof()) break;
            else archPedidos >> ws;
        }
    }
}

void procesarPedido(struct LibroSolicitado libroPedido, struct Libro *&arrLibros, 
        struct Cliente *&arrClientes, int dni){
    if(libroPedido >> arrLibros){
        for(int i = 0; arrClientes[i].dni != 0; i++){
            if(arrClientes[i].dni == dni){
                arrClientes[i] << libroPedido;
            }
        }
    }
}

void imprimirReporte(ofstream &archReporte, struct Libro *arrLibros, 
        struct Cliente *arrClientes){
    archReporte << left << setw(30) << " " << "REPORTE DE PEDIDOS DE LIBROS"
            << endl;
    imprimirLinea(archReporte, 100, '=');
    for(int i = 0; i < arrClientes[i].dni != 0; i++){
        ++arrClientes[i];
        archReporte << arrClientes[i];
        imprimirLinea(archReporte, 100, '-');
    }
    archReporte << left << setw(30) << " " << "REPORTE DE LIBROS"
            << endl;
    imprimirLinea(archReporte, 100, '=');
    for(int i = 0; strcmp(arrLibros[i].codigo, "FIN") != 0; i++){
        archReporte << arrLibros[i];
        imprimirLinea(archReporte, 100, '-');
    }
}

void imprimirLinea(ofstream &arch, int n, char c){
    for(int i = 0; i < n; i++)
        arch.put(c);
    arch << endl;
}