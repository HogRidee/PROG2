/* 
 * File:   Camion.cpp
 * Author: Ivan
 * 
 * Created on 20 de noviembre de 2024, 10:35
 */

#include "Camion.h"

Camion::Camion() {
    ejes = 0;
    llantas = 0;
}

Camion::Camion(const Camion& orig) {
   *this = orig;
}

Camion::~Camion() {
}

void Camion::SetLlantas(int llantas) {
    this->llantas = llantas;
}

int Camion::GetLlantas() const {
    return llantas;
}

void Camion::SetEjes(int ejes) {
    this->ejes = ejes;
}

int Camion::GetEjes() const {
    return ejes;
}

