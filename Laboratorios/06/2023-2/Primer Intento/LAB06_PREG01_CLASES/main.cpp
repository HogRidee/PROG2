/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 31 de octubre de 2024, 10:13
 */

#include "Almacen.h"

using namespace std;

int main(int argc, char** argv) {

    ifstream archClientes("Clientes.csv", ios::in);
    if(not archClientes.is_open()){
        cout << "ERROR: No se pudo abrir el archivo Clientes.csv" << endl;
        exit(1);
    }
    
    class Cliente cliente;
    while((archClientes >> cliente)){
        cout << cliente.GetDni() << " " << cliente.GetTelefono() << endl;
    }
    
    ifstream archProductos("Productos.csv", ios::in);
    if(not archProductos.is_open()){
        cout << "ERROR: No se pudo abrir el archivo Productos.csv" << endl;
        exit(1);
    }
    
    class Producto producto;

    while((archProductos >> producto)){
    }
    
    return 0;
}

