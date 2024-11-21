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
    elimina();
}

void LVehiculos::elimina() {
    class NodoLista *sale;
    while(lini){
        sale = lini;
        lini = lini->sig;
        delete sale;
    }
}

void LVehiculos::inserta(ifstream& arch, char tipo) {
    class NodoLista *pini = lini, *pfin = lfin, *nuevo;
    nuevo = new class NodoLista;
    nuevo->asignaMemoria(tipo);
    nuevo->leeDatos(arch);
    if(pini == nullptr){
        pini = nuevo;
        pfin = nuevo;
    }
    else{
        pfin->sig = nuevo;
        pfin = nuevo;
    }
}

void LVehiculos::imprime(ofstream& arch) {
    class NodoLista *p = lini;
    while(p){
        p->imprime(arch);
        p = p->sig; 
    }
}
