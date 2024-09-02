/* 
 * File:   Funciones.h
 * Author: Ivan
 *
 * Created on 2 de septiembre de 2024, 13:31
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "Sobrecargas.h"

using namespace std;

void leerLibros(struct Libro *&arrLibros, const char *filename);
void leerClientes(struct Cliente *&arrClientes, const char *filename);
void leerPedidos(struct Libro *arrLibros, struct Cliente *&arrClientes, 
        const char *filename);

#endif /* FUNCIONES_H */

