/* 
 * File:   FuncionesRegistros.h
 * Author: Ivan
 *
 * Created on 9 de octubre de 2024, 10:19
 */

#ifndef FUNCIONESREGISTROS_H
#define FUNCIONESREGISTROS_H

#include "BibliotecaGenerica.h"

void *leeregistro(ifstream &arch);
char *leerCadena(ifstream &arch, int n, char c);
void imprimeregistro(ofstream &arch, void *dato);
int cmpregistro(const void *a, const void *b);

#endif /* FUNCIONESREGISTROS_H */

