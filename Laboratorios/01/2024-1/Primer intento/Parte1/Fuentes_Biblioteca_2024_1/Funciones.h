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

#include "Estructuras.h"

using namespace std;

bool operator >> (istream &in, struct Libro &libro);
bool operator >> (istream &in, struct Cliente &cliente);
bool operator >> (struct LibroSolicitado &libroSolicitado, struct Libro *&arrLibros);
int buscarLibro(char *codigo, struct Libro *arrLibros);

#endif /* FUNCIONES_H */

