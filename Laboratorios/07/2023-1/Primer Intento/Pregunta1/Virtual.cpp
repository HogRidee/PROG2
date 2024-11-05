/* 
 * File:   Virtual.cpp
 * Author: Ivan
 * 
 * Created on 4 de noviembre de 2024, 11:30
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

void Virtual::GetLicencia(char *lic) const {
    if(licencia == nullptr) lic[0] = 0;
    else strcpy(lic, licencia);
}

void Virtual::leerDatos(ifstream& arch) {
    Alumno::leerDatos(arch);
    char lic[60];
    arch.getline(lic, 60, '\n');
    SetLicencia(lic);
}

void Virtual::actualiza(double monto) {
    Alumno::SetTotal(monto+total);
}

void Virtual::imprime(ofstream& arch) {
    Alumno::imprime(arch);
    arch << right << setw(15) << licencia;
    arch << right << setw(10) << Alumno::GetTotal() << endl;
}




