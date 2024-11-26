/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 26 de noviembre de 2024, 10:11
 */

#include "Flota.h"

using namespace std;

int main(int argc, char** argv) {

    class Flota unidades;
    
    unidades.cargaflota();
    unidades.cargapedidos();
    unidades.muestracarga();
    
    return 0;
}

