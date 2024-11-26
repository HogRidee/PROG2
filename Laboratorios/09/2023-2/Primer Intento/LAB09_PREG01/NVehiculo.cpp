/* 
 * File:   NVehiculo.cpp
 * Author: Ivan
 * 
 * Created on 26 de noviembre de 2024, 10:36
 */

#include "NVehiculo.h"

NVehiculo::NVehiculo() {
    unidad = nullptr;
}

NVehiculo::NVehiculo(const NVehiculo& orig) {
    unidad = nullptr;
    *this = orig;
}

NVehiculo::~NVehiculo() {
}

void NVehiculo::asignaMemoria(char tipo) {
    switch(tipo){
        case 'F':
            unidad = new class Furgon;
            break;
        case 'C':
            unidad = new class Camion;
            break;
    }
}

void NVehiculo::lee(ifstream& arch) {
    
}
