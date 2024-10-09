#include "FuncionesEnteras.h"

void *leenum(ifstream &arch){
    int num, *dato;
    arch >> num;
    if(arch.eof()) return nullptr;
    dato = new int;
    *dato = num;
    return dato;
}

void imprimenum(ofstream &arch, void *dato){
    int *num = (int*)dato;
    arch << setw(5) << *num << endl;
}

int cmpnum(const void *a, const void *b){
    int *ai = (int*)a, *bi = (int*)b;
    return *ai - *bi;
}