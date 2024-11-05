/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 4 de noviembre de 2024, 11:18
 */

#include "Tesoreria.h"

using namespace std;

int main(int argc, char** argv) {

    Tesoreria caja;
    
    caja.cargaescalas();
    caja.cargaalumnos();
    caja.actualiza(20);
    caja.imprime();
    
    return 0;
}

