#include "FuncionesEnteras.h"

void *leenum(ifstream &arch){
    int dato, *ptrDato;
    arch >> dato;
    if(arch.eof()) return nullptr;
    ptrDato = new int;
    *ptrDato = dato;
    return ptrDato;
}

void imprimenum(ofstream &arch, void *dato){
    int *d = (int*)dato;
    arch << setw(5) << *d << endl;
}

int cmpnum(const void *a, const void *b){
    int *ai = (int*)a, *bi = (int*)b;
    return *ai-*bi;
}