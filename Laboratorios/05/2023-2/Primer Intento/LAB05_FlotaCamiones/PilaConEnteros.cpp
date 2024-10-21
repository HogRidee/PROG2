#include "PilaConEnteros.h"

void *leenumero(ifstream &arch){
    double num, *dato;
    arch >> num;
    if(arch.eof()) return nullptr;
    dato = new double;
    *dato = num;
    return dato;
}

double calculanumero(void *dato){
    double *num = (double*)dato;
    return *num;
}

void imprimenumero(ofstream &arch, void *dato){
    double *peso = (double*)dato;
    arch << *peso << endl;
}

int cmpnumero(const void *a, const void *b){
    void **ai = *(void***)a;
    void **bi = *(void***)b;
    double *datoa = (double*)ai[1];
    double *datob = (double*)bi[1];
    return (*datoa < *datob) - (*datoa > *datob);
}