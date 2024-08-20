/* 
 * File:   main.cpp
 * Author: ivana
 *
 * Created on 20 de agosto de 2024, 10:36 AM
 */

#include <iostream>
#include <fstream>

using namespace std;

#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "Funciones.h"

#define NLIBROS 300
#define NCLIENTES 60
#define NPEDIDOS 130

int main(int argc, char** argv) {
    
    ifstream archLibros, archClientes, archPedidos;
    
    AperturaDeUnArchivoDeTextosParaLeer(archLibros, "Libros.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archClientes, "Cientes.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archPedidos, "Pedidos.txt");
    
    struct Libro *arrLibros = nullptr;
    arrLibros = new struct Libro[NLIBROS];
    int nLibros = 0;
    
    while(true){
        if(not (archLibros >> arrLibros[nLibros])){
            strcpy(arrLibros[nLibros].codigo, "FIN");
            break;
        }
        nLibros++;
    }
    
    for(int i = 0; i < nLibros; i++){
        cout << arrLibros[i].codigo << " ";
        cout << arrLibros[i].tiltulo << " ";
        cout << arrLibros[i].autor << " ";
        cout << arrLibros[i].stock << " ";
        cout << arrLibros[i].precio << " " << endl;
    }
    
    struct Cliente *arrClientes = nullptr;
    arrClientes = new struct Cliente[NCLIENTES];
    int nClientes = 0;
    
    while(true){
        if(not (archClientes >> arrClientes[nClientes])){
            break;
        }
        nClientes++;
    }
    
    for(int i = 0; i < nClientes; i++){
        cout << arrClientes[i].dni << " ";
        cout << arrClientes[i].nombre << " " << endl;
    }
    
    struct LibroSolicitado libroPedido;
    strcpy(libroPedido.codigoDelLibro, arrLibros[0].codigo);
    libroPedido.numeroDePedido = 1;
    libroPedido.precio = 40.0;
    
    if(libroPedido >> arrLibros){
        
    }
    
    return 0;
}

