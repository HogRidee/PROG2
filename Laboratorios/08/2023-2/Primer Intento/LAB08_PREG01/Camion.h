/* 
 * File:   Camion.h
 * Author: Ivan
 *
 * Created on 20 de noviembre de 2024, 10:35
 */

#ifndef CAMION_H
#define CAMION_H

#include "Vehiculo.h"

class Camion: public Vehiculo {
private:
    int ejes;
    int llantas;
public:
    Camion();
    Camion(const Camion& orig);
    virtual ~Camion();
    void SetLlantas(int llantas);
    int GetLlantas() const;
    void SetEjes(int ejes);
    int GetEjes() const;
};

#endif /* CAMION_H */

