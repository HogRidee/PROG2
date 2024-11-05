/* 
 * File:   Semipresencial.cpp
 * Author: Ivan
 * 
 * Created on 5 de noviembre de 2024, 10:59
 */

#include "Semipresencial.h"

Semipresencial::Semipresencial() {
    descuento = 0.0;
    total = 0.0;
}

Semipresencial::Semipresencial(const Semipresencial& orig) {
    *this = orig;
}

Semipresencial::~Semipresencial() {
}

void Semipresencial::SetTotal(double total) {
    this->total = total;
}

double Semipresencial::GetTotal() const {
    return total;
}

void Semipresencial::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Semipresencial::GetDescuento() const {
    return descuento;
}

void Semipresencial::leerDatos(ifstream& arch) {
    Alumno::leerDatos(arch);
    arch >> descuento;
    arch.get();
}

void Semipresencial::actualiza(double monto) {
    total = monto - monto*descuento/100;
    Alumno::SetTotal(total);
}

void Semipresencial::imprime(ofstream& arch) {
    Alumno::imprime(arch);
    arch << left << setw(20) << " ";
    arch << right << setw(10) << total << endl; 
}
