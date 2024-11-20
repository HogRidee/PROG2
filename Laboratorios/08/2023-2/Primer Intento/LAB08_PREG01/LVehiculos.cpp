/* 
 * File:   LVehiculos.cpp
 * Author: Ivan
 * 
 * Created on 20 de noviembre de 2024, 10:39
 */

#include "LVehiculos.h"

LVehiculos::LVehiculos() {
    lfin = nullptr;
    lini = nullptr;
}

LVehiculos::LVehiculos(const LVehiculos& orig) {
    lfin = nullptr;
    lini = nullptr;
    *this = orig;
}

LVehiculos::~LVehiculos() {
    delete lfin;
    delete lini;
}

