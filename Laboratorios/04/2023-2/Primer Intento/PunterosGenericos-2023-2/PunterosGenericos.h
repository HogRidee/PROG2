/* 
 * File:   PunterosGenericos.h
 * Author: Ivan
 *
 * Created on 26 de septiembre de 2024, 6:55
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

#include "MuestraPunteros.h"

using namespace std;

void cargaproductos(void *&productos);
void *leerProducto(ifstream &arch);
char *leerCadena(ifstream &arch, int n, char c);
void cargaclientes(void *&clientes);
void *leerCliente(ifstream &arch);
void cargapedidos(void *productos, void *clientes);
int buscarCliente(void *clientes, int dni);
bool sonIguales(void* cliente, int dni);
void cargarPedido(void *cliente, int &nP, void *buffer, void *productos, 
        char *codigo, int cant);
int buscarProducto(void *productos, char *codigo);
bool sonIguales(void *producto, char *codigo);
bool verificarTipo(void *producto);
bool verificarCredito(void *producto, void *cliente, int cant);
void asignarPedido(void *buffer, void *producto, int cant);
void *crearPedido(void *producto, int cant);
void disminuirLC(void *cliente, void *producto, int cant);
int devolverCantClientes(void *cliente);
void imprimereporte(void *clientes);

#endif /* PUNTEROSGENERICOS_H */

