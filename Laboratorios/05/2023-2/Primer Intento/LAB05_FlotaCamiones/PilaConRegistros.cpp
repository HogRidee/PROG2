#include "PilaConRegistros.h"

void *leeregistro(ifstream &arch){
    void **reg;
    int d, n, *dni, *cant;
    double p, *peso;
    char *cod;
    cod = leerCadena(arch, 15, ',');
    if(arch.eof()) return nullptr;
    arch >> d;
    arch.get();
    arch >> n;
    arch.get();
    arch >> p;
    arch.get();
    dni = new int;
    cant = new int;
    peso = new double;
    *dni = d;
    *cant = n;
    *peso = p;
    reg = new void*[4]{};
    reg[0] = cod;
    reg[1] = dni;
    reg[2] = cant;
    reg[3] = peso;
    return reg;
}

char *leerCadena(ifstream &arch,int n, char c){
    char buffer[n], *cad;
    arch.getline(buffer, n, c);
    if(arch.eof()) return nullptr;
    cad = new char[strlen(buffer)+1];
    strcpy(cad, buffer);
    return cad;
}

double calcularegistro(void *dato){
    void **reg = (void**)dato;
    double *peso = (double*)reg[3];
    return *peso;
}

void imprimeregistro(ofstream &arch, void *dato){
    void **reg = (void**)dato;
    char *cod = (char *)reg[0];
    int *cant = (int *)reg[2];
    double *peso = (double*)reg[3];
    arch << setw(10) << cod;
    arch << setw(10) << *cant;
    arch << setw(10) << *peso << endl;
}

int cmpregistro(const void *a, const void *b){
    void **ai = *(void***)a;
    void **bi = *(void***)b;
    double *datoa = (double*)ai[1];
    double *datob = (double*)bi[1];
    return (*datoa < *datob) - (*datoa > *datob);
}