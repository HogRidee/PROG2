#include "FlotaGenerica.h"

void cargacamiones(void *&flota, int numcamiones, double pesomaximo, 
        void *(*lee)(ifstream &), double (*calcula)(void *), const char *filename){
    ifstream arch(filename, ios::in);
    if(not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << filename << endl;
        exit(1);
    }
    flota = nullptr;
    void *dato, **arreglo;
    int i;
    arreglo = new void*[numcamiones+1]{};
    while(true){
        dato = lee(arch);
        if(arch.eof()) break;
        for(i = 0; arreglo[i]; i++){
            void **camion = (void**)arreglo[i];
            double *pesoCamion = (double*)camion[1];
            if(pesomaximo >= *pesoCamion+calcula(dato)) break;
        }
        if(i == numcamiones) break;
        if(arreglo[i] == nullptr){
            void **pila;
            pila = new void*[2]{};
            double *peso;
            peso = new double;
            *peso = 0;
            pila[1] = peso;
            arreglo[i] = pila;
        }
        push(arreglo[i], dato);
        void **pilaa = (void**)arreglo[i];
        double *pesoPila = (double*)pilaa[1];
        *pesoPila = (*pesoPila)+calcula(dato);
    }
    flota = arreglo;
}

bool pilavacia(void *pila){
    void **info = (void**)pila;
    return (info[0] == nullptr);
}

void push(void *pila, void *dato){
    void **info = (void**)pila;
    void **nuevo;
    nuevo = new void*[2]{};
    nuevo[1] = dato;
    if(pilavacia(pila))
        info[0] = nuevo;
    else{
        nuevo[0] = info[0];
        info[0] = nuevo;
    }
}

void muestracamiones(void *flota, int numcamiones, void (*imprime)(ofstream &, void*), 
        const char *filename){
    ofstream arch(filename, ios::out);
    if(not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << endl;
        exit(1);
    }
    void **arreglo = (void**)flota;
    for(int i = 0; i < numcamiones; i++){
        void **info = (void**)arreglo[i];
        void **recorrido = (void**)info[0];
        double *peso = (double*)info[1];
        arch << "Camion " << setw(2) << i+1 << ":Peso: " << setw(3) 
                << fixed << setprecision(2) << *peso << endl << endl;
        while(recorrido){
            imprime(arch, recorrido[1]);
            recorrido = (void**)recorrido[0];
        }
        arch << endl;
    }
}