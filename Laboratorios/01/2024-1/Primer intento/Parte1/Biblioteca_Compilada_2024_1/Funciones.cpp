#include "Funciones.h"

bool operator >> (istream &in, struct Libro &libro){
    in.getline(libro.codigo, 8, ',');
    if(in.eof()) return false;
    in.getline(libro.tiltulo, 80, ',');
    in.getline(libro.autor, 60, ',');
    in >> libro.stock;
    in.get();
    in >> libro.precio;
    in.get();
    return true;
}

bool operator >> (istream &in, struct Cliente &cliente){
    in >> cliente.dni;
    if(in.eof()) return false;
    in.get();
    in.getline(cliente.nombre, 60, '\n');
    cliente.cantDeLibros = 0;
    cliente.pagoTotal = 0.0;
    return true;
}

bool operator >> (struct LibroSolicitado &libroSolicitado, struct Libro *&arrLibros){
    int pos;
    pos = buscarLibro(libroSolicitado.codigoDelLibro, arrLibros);
    if(pos != -1){
        if(arrLibros[pos].stock > 0){
            arrLibros[pos].stock--;
            libroSolicitado.precio = arrLibros[pos].precio;
            libroSolicitado.atendido = true;
            return true;
        }
    }
    else{
        libroSolicitado.atendido = false;
        return false;
    }
}

int buscarLibro(char *codigo, struct Libro *arrLibros){
    for(int i = 0; strcmp(arrLibros[i].codigo, "FIN") != 0; i++){
        if(strcmp(arrLibros[i].codigo, codigo) == 0){
            return i;
        }
    }
    return -1;
}

bool operator << (struct Cliente &cliente, struct LibroSolicitado pedido){
    if(cliente.cantDeLibros < 30){
        cliente.librosSolicitados[cliente.cantDeLibros] = pedido;
        //cliente.pagoTotal += pedido.precio;
        cliente.cantDeLibros++;
        return true;
    }
    return false;
}

struct Cliente& operator ++ (struct Cliente &cliente){
    for(int i = 0; i < cliente.cantDeLibros; i++){
        if(cliente.librosSolicitados[i].atendido)
            cliente.pagoTotal += cliente.librosSolicitados[i].precio;
    }
}

ostream& operator << (ostream &out, const struct Libro &libro){
    out << fixed << setprecision(2);
    out << left << setw(10) << libro.codigo;
    out << left << setw(40) << libro.tiltulo;
    out << left << setw(40) << libro.autor;
    out << right << setw(5) << libro.stock;
    out << right << setw(10) << libro.precio << endl;
}

ostream& operator << (ostream &out, const struct Cliente &cliente){
    out << fixed << setprecision(2);
    out << right << setw(5) << cliente.dni;
    out << left << setw(3) << " ";
    out << left << setw(15) << cliente.nombre << endl;
    imprimirLibrosEntregados(out, cliente);
    out << "Total a pagar: " << cliente.pagoTotal << endl;
    imprimirLibrosNoEntregados(out, cliente);
    return out;
}

void imprimirLibrosEntregados(ostream &out, const struct Cliente &cliente){
    out << "Libros entregados:" << endl;
    out << left << setw(5) << " ";
    out << left << setw(15) << "Pedido No.";
    out << left << setw(10) << "Codigo";
    out << left << setw(10) << "Precio" << endl;
    for(int i = 0; i < cliente.cantDeLibros; i++){
        if(cliente.librosSolicitados[i].atendido){
            out << right << setw(10) << cliente.librosSolicitados[i].numeroDePedido;
            out << left << setw(10) << " ";
            out << left << setw(5) << cliente.librosSolicitados[i].codigoDelLibro;
            out << right << setw(8) << cliente.librosSolicitados[i].precio << endl;
        }
    }
}

void imprimirLibrosNoEntregados(ostream &out, const struct Cliente &cliente){
    out << "Libros no entregados por falta de stock:" << endl;
    out << left << setw(5) << " ";
    out << left << setw(15) << "Pedido No.";
    out << left << setw(10) << "Codigo" << endl;
    for(int i = 0; i < cliente.cantDeLibros; i++){
        if(not cliente.librosSolicitados[i].atendido){
            out << right << setw(10) << cliente.librosSolicitados[i].numeroDePedido;
            out << left << setw(10) << " ";
            out << left << setw(5) << cliente.librosSolicitados[i].codigoDelLibro;
        }
    }
}
