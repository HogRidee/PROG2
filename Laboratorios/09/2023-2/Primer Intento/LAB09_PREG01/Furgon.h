/* 
 * File:   Furgon.h
 * Author: Ivan
 *
 * Created on 26 de noviembre de 2024, 10:33
 */

#ifndef FURGON_H
#define FURGON_H

#include "Vehiculo.h"
#include "NPedido.h"
#include <list>
#include <iterator>

class Furgon : public Vehiculo{
private:
    int filas;
    int puertas;
    list <class NPedido> pdeposito;
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

