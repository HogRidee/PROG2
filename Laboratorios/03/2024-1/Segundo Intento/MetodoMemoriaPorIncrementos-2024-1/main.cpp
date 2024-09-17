/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 16 de septiembre de 2024, 16:55
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
    pruebaDeLecturaDeLibros("ReporteDeLibrosFinal.txt", libros, stock);
    
    ordenarPedidosClientes(pedidosClientes);
    reporteDeEntregaDePedidos("ReporteDeEntregaDePedidos.txt", pedidosClientes, 
            pedidosLibros, pedidosAtendidos);
    
    return 0;
}

