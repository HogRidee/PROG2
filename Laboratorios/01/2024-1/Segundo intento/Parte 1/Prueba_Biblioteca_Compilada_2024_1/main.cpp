/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 2 de septiembre de 2024, 13:24
 */

#include <iostream>
#include <fstream>

using namespace std;

#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "Sobrecargas.h"

int main(int argc, char** argv) {

    ifstream archLibros, archClientes;
    
    AperturaDeUnArchivoDeTextosParaLeer(archLibros, "Libros.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archClientes, "Cientes.csv");
    
    struct Libro *arrLibros = nullptr;
    arrLibros = new struct Libro[300];
    int i = 0;
    
    struct Cliente *arrClientes = nullptr;
    arrClientes = new struct Cliente[300];
    int j = 0;
    
    while(true){
        if(not (archLibros >> arrLibros[i])){
            strcpy(arrLibros[i].codigo, "FIN");
            break;
        }
        i++;
    }
    
    while(true){
        if(not (archClientes >> arrClientes[j])){
            arrClientes[j].dni = 0;
            break;
        }
        j++;
    }
    
    struct LibroSolicitado libroPedido;
    strcpy(libroPedido.codigoDelLibro, "IIM5175");

    libroPedido >> arrLibros;
    
    arrClientes[0] << libroPedido;
    cout << arrClientes[0].librosSolicitados[0].codigoDelLibro << endl;
    
    ++arrClientes[0];
    cout << arrClientes[0].pagoTotal << endl;
    
    cout << arrLibros[0] << endl;
    
    cout << arrClientes[0] << endl;
    
    return 0;
}
