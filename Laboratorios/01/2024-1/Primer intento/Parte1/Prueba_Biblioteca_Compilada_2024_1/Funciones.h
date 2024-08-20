/* 
 * File:   Funciones.h
 * Author: ivana
 *
 * Created on 20 de agosto de 2024, 10:48 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <fstream>
#include <iostream>
#include <cstring>
#include <iomanip>

#include "Estructuras.h"

using namespace std;

bool operator >> (istream &in, struct Libro &libro);
bool operator >> (istream &in, struct Cliente &cliente);
bool operator >> (struct LibroSolicitado &libroSolicitado, struct Libro *&arrLibros);
int buscarLibro(char *codigo, struct Libro *arrLibros);
bool operator << (struct Cliente &cliente, struct LibroSolicitado pedido);
struct Cliente& operator ++ (struct Cliente &cliente);
ostream& operator << (ostream &out, const struct Libro &libro);
ostream& operator << (ostream &out, const struct Cliente &cliente);
void imprimirLibrosEntregados(ostream &out, const struct Cliente &cliente);
void imprimirLibrosNoEntregados(ostream &out, const struct Cliente &cliente);

#endif /* FUNCIONES_H */

