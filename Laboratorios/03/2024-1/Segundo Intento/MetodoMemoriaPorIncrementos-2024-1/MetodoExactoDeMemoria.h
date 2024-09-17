/* 
 * File:   MetodoExactoDeMemoria.h
 * Author: Ivan
 *
 * Created on 16 de septiembre de 2024, 16:55
 */

#ifndef METODOEXACTODEMEMORIA_H
#define METODOEXACTODEMEMORIA_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

#define INCREMENTO 5

using namespace std;

void lecturaDeLibros(const char *filename, char ***&libros, int **&stock);
char *leerCadena(ifstream &arch, int n, char c);
void aumentarEspacios(char ***&libros, int **&stock, int &nd, int &cap);
char **asignarLibro(char *codigo, char *titulo, char *autor);
int *asignarStock(int stockD);
void pruebaDeLecturaDeLibros(const char *filename, char ***libros, int **stock);
void atencionDePedidos(const char *filename, char ***libros, int **stock, 
        int **&pedidosClientes, char ***&pedidosLibros, bool **&pedidosAtendidos);
void aumentarEspacios(int **&pedidosClientes, int &nd, int &cap);
int buscarCliente(int **pedidosClientes, int dni);
void crearCliente(int *&pedidosClientes, int dni, int &numDat, int &caP);
void actualizarCliente(int *&pedido, int numPed, int &numDat, int &caP);
void aumentarEspacios(int *&pedido, int &numDat, int &caP);
void aumentarEspacios(char ***&pedidosLibros, bool **&pedidosAtendidos, int numPed, int &cp);
void leerPedidos(ifstream &arch, char **&libross, bool *&pedidos, char ***libros, 
        int **stock);
void aumentarEspacios(char **&libros, bool *&pedidos, int &nd, int &cap);
int buscarLibro(char *codigo, char ***libros);
void ajustarStock(int *stock, bool &pedido);
void ordenarPedidosClientes(int **pedidosClientes);
void qSort(int **pedidosClientes, int izq, int der);
void cambiar(int *&datosI, int *&datosK);
void reporteDeEntregaDePedidos(const char *filename, int **pedidosClientes, 
            char ***pedidosLibros, bool **pedidosAtendidos);
void imprimirLinea(ofstream &arch, int n, char c);
void imprimirPedido(ofstream &arch, char **libros, bool *pedidos);

#endif /* METODOEXACTODEMEMORIA_H */

