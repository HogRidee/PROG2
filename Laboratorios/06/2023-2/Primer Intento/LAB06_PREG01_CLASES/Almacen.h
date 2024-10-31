/* 
 * File:   Almacen.h
 * Author: Ivan
 *
 * Created on 31 de octubre de 2024, 10:36
 */

#ifndef ALMACEN_H
#define ALMACEN_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

#include "Cliente.h"
#include "Producto.h"

using namespace std;

class Almacen {
private:
    class Cliente arreglo_clientes[100];
    int cantidad_clientes;
    class Producto arreglo_productos[100];
    int cantidad_productos;
public:
    Almacen();
    ~Almacen();
    void SetCantidad_productos(int cantidad_productos);
    int GetCantidad_productos() const;
    void SetCantidad_clientes(int cantidad_clientes);
    int GetCantidad_clientes() const;
};

#endif /* ALMACEN_H */

