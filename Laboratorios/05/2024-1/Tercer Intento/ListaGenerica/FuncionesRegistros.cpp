#include "FuncionesRegistros.h"

void *leeregistro(ifstream &arch){
    void **registro;
    int np, dni, *n, *d;
    char *cod;
    arch >> np;
    if(arch.eof()) return nullptr;
    arch.get();
    arch >> dni;
    arch.get();
    cod = leerCadena(arch, 20, '\n');
    n = new int;
    d = new int;
    *n = np;
    *d = dni;
    registro = new void*[3]{};
    registro[0] = n;
    registro[1] = d;
    registro[2] = cod;
    return registro;
}

char *leerCadena(ifstream &arch, int n, char c){
    char buffer[n], *cad;
    arch.getline(buffer, n, c);
    if(arch.eof()) return nullptr;
    cad = new char[strlen(buffer)+1];
    strcpy(cad, buffer);
    return cad;
}

void imprimeregistro(ofstream &arch, void *dato){
    void **info = (void**)dato;
    int *np = (int*)info[0];
    int *dni = (int*)info[1];
    char *cod = (char*)info[2];
    arch << setw(10) << *np;
    arch << setw(10) << *dni;
    arch << setw(10) << cod << endl;
}

int cmpregistro(const void *a, const void *b){
    void **infoa = (void**)a;
    void **infob = (void**)b;
    int *npa = (int*)infoa[0];
    int *npb = (int*)infob[0];
    return *npa - *npb;
}