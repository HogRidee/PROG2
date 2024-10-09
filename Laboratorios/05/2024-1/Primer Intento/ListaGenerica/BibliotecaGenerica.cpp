#include "BibliotecaGenerica.h"

void crealista(void *&lista, void *(*lee)(ifstream &), const char *filename){
    ifstream arch(filename, ios::in);
    if(not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << filename << endl;
        exit(1);
    }
    void *dato;
    lista = nullptr;
    inicializarLista(lista);
    while(true){
        dato = lee(arch);
        if(arch.eof()) break;
        insertarAlFinal(dato, lista);
    }
}

void inicializarLista(void *&lista){
    void **info = new void*[2]{};
    lista = info;
}

void insertarAlFinal(void *dato, void *lista){
    void **p = (void**)lista, **ant = nullptr, **nuevo;
    void **recorrido = (void**)p[0];
    nuevo = new void*[2]{};
    nuevo[0] = dato;
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

void *quitalista(void *lista){
    if(listavacia(lista)) return nullptr;
    void **p = (void**)lista;
    void **cabeza = (void**)p[0];
    void **nuevaCabeza = (void**)cabeza[1];
    void *dato = cabeza[0];
    p[0] = nuevaCabeza;
    delete cabeza;
    return dato;
}

bool listavacia(void *lista){
    void **p = (void**)lista;
    return (p[0] == nullptr);
}

void combinalista(void *lista1, void *lista2, void *&listaFinal, 
        int (*compara)(const void*, const void*)){
    inicializarLista(listaFinal);
    void **p1 = (void**)lista1;
    void **p2 = (void**)lista2;
    void **rec1 = (void**)p1[0];
    void **rec2 = (void**)p2[0];
    void *dato;
    while(not listavacia(lista1) or not listavacia(lista2)){
        if(listavacia(lista1)){
            dato = quitalista(lista2);
            rec2 = (void**)rec2[1];
        }
        else if(listavacia(lista2)){
            dato = quitalista(lista1);
            rec1 = (void**)rec1[1];
        }
        else if(compara(rec1[0], rec2[0]) > 0){
            rec2 = (void**)rec2[1];
            dato = quitalista(lista2);
        }
        else{
            rec1 = (void**)rec1[1];
            dato = quitalista(lista1);
        }
        insertarAlFinal(dato, listaFinal);
    }
}