/* 
 * File:   Flota.h
 * Author: Ivan
 *
 * Created on 21 de noviembre de 2024, 8:47
 */

#ifndef FLOTA_H
#define FLOTA_H

#include "LVehiculos.h"

class Flota {
private:
    class LVehiculos lista;
public:
    Flota();
    Flota(const Flota& orig);
    virtual ~Flota();
    
    void cargaflota();
    void cargapedidos();
    void muestracarga();
};

#endif /* FLOTA_H */

