/* 
 * File:   Flota.h
 * Author: Ivan
 *
 * Created on 26 de noviembre de 2024, 10:37
 */

#ifndef FLOTA_H
#define FLOTA_H

#include "NVehiculo.h"

#include <vector>
#include <iterator> 

class Flota {
private:
    vector <class NVehiculo> vflota;
public:
    Flota();
    Flota(const Flota& orig);
    virtual ~Flota();
    
    void cargaflota();
    void cargapedidos();
    void muestracarga();
};

#endif /* FLOTA_H */

