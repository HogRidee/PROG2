/* 
 * File:   BibliotecaGenerica.h
 * Author: Ivan
 *
 * Created on 9 de octubre de 2024, 10:18
 */

#ifndef BIBLIOTECAGENERICA_H
#define BIBLIOTECAGENERICA_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

void crealista(void *&pedidos1, void *(*lee)(ifstream &), const char *filename);
void inicializarLista(void *&lista);
void insertarAlFinal(void *dato, void *lista);
void imprimelista(void *lista, void (*imprime)(ofstream &, void *), 
        const char *filename);
void *quitalista(void *lista);
bool listavacia(void *lista);
void combinalista(void *lista1, void *lista2, void *&listaFinal, 
        int (*compara)(const void*, const void*));

#endif /* BIBLIOTECAGENERICA_H */

