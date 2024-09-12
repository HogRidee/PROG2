/* 
 * File:   main.cpp
 * Author: ivana
 *
 * Created on 11 de septiembre de 2024, 03:16 PM
 */

#include "MetodoExactoDeMemoria.h"

int main(int argc, char** argv) {

    char ***libros, ***pedidosLibros;
    int **stock, **pedidosClientes;
    bool **pedidosAtendidos;
    
    lecturaDeLibros ("Libros.csv",libros, stock);
    pruebaDeLecturaDeLibros ("ReporteDeLibrosInicial.txt" ,libros, stock);
    atencionDePedidos("Pedidos.txt", libros, stock, pedidosClientes, pedidosLibros,
            pedidosAtendidos);
    pruebaDeLecturaDeLibros ("ReporteDeLibrosFinal.txt", libros, stock);
    reporteDeEntregaDePedidos ("ReporteDeEntregaDePedisos.txt", pedidosClientes, 
            pedidosLibros, pedidosAtendidos);
    
    return 0;
}

