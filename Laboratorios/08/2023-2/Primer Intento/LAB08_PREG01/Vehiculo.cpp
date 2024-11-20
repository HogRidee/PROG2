/* 
 * File:   Vehiculo.cpp
 * Author: Ivan
 * 
 * Created on 20 de noviembre de 2024, 10:29
 */

#include "Vehiculo.h"

Vehiculo::Vehiculo() {
    actcarga = 0.0;
    cliente = 0;
    maxcarga = 0.0;
    ped = nullptr;
    placa = nullptr;
}

Vehiculo::Vehiculo(const Vehiculo& orig) {
    ped = nullptr;
    placa = nullptr;
    *this = orig;
}

Vehiculo::~Vehiculo() {
    delete ped;
    delete placa;
}

void Vehiculo::SetActcarga(double actcarga) {
    this->actcarga = actcarga;
}

double Vehiculo::GetActcarga() const {
    return actcarga;
}

void Vehiculo::SetMaxcarga(double maxcarga) {
    this->maxcarga = maxcarga;
}

double Vehiculo::GetMaxcarga() const {
    return maxcarga;
}

void Vehiculo::SetPlaca(char* plac) {
    if(placa != nullptr) delete placa;
    placa = new char[strlen(plac)+1];
    strcpy(placa, plac);
}

void Vehiculo::GetPlaca(char *plac) const {
    if(placa == nullptr) plac[0] = 0;
    else strcpy(plac, placa);
}

void Vehiculo::SetCliente(int cliente) {
    this->cliente = cliente;
}

int Vehiculo::GetCliente() const {
    return cliente;
}

