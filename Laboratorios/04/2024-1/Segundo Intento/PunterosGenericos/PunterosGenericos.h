/* 
 * File:   PunterosGenericos.h
 * Author: Ivan
 *
 * Created on 25 de septiembre de 2024, 12:47
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

#include "AperturaDeArchivos.h"
#include "MuestraPunteroGenerico.h"

using namespace std;

void cargaclientes(void *&clientes);
void *leerCliente(ifstream &arch);
char *leerCadena(ifstream &arch, int n, char c);
void creareserva(void *&reserva);
void *leerLibro(ifstream &arch);
void *crearPedido(int stock);
void cargareservar(void *clientes, void *reserva);
void cargarReservas(void *clientes, void *reserva, int dni, char *codigo);
int buscarLibro(void *res, char *codigo);
bool sonIguales(void *res, char *codigo);
void cargarReserva(void *res, void *clientes, int dni);
int buscarCliente(void *clientes, int dni);
bool sonIguales(void *cli, int dni);
void *crearPedido(void *cli);
int calcularPosicion(void *res);

#endif /* PUNTEROSGENERICOS_H */

