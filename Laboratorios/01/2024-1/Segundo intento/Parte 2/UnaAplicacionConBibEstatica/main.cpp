/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 2 de septiembre de 2024, 13:29
 */

#include <iostream>

#include "Estructuras.h"
#include "Funciones.h"

using namespace std;

int main(int argc, char** argv) {

    struct Libro *arrLibros = nullptr;
    struct Cliente *arrClientes = nullptr;
    arrLibros = new Libro[300];
    arrClientes = new Cliente[100];
    
    leerLibros(arrLibros, "Libros.csv");
    leerClientes(arrClientes, "Cientes.csv");
    leerPedidos(arrLibros, arrClientes, "Pedidos.txt");
    emitirReporte(arrLibros, arrClientes);
    
    return 0;
}

