/* 
 * File:   NPedido.cpp
 * Author: Ivan
 * 
 * Created on 20 de noviembre de 2024, 10:26
 */

#include "NPedido.h"

NPedido::NPedido() {
    cantidad = 0;
    codigo = nullptr;
    peso = 0.0;
}

NPedido::NPedido(const NPedido& orig) {
    codigo = nullptr;
    *this = orig;
}

NPedido::~NPedido() {
    delete codigo;
}

void NPedido::SetPeso(double peso) {
    this->peso = peso;
}

double NPedido::GetPeso() const {
    return peso;
}

void NPedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int NPedido::GetCantidad() const {
    return cantidad;
}

void NPedido::SetCodigo(char* cod) {
    if(codigo != nullptr) delete codigo;
    codigo = new char[strlen(cod)+1];
    strcpy(codigo, cod);
}

void NPedido::GetCodigo(char *cod) const {
    if(codigo == nullptr) cod[0] = 0;
    else strcpy(cod, codigo);
}

