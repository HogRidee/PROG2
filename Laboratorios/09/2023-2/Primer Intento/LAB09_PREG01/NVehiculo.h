/* 
 * File:   NVehiculo.h
 * Author: Ivan
 *
 * Created on 26 de noviembre de 2024, 10:36
 */

#ifndef NVEHICULO_H
#define NVEHICULO_H

#include "Vehiculo.h"

class NVehiculo {
private:
    class Vehiculo *unidad;
public:
    NVehiculo();
    NVehiculo(const NVehiculo& orig);
    virtual ~NVehiculo();
    
    void asignaMemoria(char tipo);
    void lee(ifstream &arch);
};

#endif /* NVEHICULO_H */

