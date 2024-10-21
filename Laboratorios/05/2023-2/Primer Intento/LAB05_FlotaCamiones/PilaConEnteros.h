/* 
 * File:   PilaConEnteros.h
 * Author: Ivan
 *
 * Created on 21 de octubre de 2024, 12:42
 */

#ifndef PILACONENTEROS_H
#define PILACONENTEROS_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

void *leenumero(ifstream &arch);
double calculanumero(void *dato);
void imprimenumero(ofstream &arch, void *dato);
int cmpnumero(const void *a, const void *b);

#endif /* PILACONENTEROS_H */

