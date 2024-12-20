/* 
 * File:   Semipresencial.h
 * Author: Ivan
 *
 * Created on 4 de noviembre de 2024, 11:28
 */

#ifndef SEMIPRESENCIAL_H
#define SEMIPRESENCIAL_H

#include "Alumno.h"

class Semipresencial : public Alumno{
private:
    double descuento;
    double total;
public:
    Semipresencial();
    Semipresencial(const Semipresencial& orig);
    virtual ~Semipresencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    
    void leerDatos(ifstream &arch);
    void actualiza(double monto);
    void imprime(ofstream &arch);
};

#endif /* SEMIPRESENCIAL_H */

