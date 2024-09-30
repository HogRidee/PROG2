/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 30 de septiembre de 2024, 12:32
 */

#include "PunterosGenericos.h"
#include "MuestraPunteros.h"

using namespace std;

int main(int argc, char** argv) {

    void *productos, *clientes;
    
    cargaproductos(productos);
    cargaclientes(clientes);
    cargapedidos(productos, clientes);
    imprimereporte(clientes);
    
    return 0;
}

