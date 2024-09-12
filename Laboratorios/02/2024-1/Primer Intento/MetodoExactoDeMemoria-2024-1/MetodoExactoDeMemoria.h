/* 
 * File:   MetodoExactoDeMemoria.h
 * Author: ivana
 *
 * Created on 11 de septiembre de 2024, 03:16 PM
 */

#ifndef METODOEXACTODEMEMORIA_H
#define METODOEXACTODEMEMORIA_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

void lecturaDeLibros (const char *filename,char ***&libros, int **&stock);
char ** leeLibro(ifstream &archLibros);
char *leerCadenaExacta(ifstream &arch, int n, char c);
int *leeStock(ifstream &archLibros);
void pruebaDeLecturaDeLibros (const char *filename, char ***libros, 
        int **stock);
void imprimirLinea(ofstream &archReporte, int n, char c);
void reporteLibros(ofstream &arch, char **libros);
void reporteStock(ofstream &archReporte, int *stock);
void atencionDePedidos(const char *filename, char ***&libros, int **&stock, 
        int **&pedidosClientes, char ***&pedidosLibros, bool **&pedidosAtendidos);
char ** leerLibrosPedido(ifstream &archPedidos);
char *leerLibro(ifstream &archPedidos);
int buscarCliente(int dni, int **buffPedCli);
int *crearCliente(int dni);
void reporteDeEntregaDePedidos (const char *filename, int **pedidosClientes, 
            char ***pedidosLibros, bool **pedidosAtendidos);

#endif /* METODOEXACTODEMEMORIA_H */

