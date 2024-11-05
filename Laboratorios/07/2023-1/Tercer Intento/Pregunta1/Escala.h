/* 
 * File:   Escala.h
 * Author: Ivan
 *
 * Created on 5 de noviembre de 2024, 10:52
 */

#ifndef ESCALA_H
#define ESCALA_H

class Escala {
private:
    int codigo;
    double precio;
public:
    Escala();
    Escala(const Escala& orig);
    virtual ~Escala();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
};

#endif /* ESCALA_H */

