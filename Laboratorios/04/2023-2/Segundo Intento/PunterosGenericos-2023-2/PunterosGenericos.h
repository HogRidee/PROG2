/* 
 * File:   PunterosGenericos.h
 * Author: Ivan
 *
 * Created on 30 de septiembre de 2024, 5:50
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
void cargapedido(void *productos, void *clientes);
void leerPedido(ifstream &arch, char *&codigo, int &dni, int &cant);
void procesarPedido(void *productos, void *clientes, char *codigo, int dni, int cant);
int buscarProducto(void *productos, char *codigo, bool &esCred, double &precio);
bool sonIguales(void *producto, char *codigo);
int buscarCliente(void *clientes, int dni, double &lineaC);
bool sonIguales(void *cliente, int dni);
void insertarPedido(void *&buffer, int &nd, char *codigo, int cantt, double totall);
void asignarMemoriaExacta(void *buffer, void *&cli, int nd);
void imprimereporte(void *clientes);
void imprimirLinea(ofstream &arch, int n, char c);
void imprimirCabecera(ofstream &arch, void *cliente);
void imprimirPedidos(ofstream &arch, void *cliente);

#endif /* PUNTEROSGENERICOS_H */

