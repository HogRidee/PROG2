/* 
 * File:   FuncionesRegistros.h
 * Author: Ivan
 *
 * Created on 10 de octubre de 2024, 11:06
 */

#ifndef FUNCIONESREGISTROS_H
#define FUNCIONESREGISTROS_H

#include "BibliotecaGenerica.h"

void *leeregistro(ifstream &arch);
char *leerCadena(ifstream &arch, int n, char c);
void imprimeregistro(ofstream &arch, void *dato);
int cmpregistro(const void *a, const void *b);

#endif /* FUNCIONESREGISTROS_H */

