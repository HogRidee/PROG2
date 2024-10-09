#include "BibliotecaGenerica.h"

void crealista(void *&lista, void *(*lee)(ifstream &), const char *filename){
    ifstream arch(filename, ios::in);
    if(not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << filename << endl;
        exit(1);
    }
    lista = nullptr;
    void *dato;
    inicializarLista(lista);
    while(true){
        dato = lee(arch);
        if(arch.eof()) break;
        insertarAlFinal(lista, dato);
    }
}

void inicializarLista(void *&lista){
    void **info = new void*[2]{};
    lista = info;
}

void insertarAlFinal(void *lista, void *dato){
    void **p = (void**)lista, **ant = nullptr, **nuevo;
    nuevo = new void*[2]{};
    nuevo[0] = dato;
    void **recorrido = (void**)p[0];
    while(recorrido){
        ant = recorrido;
        recorrido = (void**)recorrido[1];
    }
    if(ant == nullptr)
        p[0] = nuevo;
    else
        ant[1] = nuevo;
    p[1] = nuevo;
}

void imprimelista(void *lista, void (*imprime)(ofstream &, void *), 
        const char *filename){
    ofstream arch(filename, ios::out);
    if(not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << filename << endl;
        exit(1);
    }
    void **p = (void**)lista;
    void **recorrido = (void**)p[0];
    while(recorrido){
        imprime(arch, recorrido[0]);
        recorrido = (void**)recorrido[1];
    }
}

bool listavacia(void *lista){
    void **p = (void**)lista;
    return (p[0] == nullptr);
}

void *quitalista(void *lista){
    void **p = (void**)lista;
    void **cabeza = (void**)p[0];
    void **nuevaCabeza = (void**)cabeza[1];
    void *dato = cabeza[0];
    p[0] = nuevaCabeza;
    delete cabeza;
    return dato;
}



