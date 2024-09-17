/* 
 * File:   MetodoExactoDeMemoria.h
 * Author: Ivan
 *
 * Created on 17 de septiembre de 2024, 12:54
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
char **crearLibro(char *codigo, char *titulo, char *autor);
int *crearStock(int stockD);
void aumentarEspacios(char ***&libros, int **&stock, int &nd, int &cap);
void pruebaDeLecturaDeLibros(const char *filename, char ***libros, int **stock);
void atencionDePedidos(const char *filename, char ***libros, int **stock, 
        int **&pedidosClientes, char ***&pedidosLibros, bool **&pedidosAtendidos);
int buscarCliente(int **pedidosClientes, int dni);
void aumentarEspacios(int **&pedidosClientes, int &nd, int &cap);
void crearCliente(int *&cliente, int dni, int &nC);
void actualizarCliente(int *&cliente, int numPed, int &nC, int &capC);
void aumentarEspacios(int *&cliente, int &nC, int &capC);
void aumentarEspacios(char ***&pedidosLibros, bool **&pedidosAtendidos, int &capP, 
        int numPed);

#endif /* METODOEXACTODEMEMORIA_H */

