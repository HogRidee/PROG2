/* 
 * File:   Semipresencial.cpp
 * Author: Ivan
 * 
 * Created on 4 de noviembre de 2024, 11:28
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
    total = monto*GetDescuento()/100;
    Alumno::SetTotal(monto-total);
}

void Semipresencial::imprime(ofstream& arch) {
    Alumno::imprime(arch);
    arch << right << setw(15) << "-";
    arch << right << setw(10) << Alumno::GetTotal() << endl;
}


