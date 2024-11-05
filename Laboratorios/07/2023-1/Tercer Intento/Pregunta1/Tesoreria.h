/* 
 * File:   Tesoreria.h
 * Author: Ivan
 *
 * Created on 5 de noviembre de 2024, 11:16
 */

#ifndef TESORERIA_H
#define TESORERIA_H

#include "Escala.h"
#include "Presencial.h"
#include "Semipresencial.h"
#include "Virtual.h"

using namespace std;

class Tesoreria {
private:
    class Presencial lpresencial[100];
    class Semipresencial lsemipresencial[100];
    class Virtual lvirtual[100];
    class Escala lescala[5];
public:
    Tesoreria();
    Tesoreria(const Tesoreria& orig);
    virtual ~Tesoreria();
    
    void cargaescalas();
    void cargaalumnos();
    void actualiza(double cred);
    void imprime();
    void imprimirLinea(ofstream &arch, int n, char c);
};

#endif /* TESORERIA_H */

