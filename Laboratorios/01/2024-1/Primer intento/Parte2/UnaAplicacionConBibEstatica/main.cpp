/* 
 * File:   main.cpp
 * Author: ivana
 *
 * Created on 20 de agosto de 2024, 04:44 PM
 */

#include <iostream>
#include <fstream>

using namespace std;

#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "Funciones.h"
#include "FuncionesFinal.h"

int main(int argc, char** argv) {

    ifstream archLibros, archClientes, archPedidos;
    
    AperturaDeUnArchivoDeTextosParaLeer(archLibros, "Libros.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archClientes, "Cientes.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archPedidos, "Pedidos.txt");
    
    struct Libro *arrLibros = nullptr;
    arrLibros = new struct Libro[300];
    
    struct Cliente *arrClientes = nullptr;
    arrClientes = new struct Cliente[100];
    
    leerLibros(archLibros, arrLibros);
    leerClientes(archClientes, arrClientes);
    leerPedidos(archPedidos, arrLibros, arrClientes);
    
    return 0;
}

