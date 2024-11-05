/* 
 * File:   Presencial.cpp
 * Author: Ivan
 * 
 * Created on 4 de noviembre de 2024, 11:25
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
    total = monto*GetRecargo()/100;
    Alumno::SetTotal(monto+total);
}

void Presencial::imprime(ofstream& arch) {
    Alumno::imprime(arch);
    arch << right << setw(15) << "+";
    arch << right << setw(10) << Alumno::GetTotal() << endl;
}


