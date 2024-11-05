/* 
 * File:   Virtual.h
 * Author: Ivan
 *
 * Created on 5 de noviembre de 2024, 11:10
 */

#ifndef VIRTUAL_H
#define VIRTUAL_H

#include "Alumno.h"

class Virtual : public Alumno{
private:
    char *licencia;
    double total;
public:
    Virtual();
    Virtual(const Virtual& orig);
    virtual ~Virtual();
    void SetTotal(double total);
    double GetTotal() const;
    void SetLicencia(char* lic);
    void GetLicencia(char *lic) const;
    
    void leerDatos(ifstream &arch);
    void actualiza(double monto);
    void imprime(ofstream &arch);
};

#endif /* VIRTUAL_H */

