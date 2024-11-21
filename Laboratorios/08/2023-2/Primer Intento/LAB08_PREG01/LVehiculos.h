/* 
 * File:   LVehiculos.h
 * Author: Ivan
 *
 * Created on 20 de noviembre de 2024, 10:39
 */

#ifndef LVEHICULOS_H
#define LVEHICULOS_H

#include "NodoLista.h"

class LVehiculos {
private:
    class NodoLista *lini;
    class NodoLista *lfin;
public:
    LVehiculos();
    LVehiculos(const LVehiculos& orig);
    virtual ~LVehiculos();
    
    void elimina();
    void inserta(ifstream &arch, char tipo);
    void imprime(ofstream &arch);
};

#endif /* LVEHICULOS_H */

