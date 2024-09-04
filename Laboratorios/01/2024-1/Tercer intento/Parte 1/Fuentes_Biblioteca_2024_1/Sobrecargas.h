/* 
 * File:   Sobrecargas.h
 * Author: Ivan
 *
 * Created on 4 de septiembre de 2024, 16:28
 */

#ifndef SOBRECARGAS_H
#define SOBRECARGAS_H

#include <fstream>
#include <cstring>

#include "Estructuras.h"

using namespace std;

bool operator >> (istream &in, struct Libro &libro);
bool operator >> (istream &in, struct Cliente &cliente);

#endif /* SOBRECARGAS_H */

