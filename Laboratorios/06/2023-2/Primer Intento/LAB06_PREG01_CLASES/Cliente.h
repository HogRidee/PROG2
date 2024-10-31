/* 
 * File:   Cliente.h
 * Author: Ivan
 *
 * Created on 31 de octubre de 2024, 10:17
 */

#ifndef CLIENTE_H
#define CLIENTE_H

#include <fstream>

#include "ProductoEntregado.h"

using namespace std;

class Cliente {
private:
    int dni;
    char *nombre;
    int telefono;
    class ProductoEntregado productos_entregados[100];
    int cantidad_productos_entregados;
    double monto_total;
public:
    Cliente();
    ~Cliente();
    void SetMonto_total(double monto_total);
    double GetMonto_total() const;
    void SetCantidad_productos_entregados(int cantidad_productos_entregados);
    int GetCantidad_productos_entregados() const;
    void SetTelefono(int telefono);
    int GetTelefono() const;
    void SetNombre(char* nomb);
    void GetNombre(char *nomb) const;
    void SetDni(int dni);
    int GetDni() const;
};

bool operator >>(ifstream &, class Cliente &);

#endif /* CLIENTE_H */

