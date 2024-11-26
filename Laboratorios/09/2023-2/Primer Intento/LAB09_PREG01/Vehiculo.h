/* 
 * File:   Vehiculo.h
 * Author: Ivan
 *
 * Created on 26 de noviembre de 2024, 10:22
 */

#ifndef VEHICULO_H
#define VEHICULO_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

class Vehiculo {
private:
    int cliente;
    char *placa;
    double maxcarga;
    double actcarga;
public:
    Vehiculo();
    Vehiculo(const Vehiculo& orig);
    virtual ~Vehiculo();
    void SetActcarga(double actcarga);
    double GetActcarga() const;
    void SetMaxcarga(double maxcarga);
    double GetMaxcarga() const;
    void SetPlaca(char* plac);
    void GetPlaca(char *plac) const;
    void SetCliente(int cliente);
    int GetCliente() const;
    
    virtual void lee(ifstream &arch);
};

#endif /* VEHICULO_H */

