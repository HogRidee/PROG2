/* 
 * File:   main.cpp
 * Author: ivana
 *
 * Created on 27 de agosto de 2024, 03:55 PM
 */

#include <iostream>
#include <fstream>

using namespace std;

#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "Sobrecargas.h"

int main(int argc, char** argv) {

    ifstream archLibros, archClientes;
    
    AperturaDeUnArchivoDeTextosParaLeer(archLibros, "Libros.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archClientes, "Cientes.csv");
    
    struct Libro *arrLibros = nullptr;
    arrLibros = new struct Libro[300];
    int i = 0;
    
    struct Cliente *arrClientes = nullptr;
    arrClientes = new struct Cliente[300];
    int j = 0;
    
    while(true){
        if(not (archLibros >> arrLibros[i])){
            strcpy(arrLibros[i].codigo, "FIN");
            break;
        }
        i++;
    }
    
    while(true){
        if(not (archClientes >> arrClientes[j])){
            arrClientes[j].dni = 0;
            break;
        }
        j++;
    }
    
    struct LibroSolicitado libroPedido;
    
    libroPedido >> arrLibros;
    
    return 0;
}

