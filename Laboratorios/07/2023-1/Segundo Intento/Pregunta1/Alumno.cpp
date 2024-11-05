/* 
 * File:   Alumno.cpp
 * Author: Ivan
 * 
 * Created on 5 de noviembre de 2024, 9:25
 */

#include "Alumno.h"

Alumno::Alumno() {
    codigo = 0;
    escala = 0;
    nombre = nullptr;
    total = 0.0;
}

Alumno::Alumno(const Alumno& orig) {
    nombre = nullptr;
    *this = orig;
}

Alumno::~Alumno() {
    delete nombre;
}

void Alumno::SetTotal(double total) {
    this->total = total;
}

double Alumno::GetTotal() const {
    return total;
}

void Alumno::SetEscala(int escala) {
    this->escala = escala;
}

int Alumno::GetEscala() const {
    return escala;
}

void Alumno::SetNombre(char* nomb) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb)+1];
    strcpy(nombre, nomb);
}

void Alumno::GetNombre(char *nomb) const {
    if(nombre == nullptr) nomb[0] = 0;
    else strcpy(nomb, nombre);
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}

void Alumno::leerDatos(ifstream& arch) {
    char nomb[60];
    arch >> codigo;
    arch.get();
    arch.getline(nomb, 60, ',');
    SetNombre(nomb);
    arch >> escala;
    arch.get();
}

void Alumno::imprime(ofstream& arch) {
    arch << left << setw(20) << codigo;
    arch << left << setw(43) << nombre;
    arch << left << setw(20) << escala;
}
