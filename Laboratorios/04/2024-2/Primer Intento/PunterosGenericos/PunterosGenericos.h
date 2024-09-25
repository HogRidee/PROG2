/* 
 * File:   PunterosGenericos.h
 * Author: Ivan
 *
 * Created on 25 de septiembre de 2024, 10:57
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
void *leerRegistro(ifstream &arch);
char *leerCadena(ifstream &arch, int n, char c);
void creareserva(void *&reserva);
void *leerReserva(ifstream &arch);
void *crearPedido(int s);
void cargareserva(void *clientes, void *reserva);
void colocarPedido(void *cli, void *res, int dni, char *codigo);
int buscarLibro(void *res, char *codigo);
bool sonIguales(char *codigo, void *res);
void colocarCliente(void *res, int dni, void *cli);
int buscarCliente(void *cli, int dni);
bool sonIguales(int dni, void *cli);
void *crearPedido(void *cli);
int calcularPosicion(void *res);
void colocarPedido(void *res, void *pedido, int posP);

#endif /* PUNTEROSGENERICOS_H */

