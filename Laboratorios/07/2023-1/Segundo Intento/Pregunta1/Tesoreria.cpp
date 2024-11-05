/* 
 * File:   Tesoreria.cpp
 * Author: Ivan
 * 
 * Created on 5 de noviembre de 2024, 9:33
 */

#include "Tesoreria.h"

Tesoreria::Tesoreria() {
}

Tesoreria::Tesoreria(const Tesoreria& orig) {
    *this = orig;
}

Tesoreria::~Tesoreria() {
}

void Tesoreria::cargaescalas() {
    ifstream arch("escalas.csv", ios::in);
    if(not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo escalas.csv" << endl;
        exit(1);
    }
    int escala;
    double precio;
    while(true){
        arch >> escala;
        if(arch.eof()) break;
        arch.get();
        arch >> precio;
        lescala[escala-1].SetCodigo(escala);
        lescala[escala-1].SetPrecio(precio);
    }
}

void Tesoreria::cargaalumnos() {
    ifstream arch("Alumnos.csv", ios::in);
    if(not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo Alumnos.csv" << endl;
        exit(1);
    }
    int np = 0, ns = 0, nv = 0;
    char tipo;
    while(true){
        arch >> tipo;
        if(arch.eof()) break;
        arch.get();
        switch(tipo){
            case 'P':
                lpresencial[np].leerDatos(arch);
                np++;
                break;
            case 'S':
                lsemipresencial[ns].leerDatos(arch);
                ns++;
                break;
            case 'V':
                lvirtual[nv].leerDatos(arch);
                nv++;
                break;
        }
    }
    lpresencial[np].SetCodigo(0);
    lsemipresencial[ns].SetCodigo(0);
    lvirtual[nv].SetCodigo(0);
}

void Tesoreria::actualiza(double cred) {
    int escala;
    double precio;
    for(int i = 0; lpresencial[i].GetCodigo(); i++){
        escala = lpresencial[i].GetEscala();
        precio = lescala[escala-1].GetPrecio();
        lpresencial[i].actualiza(precio*cred);
    }
    for(int i = 0; lsemipresencial[i].GetCodigo(); i++){
        escala = lsemipresencial[i].GetEscala();
        precio = lescala[escala-1].GetPrecio();
        lsemipresencial[i].actualiza(precio*cred);
    }
    for(int i = 0; lvirtual[i].GetCodigo(); i++){
        escala = lvirtual[i].GetEscala();
        precio = lescala[escala-1].GetPrecio();
        lvirtual[i].actualiza(precio*cred);
    }
}

void Tesoreria::imprime() {
    ofstream arch("Reporte.txt", ios::out);
    if(not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo Reporte.txt" << endl;
        exit(1);
    }
    arch.precision(2);
    arch << fixed;
    arch << left << setw(20) << "Codigo";
    arch << left << setw(40) << "Nombre";
    arch << left << setw(20) << "Escala";
    arch << left << setw(20) << "Licencia";
    arch << left << setw(20) << "Total" << endl;
    imprimirLinea(arch, 120, '=');
    for(int i = 0; lpresencial[i].GetCodigo(); i++)
        lpresencial[i].imprime(arch);
    for(int i = 0; lsemipresencial[i].GetCodigo(); i++)
        lsemipresencial[i].imprime(arch);
    for(int i = 0; lvirtual[i].GetCodigo(); i++)
        lvirtual[i].imprime(arch);
}

void Tesoreria::imprimirLinea(ofstream& arch, int n, char c) {
    for(int i = 0; i < n; i++)
        arch.put(c);
    arch << endl;
}
