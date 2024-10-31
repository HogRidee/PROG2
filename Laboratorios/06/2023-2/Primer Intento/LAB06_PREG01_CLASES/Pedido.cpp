/* 
 * File:   Pedido.cpp
 * Author: Ivan
 * 
 * Created on 31 de octubre de 2024, 10:33
 */

#include "Pedido.h"

Pedido::Pedido() {
    codigo = nullptr;
    dni_cliente = 0;
    precio_producto = 0.0;
}

Pedido::~Pedido() {
    delete codigo;
}

void Pedido::SetPrecio_producto(double precio_producto) {
    this->precio_producto = precio_producto;
}

double Pedido::GetPrecio_producto() const {
    return precio_producto;
}

void Pedido::SetDni_cliente(int dni_cliente) {
    this->dni_cliente = dni_cliente;
}

int Pedido::GetDni_cliente() const {
    return dni_cliente;
}

void Pedido::SetCodigo(char* cod) {
    if(codigo != nullptr) delete codigo;
    codigo = new char[strlen(cod)+1];
    strcpy(codigo, cod);
}

void Pedido::GetCodigo(char *cod) const {
    if(codigo == nullptr) cod[0] = 0;
    else strcpy(cod, codigo);
}

