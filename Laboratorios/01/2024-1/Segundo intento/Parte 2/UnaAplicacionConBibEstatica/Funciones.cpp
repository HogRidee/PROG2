#include "Funciones.h"

void leerLibros(struct Libro *&arrLibros, const char *filename){
    ifstream archLibros;
    AperturaDeUnArchivoDeTextosParaLeer(archLibros, filename);
    int i = 0;
    while(true){
        if(not (archLibros >> arrLibros[i])){
            strcpy(arrLibros[i].codigo, "FIN");
            break;
        }
        i++;
    }
}

void leerClientes(struct Cliente *&arrClientes, const char *filename){
    ifstream archClientes;
    AperturaDeUnArchivoDeTextosParaLeer(archClientes, filename);
    int i = 0;
    while(true){
        if(not (archClientes >> arrClientes[i])){
            arrClientes[i].dni = 0;
            break;
        }
        i++;
    }
}

void leerPedidos(struct Libro *arrLibros, struct Cliente *&arrClientes, 
        const char *filename){
    int dni;
    ifstream archPedidos;
    AperturaDeUnArchivoDeTextosParaLeer(archPedidos, filename);
    while(true){
        struct LibroSolicitado libroPedido;
        archPedidos >> libroPedido.numeroDePedido;
        archPedidos.get();
        archPedidos >> dni;
        archPedidos.get();
        while(true){
            archPedidos >> ws;
            archPedidos.get(libroPedido.codigoDelLibro, 8);
            cout << libroPedido.codigoDelLibro << endl;
            break;
        }
        break;
    }
}
