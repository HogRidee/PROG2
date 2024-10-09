/* 
 * File:   FuncionesEnteras.h
 * Author: Ivan
 *
 * Created on 9 de octubre de 2024, 13:50
 */

#ifndef FUNCIONESENTERAS_H
#define FUNCIONESENTERAS_H

#include "BibliotecaGenerica.h"

void *leenum(ifstream &arch);
void imprimenum(ofstream &arch, void *dato);
int cmpnum(const void *a, const void *b);

#endif /* FUNCIONESENTERAS_H */

