/* 
 * File:   FlotaGenerica.h
 * Author: Ivan
 *
 * Created on 21 de octubre de 2024, 12:43
 */

#ifndef FLOTAGENERICA_H
#define FLOTAGENERICA_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>

#include "PilaConEnteros.h"
#include "PilaConRegistros.h"

using namespace std;

void cargacamiones(void *&flota, int numcamiones, double pesomaximo, 
        void *(*lee)(ifstream &), double (*calcula)(void *), const char *filename);
bool pilavacia(void *pila);
void push(void *pila, void *dato);
void muestracamiones(void *flota, int numcamiones, void (*imprime)(ofstream &, void *), 
        const char *filename);

#endif /* FLOTAGENERICA_H */

