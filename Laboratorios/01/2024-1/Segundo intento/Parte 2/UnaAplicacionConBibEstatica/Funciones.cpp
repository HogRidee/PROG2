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
        if(archPedidos.eof()) break;
        archPedidos.get();
        archPedidos >> dni;
        archPedidos.get();
        while(true){
            archPedidos >> ws;
            archPedidos.get(libroPedido.codigoDelLibro, 8);
            if(libroPedido >> arrLibros){
                int pos = buscarCliente(arrClientes, dni);
                if(pos != -1)
                    if(arrClientes[pos] << libroPedido) ++arrClientes[pos];
            }
            if(archPedidos.get() == '\n') break;
        }
    }
}

int buscarCliente(struct Cliente *arrClientes, int dni){
    for(int i = 0; arrClientes[i].dni != 0; i++){
        if(arrClientes[i].dni == dni)
            return i;
    }
    return -1;
}

void emitirReporte(struct Libro *arrLibros, struct Cliente *arrClientes){
    ofstream archReporte;
    AperturaDeUnArchivoDeTextosParaEscribir(archReporte, "Reporte.txt");
    imprimirClientes(archReporte, arrClientes);
    imprimirLibros(archReporte, arrLibros);
}

void imprimirClientes(ofstream &archReporte, struct Cliente *arrClientes){
    archReporte << left << setw(40) << " " << "REPORTE DE CLIENTES" << endl;
    imprimirLinea(archReporte, 100, '=');
    for(int i = 0; arrClientes[i].dni != 0; i++){
        archReporte << arrClientes[i] << endl;
        imprimirLinea(archReporte, 100, '-');
    }
}

void imprimirLinea(ofstream &arch, int n, char c){
    for(int i = 0; i < n; i++)
        arch.put(c);
    arch << endl;
}

void imprimirLibros(ofstream &archReporte, struct Libro *arrLibros){
    archReporte << left << setw(40) << " " << "REPORTE DE LIBROS" << endl;
    imprimirLinea(archReporte, 100, '=');
    for(int i = 0; strcmp(arrLibros[i].codigo, "FIN") != 0; i++){
        archReporte << arrLibros[i] << endl;
        imprimirLinea(archReporte, 100, '-');
    }
}
