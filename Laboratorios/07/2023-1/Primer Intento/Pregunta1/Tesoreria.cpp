/* 
 * File:   Tesoreria.cpp
 * Author: Ivan
 * 
 * Created on 4 de noviembre de 2024, 11:38
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
    int nP = 0, nS = 0, nV = 0;
    char tipo;
    while(true){
        arch >> tipo;
        if(arch.eof()) break;
        arch.get();
        switch(tipo){
            case 'P':
                lpresencial[nP].leerDatos(arch);
                nP++;
                break;
            case 'S':
                lsemipresencial[nS].leerDatos(arch);
                nS++;
                break;
            case 'V':
                lvirtual[nV].leerDatos(arch);
                nV++;
                break;
        }
    }
    lpresencial[nP].SetCodigo(0);
    lsemipresencial[nS].SetCodigo(0);
    lvirtual[nV].SetCodigo(0);
}

void Tesoreria::actualiza(double cred) {
    int esc;
    double precioEsc;
    for(int i = 0; lpresencial[i].GetCodigo(); i++){
        esc = lpresencial[i].GetEscala();
        precioEsc = lescala[esc-1].GetPrecio();
        lpresencial[i].actualiza(cred*precioEsc);
    }
    for(int i = 0; lsemipresencial[i].GetCodigo(); i++){
        esc = lsemipresencial[i].GetEscala();
        precioEsc = lescala[esc-1].GetPrecio();
        lsemipresencial[i].actualiza(cred*precioEsc);
    }
    for(int i = 0; lvirtual[i].GetCodigo(); i++){
        esc = lvirtual[i].GetEscala();
        precioEsc = lescala[esc-1].GetPrecio();
        lvirtual[i].actualiza(cred*precioEsc);
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
    arch << left << setw(10) << "Codigo";
    arch << setw(40) << "Nombre";
    arch << right << setw(3) << "Escala";
    arch << setw(12) << "Licencia";
    arch << setw(8) << "Total" << endl;
    imprimeLinea(arch, 80, '=');
    for(int i = 0; lpresencial[i].GetCodigo(); i++)
        lpresencial[i].imprime(arch);
    for(int i = 0; lsemipresencial[i].GetCodigo(); i++)
        lsemipresencial[i].imprime(arch);
    for(int i = 0; lvirtual[i].GetCodigo(); i++)
        lvirtual[i].imprime(arch);
}

void Tesoreria::imprimeLinea(ofstream& arch, int n, char c) {
    for(int i = 0; i < n; i++) arch.put(c);
    arch << endl;
}
