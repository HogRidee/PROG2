/* 
 * File:   Sobrecargas.h
 * Author: ivana
 *
 * Created on 27 de agosto de 2024, 04:07 PM
 */

#ifndef SOBRECARGAS_H
#define SOBRECARGAS_H

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

#include "Estructuras.h"

bool operator >> (istream &in, struct Libro &libro);
bool operator >> (istream &in, struct Cliente &cliente);
bool operator >> (struct LibroSolicitado &libroPedido, struct Libro *&arrLibros);
int buscarLibro(const char *codigoDelLibro, struct Libro *arrLibros);

#endif /* SOBRECARGAS_H */

