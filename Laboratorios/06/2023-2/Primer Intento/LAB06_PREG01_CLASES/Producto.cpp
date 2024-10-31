/* 
 * File:   Producto.cpp
 * Author: Ivan
 * 
 * Created on 31 de octubre de 2024, 10:22
 */

#include "Producto.h"

Producto::Producto() {
    cantidad_clientes_no_servidos = 0;
    cantidad_clientes_servidos = 0;
    codigo = nullptr;
    descripcion = nullptr;
    precio = 0.0;
    stock = 0;
}

Producto::~Producto() {
    delete codigo;
    delete descripcion;
}

void Producto::SetCantidad_clientes_no_servidos(int cantidad_clientes_no_servidos) {
    this->cantidad_clientes_no_servidos = cantidad_clientes_no_servidos;
}

int Producto::GetCantidad_clientes_no_servidos() const {
    return cantidad_clientes_no_servidos;
}

void Producto::SetCantidad_clientes_servidos(int cantidad_clientes_servidos) {
    this->cantidad_clientes_servidos = cantidad_clientes_servidos;
}

int Producto::GetCantidad_clientes_servidos() const {
    return cantidad_clientes_servidos;
}

void Producto::SetStock(int stock) {
    this->stock = stock;
}

int Producto::GetStock() const {
    return stock;
}

void Producto::SetPrecio(double precio) {
    this->precio = precio;
}

double Producto::GetPrecio() const {
    return precio;
}

void Producto::SetDescripcion(char* des) {
    if(descripcion != nullptr) delete descripcion;
    descripcion = new char[strlen(des)+1];
    strcpy(descripcion, des);
}

void Producto::GetDescripcion(char* des) const {
    if(descripcion == nullptr) des[0] = 0;
    else strcpy(des, descripcion);
}

void Producto::SetCodigo(char* cod) {
    if(codigo != nullptr) delete codigo;
    codigo = new char[strlen(cod)+1];
    strcpy(codigo, cod);
}

void Producto::GetCodigo(char *cod) const {
    if(codigo == nullptr) cod[0] = 0;
    else strcpy(cod, codigo);
}

bool operator >> (ifstream &arch, class Producto &producto){
    int stock;
    double precio;
    char codigo[100], descripcion[100];
    arch.getline(codigo, 100, ',');
    if(arch.eof()) return false;
    arch.getline(descripcion, 100, ',');
    arch >> precio;
    arch.get();
    arch >> stock;
    arch.get();
    producto.SetCodigo(codigo);
    producto.SetDescripcion(descripcion);
    producto.SetPrecio(precio);
    producto.SetStock(stock);
    producto.SetCantidad_clientes_no_servidos(0);
    producto.SetCantidad_clientes_servidos(0);
    return true;
}
