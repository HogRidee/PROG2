/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 25 de septiembre de 2024, 10:55
 */

#include "PunterosGenericos.h"
#include "MuestraPunteroGenerico.h"

using namespace std;

int main(int argc, char** argv) {

    void *clientes, *reserva;
    
    cargaclientes(clientes);
    creareserva(reserva);
    cargareserva(clientes, reserva);
    reportefinal(reserva);
    
    return 0;
}

