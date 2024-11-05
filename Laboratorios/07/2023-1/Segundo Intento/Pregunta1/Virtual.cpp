/* 
 * File:   Virtual.cpp
 * Author: Ivan
 * 
 * Created on 5 de noviembre de 2024, 9:31
 */

#include "Virtual.h"

Virtual::Virtual() {
    licencia = nullptr;
    total = 100;
}

Virtual::Virtual(const Virtual& orig) {
    licencia = nullptr;
   *this = orig;
}

Virtual::~Virtual() {
    delete licencia;
}

void Virtual::SetTotal(double total) {
    this->total = total;
}

double Virtual::GetTotal() const {
    return total;
}

void Virtual::SetLicencia(char* lic) {
    if(licencia != nullptr) delete licencia;
    licencia = new char[strlen(lic)+1];
    strcpy(licencia, lic);
}

void Virtual::GetLicencia(char* lic) const {
    if(licencia == nullptr) lic[0] = 0;
    else strcpy(lic, licencia);
}

void Virtual::leerDatos(ifstream& arch) {
    char lic[20];
    Alumno::leerDatos(arch);
    arch.getline(lic, 20, '\n');
    SetLicencia(lic);
}

void Virtual::actualiza(double monto) {
    total += monto;
    Alumno::SetTotal(total);
}

void Virtual::imprime(ofstream& arch) {
    Alumno::imprime(arch);
    arch << left << setw(15) << licencia;
    arch << right << setw(10) << total << endl;
}
