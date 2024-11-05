/* 
 * File:   Alumno.h
 * Author: Ivan
 *
 * Created on 5 de noviembre de 2024, 9:25
 */

#ifndef ALUMNO_H
#define ALUMNO_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

class Alumno {
private:
    int codigo;
    char *nombre;
    int escala;
    double total;
public:
    Alumno();
    Alumno(const Alumno& orig);
    virtual ~Alumno();
    void SetTotal(double total);
    double GetTotal() const;
    void SetEscala(int escala);
    int GetEscala() const;
    void SetNombre(char* nomb);
    void GetNombre(char *nomb) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    
    void leerDatos(ifstream &arch);
    void imprime(ofstream &arch);
};

#endif /* ALUMNO_H */

