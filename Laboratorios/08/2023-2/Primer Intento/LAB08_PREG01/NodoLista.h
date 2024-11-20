/* 
 * File:   NodoLista.h
 * Author: Ivan
 *
 * Created on 20 de noviembre de 2024, 10:37
 */

#ifndef NODOLISTA_H
#define NODOLISTA_H

#include "Vehiculo.h"

class NodoLista {
private:
    class Vehiculo *unidad;
    class NodoLista *sig;
public:
    NodoLista();
    NodoLista(const NodoLista& orig);
    virtual ~NodoLista();
};

#endif /* NODOLISTA_H */

