/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 17 de septiembre de 2024, 12:53
 */

#include "MetodoExactoDeMemoria.h"

int main(int argc, char** argv) {

    char ***libros, ***pedidosLibros;
    int **stock, **pedidosClientes;
    bool **pedidosAtendidos;
    
    lecturaDeLibros("Libros.csv", libros, stock);
    pruebaDeLecturaDeLibros("ReporteDeLibrosInicial.txt", libros, stock);
    
    atencionDePedidos("Pedidos.txt", libros, stock, pedidosClientes, pedidosLibros, 
            pedidosAtendidos);
    
    return 0;
}

