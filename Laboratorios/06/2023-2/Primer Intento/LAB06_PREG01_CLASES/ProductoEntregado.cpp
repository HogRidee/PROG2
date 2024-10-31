/* 
 * File:   ProductoEntregado.cpp
 * Author: Ivan
 * 
 * Created on 31 de octubre de 2024, 10:14
 */

#include "ProductoEntregado.h"

ProductoEntregado::ProductoEntregado() {
    codigo = nullptr;
    precio = 0.0;
}

ProductoEntregado::~ProductoEntregado() {
    delete codigo;
}

void ProductoEntregado::SetPrecio(double precio) {
    this->precio = precio;
}

double ProductoEntregado::GetPrecio() const {
    return precio;
}

void ProductoEntregado::SetCodigo(char* cod) {
    if(codigo != nullptr) delete codigo;
    codigo = new char[strlen(cod)+1];
    strcmp(codigo, cod);
}

void ProductoEntregado::GetCodigo(char *cod) const {
    if(codigo == nullptr) cod[0] = 0;
    else strcpy(cod, codigo);
}

