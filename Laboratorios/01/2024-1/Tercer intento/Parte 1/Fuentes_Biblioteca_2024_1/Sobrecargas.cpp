#include "Sobrecargas.h"

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
    
}