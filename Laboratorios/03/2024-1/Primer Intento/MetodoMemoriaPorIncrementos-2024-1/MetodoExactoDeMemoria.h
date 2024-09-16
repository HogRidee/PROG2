/* 
 * File:   MetodoExactoDeMemoria.h
 * Author: Ivan
 *
 * Created on 16 de septiembre de 2024, 11:15
 */

#ifndef METODOEXACTODEMEMORIA_H
#define METODOEXACTODEMEMORIA_H

#define INCREMENTO 5

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

void lecturaDeLibros(const char *filename,char ***&libros, int **&stock);
char *leerCadena(ifstream &arch, int n, char c);
void aumentarEspacios(char ***&libros, int **&stock, int &numDat, int &cap);
char **crearLibro(char *codigo, char *titulo, char *autor);
int *crearStock(int stock);
void pruebaDeLecturaDeLibros(const char *filename, char ***libros, int **stock);
void imprimirLibro(ofstream &arch, char **libro);
void imprimirStock(ofstream &arch, int *stock);
void imprimirLinea(ofstream &arch, int n, char c);
void atencionDePedidos(const char *filename, char ***libros, int **stock, 
        int **&pedidosClientes, char ***&pedidosLibros, bool **&pedidosAtendidos);
int buscarCliente(int dni, int **pedidosClientes);
void aumentarEspacios(int **&pedidosClientes, int &numDat, int &capacidad);
void crearCliente(int *&pedido, int dni);
void crearPedido(ifstream &archPedidos, int *&pedido, int &nD, int &cap);
void actualizarCliente(int *&pedido, int codigo, int &nd, int &cap);
void aumentarEspacios(int *&pedido, int &nd, int &cap);
void aumentarEspacios(char ***&pedidosLibros, bool **&pedidosAtendidos, int &capPedidos, 
        int codigo);
void procesarPedidos(ifstream &archPedidos, char **&pedidosLibros, bool *&pedidosAtendidos, 
        char ***libros, int **stock);
void aumentarEspacios(char **&pedidosLibros, bool *&pedidosAtendidos, int &nd, int &cap);
int buscarLibro(char *codigo, char ***libros);
void actualizarStock(int *stock, bool &pedidosAtendidos);
void ordenarPedidosClientes(int **pedidosClientes);
void qSort(int **pedidosClientes, int izq, int der);
void cambiar(int *&datoI, int *&datoK);
void reporteDeEntregaDePedidos (const char *filename, int **pedidosClientes,
            char ***pedidosLibros, bool **pedidosAtendidos);
void imprimirPedido(ofstream &arch, int pedido, char ***pedidosLibros, bool **pedidosAtendidos);

#endif /* METODOEXACTODEMEMORIA_H */

