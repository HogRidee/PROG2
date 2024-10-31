/* 
 * File:   Producto.h
 * Author: Ivan
 *
 * Created on 31 de octubre de 2024, 10:22
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
 
class Producto {
private:
    char *codigo;
    char *descripcion;
    double precio;
    int stock;
    int clientes_servidos[100];
    int clientes_no_servidos[100];
    int cantidad_clientes_servidos;
    int cantidad_clientes_no_servidos;
public:
    Producto();
    ~Producto();
    void SetCantidad_clientes_no_servidos(int cantidad_clientes_no_servidos);
    int GetCantidad_clientes_no_servidos() const;
    void SetCantidad_clientes_servidos(int cantidad_clientes_servidos);
    int GetCantidad_clientes_servidos() const;
    void SetStock(int stock);
    int GetStock() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetDescripcion(char* des);
    void GetDescripcion(char *des) const;
    void SetCodigo(char* cod);
    void GetCodigo(char *cod) const;
};

bool operator >> (ifstream &arch, class Producto &producto);

#endif /* PRODUCTO_H */

