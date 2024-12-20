/* 
 * File:   NPedido.h
 * Author: Ivan
 *
 * Created on 26 de noviembre de 2024, 10:12
 */

#ifndef NPEDIDO_H
#define NPEDIDO_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

class NPedido {
private:
    char *codigo;
    int cantidad;
    double peso;
public:
    NPedido();
    NPedido(const NPedido& orig);
    virtual ~NPedido();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(char* cod);
    void GetCodigo(char *cod) const;
};

#endif /* NPEDIDO_H */

