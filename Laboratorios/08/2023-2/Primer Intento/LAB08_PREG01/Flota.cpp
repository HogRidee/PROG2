/* 
 * File:   Flota.cpp
 * Author: Ivan
 * 
 * Created on 21 de noviembre de 2024, 8:47
 */

#include "Flota.h"

Flota::Flota() {
}

Flota::Flota(const Flota& orig) {
    *this = orig;
}

Flota::~Flota() {
}

void Flota::cargaflota() {
    ifstream arch("Vehiculos.csv", ios::in);
    if(not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo Vehiculos.csv" << endl;
        exit(1);
    }
    char tipo;
    while(true){
        arch >> tipo;
        if(arch.eof()) break;
        arch.get();
        lista.inserta(arch, tipo);
    }
}

void Flota::cargapedidos() {
    
}

void Flota::muestracarga() {
    ofstream arch("Reporte.txt", ios::out);
    if(not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo Reporte.txt" << endl;
        exit(1);
    }
    lista.imprime(arch);
}
