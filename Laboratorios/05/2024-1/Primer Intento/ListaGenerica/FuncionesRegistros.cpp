#include "FuncionesRegistros.h"

void *leeregistro(ifstream &arch){
    void **registro;
    int nPedido, dni, *np, *d;
    char *codigo;
    arch >> nPedido;
    if(arch.eof()) return nullptr;
    arch.get();
    arch >> dni;
    arch.get();
    codigo = leerCadena(arch, 20, '\n');
    np = new int;
    d = new int;
    *np = nPedido;
    *d = dni;
    registro = new void*[3]{};
    registro[0] = np;
    registro[1] = d;
    registro[2] = codigo;
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
    void **reg = (void**)dato;
    int *np = (int*)reg[0];
    int *dni = (int*)reg[1];
    char *cod = (char*)reg[2];
    arch << setw(10) << *np;
    arch << setw(10) << *dni;
    arch << setw(10) << cod << endl;
}

int cmpregistro(const void *a, const void *b){
    void **rega = (void**)a;
    void **regb = (void**)b;
    int *npa = (int*)rega[0];
    int *npb = (int*)regb[0];
    return *npa - *npb;
}