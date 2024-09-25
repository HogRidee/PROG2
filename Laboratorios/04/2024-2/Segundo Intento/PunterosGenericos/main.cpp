/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 25 de septiembre de 2024, 12:46
 */

#include "PunterosGenericos.h"
#include "MuestraPunteroGenerico.h"

int main(int argc, char** argv) {

    void *clientes, *reserva;
    
    cargaclientes(clientes);
    creareserva(reserva);
    cargareservar(clientes, reserva);
    reportefinal(reserva);
    
    return 0;
}

