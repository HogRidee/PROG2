/* 
 * File:   ProductoEntregado.h
 * Author: Ivan
 *
 * Created on 31 de octubre de 2024, 10:14
 */

#ifndef PRODUCTOENTREGADO_H
#define PRODUCTOENTREGADO_H

#include <cstring>

class ProductoEntregado {
private:
    char *codigo;
    double precio;
public:
    ProductoEntregado();
    ~ProductoEntregado();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigo(char* cod);
    void GetCodigo(char *) const;
};

#endif /* PRODUCTOENTREGADO_H */

