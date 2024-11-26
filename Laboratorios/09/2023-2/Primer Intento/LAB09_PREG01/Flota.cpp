/* 
 * File:   Flota.cpp
 * Author: Ivan
 * 
 * Created on 26 de noviembre de 2024, 10:37
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
    class NVehiculo vehiculo;
    char tipo;
    while(true){
        arch >> tipo;
        if(arch.eof()) break;
        arch.get();
        vehiculo.asignaMemoria(tipo);
        vehiculo.lee(arch);
    }
}

void Flota::cargapedidos() {
    
}

void Flota::muestracarga() {
    
}


