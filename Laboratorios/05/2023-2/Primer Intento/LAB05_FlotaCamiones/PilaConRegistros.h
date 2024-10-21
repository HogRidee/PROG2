/* 
 * File:   PilaConRegistros.h
 * Author: Ivan
 *
 * Created on 21 de octubre de 2024, 12:42
 */

#ifndef PILACONREGISTROS_H
#define PILACONREGISTROS_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

void *leeregistro(ifstream &arch);
char *leerCadena(ifstream &arch,int n, char c);
double calcularegistro(void *dato);
void imprimeregistro(ofstream &arch, void *dato);
int cmpregistro(const void *a, const void *b);

#endif /* PILACONREGISTROS_H */

