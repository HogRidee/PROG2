/* 
 * File:   Furgon.h
 * Author: Ivan
 *
 * Created on 20 de noviembre de 2024, 10:36
 */

#ifndef FURGON_H
#define FURGON_H

#include "Vehiculo.h"

class Furgon: public Vehiculo {
private:
    int filas;
    int puertas;
public:
    Furgon();
    Furgon(const Furgon& orig);
    virtual ~Furgon();
    void SetPuertas(int puertas);
    int GetPuertas() const;
    void SetFilas(int filas);
    int GetFilas() const;
};

#endif /* FURGON_H */

