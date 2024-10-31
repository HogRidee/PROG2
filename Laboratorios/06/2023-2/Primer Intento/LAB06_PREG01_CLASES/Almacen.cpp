/* 
 * File:   Almacen.cpp
 * Author: Ivan
 * 
 * Created on 31 de octubre de 2024, 10:36
 */

#include "Almacen.h"

Almacen::Almacen() {
    cantidad_clientes = 0;
    cantidad_productos = 0;
}

Almacen::~Almacen() {
}

void Almacen::SetCantidad_productos(int cantidad_productos) {
    this->cantidad_productos = cantidad_productos;
}

int Almacen::GetCantidad_productos() const {
    return cantidad_productos;
}

void Almacen::SetCantidad_clientes(int cantidad_clientes) {
    this->cantidad_clientes = cantidad_clientes;
}

int Almacen::GetCantidad_clientes() const {
    return cantidad_clientes;
}