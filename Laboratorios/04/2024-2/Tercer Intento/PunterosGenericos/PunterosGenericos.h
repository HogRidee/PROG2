/* 
 * File:   PunterosGenericos.h
 * Author: Ivan
 *
 * Created on 25 de septiembre de 2024, 16:05
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
void *leerReserva(ifstream &arch);
void *crearPedidos(int stock);
void cargareservar(void *clientes, void *reserva);
void cargarPedidos(void *clientes, void *reserva, int dni, char *codigo);
int buscarLibro(void *reserva, char *codigo);
bool sonIguales(void *res, char *codigo);
void cargarPedido(void *clientes, void *res, int dni);
int buscarCliente(void *clientes, int dni);
bool sonIguales(void *cli, int dni);
int calcularPosicion(void *pedidos);
void *crearPedido(void *cli);
void asignarPedido(void *pedido, void *pedidos, int posP);

#endif /* PUNTEROSGENERICOS_H */

