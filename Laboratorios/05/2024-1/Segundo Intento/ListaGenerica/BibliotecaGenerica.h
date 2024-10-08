/* 
 * File:   BibliotecaGenerica.h
 * Author: Ivan
 *
 * Created on 9 de octubre de 2024, 13:50
 */

#ifndef BIBLIOTECAGENERICA_H
#define BIBLIOTECAGENERICA_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

void crealista(void *&lista, void *(*lee)(ifstream &), const char *filename);
void inicializarLista(void *&lista);
void insertarAlFinal(void *lista, void *dato);
void imprimelista(void *lista, void (*imprime)(ofstream &, void *), 
        const char *filename);
bool listavacia(void *lista);
void *quitalista(void *lista);
void combinalista(void *lista1, void *lista2, void *&listaf, 
        int (cmp)(const void*, const void*));

#endif /* BIBLIOTECAGENERICA_H */

