#include "Funciones.h"

bool operator >> (istream &in, struct Libro &libro){
    in.getline(libro.codigo, 8, ',');
    if(in.eof()) return false;
    in.getline(libro.tiltulo, 80, ',');
    in.getline(libro.autor, 60, ',');
    in >> libro.stock;
    in.get();
    in >> libro.precio;
    in.get();
    return true;
}

bool operator >> (istream &in, struct Cliente &cliente){
    in >> cliente.dni;
    if(in.eof()) return false;
    in.get();
    in.getline(cliente.nombre, 60, '\n');
    cliente.cantDeLibros = 0;
    cliente.pagoTotal = 0.0;
    return true;
}

bool operator >> (struct LibroSolicitado &libroSolicitado, struct Libro *&arrLibros){
    int pos;
    pos = buscarLibro(libroSolicitado.codigoDelLibro, arrLibros);
    if(pos != -1){
        if(arrLibros[pos].stock > 0){
            
        }
    }
    return true;
}

int buscarLibro(char *codigo, struct Libro *arrLibros){
    for(int i = 0; strcmp(arrLibros[i].codigo, "FIN") != 0; i++){
        if(strcmp(arrLibros[i].codigo, codigo) == 0){
            return i;
        }
    }
    return -1;
}