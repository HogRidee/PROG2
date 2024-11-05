/* 
 * File:   Presencial.cpp
 * Author: Ivan
 * 
 * Created on 5 de noviembre de 2024, 10:57
 */

#include "Presencial.h"

Presencial::Presencial() {
    recargo = 0.0;
    total = 0.0;
}

Presencial::Presencial(const Presencial& orig) {
    *this = orig;
}

Presencial::~Presencial() {
}

void Presencial::SetTotal(double total) {
    this->total = total;
}

double Presencial::GetTotal() const {
    return total;
}

void Presencial::SetRecargo(double recargo) {
    this->recargo = recargo;
}

double Presencial::GetRecargo() const {
    return recargo;
}

void Presencial::leerDatos(ifstream& arch) {
    Alumno::leerDatos(arch);
    arch >> recargo;
    arch.get();
}

void Presencial::actualiza(double monto) {
    total = monto + monto*recargo/100;
    Alumno::SetTotal(total);
}

void Presencial::imprime(ofstream& arch) {
    Alumno::imprime(arch);
    arch << left << setw(20) << " ";
    arch << right << setw(10) << total << endl;
}
