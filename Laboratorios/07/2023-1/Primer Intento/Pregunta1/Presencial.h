/* 
 * File:   Presencial.h
 * Author: Ivan
 *
 * Created on 4 de noviembre de 2024, 11:25
 */

#ifndef PRESENCIAL_H
#define PRESENCIAL_H

#include "Alumno.h"

class Presencial : public Alumno{
private:
    double recargo;
    double total;
public:
    Presencial();
    Presencial(const Presencial& orig);
    virtual ~Presencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetRecargo(double recargo);
    double GetRecargo() const;
    
    void leerDatos(ifstream &arch);
    void actualiza(double monto);
    void imprime(ofstream &arch);
};

#endif /* PRESENCIAL_H */

