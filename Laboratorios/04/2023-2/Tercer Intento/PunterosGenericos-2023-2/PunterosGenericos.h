/* 
 * File:   PunterosGenericos.h
 * Author: Ivan
 *
 * Created on 30 de septiembre de 2024, 12:33
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
void leerPedido(ifstream &arch, char *&codigo, int &dni, int &cant);
int buscarProducto(void *productos, char *codigo, double &precio, bool &necesitaC);
bool sonIguales(void *producto, char *codigo);
int buscarCliente(void *clientes, int dni, double &lC);
bool sonIguales(void *cliente, int dni);
void insertarPedido(void *&buffer, int &nd, char *codigo, int cant, double total);
void asignarMemoriaExacta(void *&cliente, void *buffer, int nd);
void imprimereporte(void *clientes);
void imprimirLinea(ofstream &arch, int n, char c);
void imprimirCabecera(ofstream &arch, void *cliente);
void imprimirPedidos(ofstream &arch, void *cliente);

#endif /* PUNTEROSGENERICOS_H */

