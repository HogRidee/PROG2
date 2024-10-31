/* 
 * File:   Cliente.cpp
 * Author: Ivan
 * 
 * Created on 31 de octubre de 2024, 10:17
 */

#include "Cliente.h"

Cliente::Cliente() {
    cantidad_productos_entregados = 0;
    dni = 0;
    monto_total = 0.0;
    nombre = nullptr;
    telefono = 0;
}

Cliente::~Cliente() {
    delete nombre;
}

void Cliente::SetMonto_total(double monto_total) {
    this->monto_total = monto_total;
}

double Cliente::GetMonto_total() const {
    return monto_total;
}

void Cliente::SetCantidad_productos_entregados(int cantidad_productos_entregados) {
    this->cantidad_productos_entregados = cantidad_productos_entregados;
}

int Cliente::GetCantidad_productos_entregados() const {
    return cantidad_productos_entregados;
}

void Cliente::SetTelefono(int telefono) {
    this->telefono = telefono;
}

int Cliente::GetTelefono() const {
    return telefono;
}

void Cliente::SetNombre(char* nomb) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb)+1];
    strcpy(nombre, nomb);
}

void Cliente::GetNombre(char *nomb) const {
    if(nombre == nullptr) nomb[0] = 0;
    else strcpy(nomb, nombre);
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}

bool operator >>(ifstream &arch, class Cliente &cliente){
    int dni, telefono;
    char nomb[100];
    arch >> dni;
    if(arch.eof()) return false;
    arch.get();
    arch.getline(nomb, 100, ',');
    arch >> telefono;
    cliente.SetDni(dni);
    cliente.SetNombre(nomb);
    cliente.SetTelefono(telefono);
    cliente.SetCantidad_productos_entregados(0);
    cliente.SetMonto_total(0.0);
    return true;
}
