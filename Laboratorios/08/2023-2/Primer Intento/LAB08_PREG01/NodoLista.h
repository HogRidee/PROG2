/* 
 * File:   NodoLista.h
 * Author: Ivan
 *
 * Created on 20 de noviembre de 2024, 10:37
 */

#ifndef NODOLISTA_H
#define NODOLISTA_H

#include "Camion.h"
#include "Furgon.h"
#include "Vehiculo.h"

class NodoLista {
private:
    class Vehiculo *unidad;
    class NodoLista *sig;
public:
    NodoLista();
    NodoLista(const NodoLista& orig);
    virtual ~NodoLista();
    friend class LVehiculos;
    
    void asignaMemoria(char tipo);
    void leeDatos(ifstream &arch);
    void imprime(ofstream &arch);
};

#endif /* NODOLISTA_H */

