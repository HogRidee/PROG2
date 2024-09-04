/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 4 de septiembre de 2024, 16:10
 */

#include <iostream>

#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "Sobrecargas.h"

using namespace std;

int main(int argc, char** argv) {

    ifstream archLibros, archClientes;
    
    AperturaDeUnArchivoDeTextosParaLeer(archLibros, "Libros.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archClientes, "Cientes.csv");
    
    struct Libro *arrLibros = nullptr;
    arrLibros = new struct Libro[400];
    int i = 0;
    
    struct Cliente *arrClientes = nullptr;
    arrClientes = new struct Cliente[400];
    int j = 0;
    
    while(true){
        if(not (archLibros >> arrLibros[i])){
            strcpy(arrLibros[i].codigo, "FIN");
            break;
        }
        i++;
    }
    
    return 0;
}

