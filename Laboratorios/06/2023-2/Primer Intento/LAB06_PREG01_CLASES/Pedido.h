/* 
 * File:   Pedido.h
 * Author: Ivan
 *
 * Created on 31 de octubre de 2024, 10:33
 */

#ifndef PEDIDO_H
#define PEDIDO_H

#include <cstring>

class Pedido {
private:
    char *codigo;
    int dni_cliente;
    double precio_producto;
public:
    Pedido();
    ~Pedido();
    void SetPrecio_producto(double precio_producto);
    double GetPrecio_producto() const;
    void SetDni_cliente(int dni_cliente);
    int GetDni_cliente() const;
    void SetCodigo(char* cod);
    void GetCodigo(char *cod) const;
};

#endif /* PEDIDO_H */

