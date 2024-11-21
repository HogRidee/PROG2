/* 
 * File:   NodoLista.cpp
 * Author: Ivan
 * 
 * Created on 20 de noviembre de 2024, 10:37
 */

#include "NodoLista.h"

NodoLista::NodoLista() {
    sig = nullptr;
    unidad = nullptr;
}

NodoLista::NodoLista(const NodoLista& orig) {
    sig = nullptr;
    unidad = nullptr;
    *this = orig;
}

NodoLista::~NodoLista() {
    delete sig;
    delete unidad;
}

void NodoLista::asignaMemoria(char tipo) {
    switch(tipo){
        case 'F':
            unidad = new class Furgon;
            break;
        case 'C':
            unidad = new class Camion;
            break;
    }
}

void NodoLista::leeDatos(ifstream& arch) {
    unidad->lee(arch);
}

void NodoLista::imprime(ofstream& arch) {
    
}
