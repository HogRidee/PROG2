/* 
 * File:   FuncionesFinal.h
 * Author: ivana
 *
 * Created on 20 de agosto de 2024, 04:52 PM
 */

#ifndef FUNCIONESFINAL_H
#define FUNCIONESFINAL_H

#include <fstream>
#include <iostream>
#include <iomanip>

#include "Estructuras.h"
#include "Funciones.h"

using namespace std;

void leerLibros(ifstream &archLibros, struct Libro *arrLibros);
void leerClientes(ifstream &archClientes, struct Cliente *arrClientes);
void leerPedidos(ifstream &archPedidos, struct Libro *arrLibros, 
        struct Libro *arrClientes);

#endif /* FUNCIONESFINAL_H */

