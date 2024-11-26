/* 
 * File:   Camion.h
 * Author: Ivan
 *
 * Created on 26 de noviembre de 2024, 10:26
 */

#ifndef CAMION_H
#define CAMION_H

#include "Vehiculo.h"
#include "NPedido.h"
#include <map>
#include <iterator>

class Camion : public Vehiculo{
private:
    int ejes;
    int llantas;
    map <int, class NPedido> mdeposito;
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

