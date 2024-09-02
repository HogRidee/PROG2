#include "Sobrecargas.h"

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

bool operator >> (struct LibroSolicitado &libroPedido, struct Libro *&arrLibros){
    int pos = buscarLibro(libroPedido.codigoDelLibro, arrLibros);
    if(pos != -1){
        if(arrLibros[pos].stock > 0){
            arrLibros[pos].stock--;
            libroPedido.atendido = true;
            libroPedido.precio = arrLibros[pos].precio;
            return true;
        }
    }
    libroPedido.atendido = false;        
    return false;
}

int buscarLibro(const char *codigoDelLibro, struct Libro *arrLibros){
    for(int i = 0; strcmp(arrLibros[i].codigo, "FIN") != 0; i++){
        if(strcmp(arrLibros[i].codigo, codigoDelLibro) == 0)
            return i;
    }
    return -1;
}

bool operator << (struct Cliente &cliente, const struct LibroSolicitado &pedido){
    if(cliente.cantDeLibros != 29){
        cliente.librosSolicitados[cliente.cantDeLibros] = pedido;
        cliente.cantDeLibros++;
        return true;
    }
    return false;
}

void operator ++ (struct Cliente &cliente){
    cliente.pagoTotal = 0;
    for(int i = 0; i < cliente.cantDeLibros; i++)
        cliente.pagoTotal += cliente.librosSolicitados[i].precio;
}

ostream& operator << (ostream &out, const struct Libro &libro){
    out << left << setw(10) << libro.codigo;
    out << left << setw(50) << libro.tiltulo;
    out << left << setw(40) << libro.autor;
    out << right << setw(5) << libro.stock << setw(2) << " ";
    out << right << setw(5) << libro.precio;
    return out;
}

ostream& operator << (ostream &out, const struct Cliente &cliente){
    out << right << setw(5) << cliente.dni << setw(3) << " ";
    out << left << setw(5) << cliente.nombre << endl;
    out << "Libros entregados:" << endl;
    out << left << setw(5) << " ";
    out << left << setw(15) << "Pedido No.";
    out << left << setw(15) << "Codigo";
    out << left << setw(15) << "Precio" << endl;
    imprimirLibrosEntregados(out, cliente);
    out << "Libros no entregados: por falta de stock: " << endl;
    out << left << setw(5) << " ";
    out << left << setw(15) << "Pedido No.";
    out << left << setw(15) << "Codigo" << endl;
    imprimirLibrosNoEntregados(out, cliente);
    return out;
}

void imprimirLibrosEntregados(ostream &out, const struct Cliente &cliente){
    for(int i = 0; i < cliente.cantDeLibros; i++){
        if(cliente.librosSolicitados[i].atendido){
            out << left << setw(5) << " ";
            out << right << setw(5) << cliente.librosSolicitados[i].numeroDePedido;
            out << left << setw(5) << " ";
            out << left << setw(10) << cliente.librosSolicitados[i].codigoDelLibro;
            out << right << setw(10) << cliente.librosSolicitados[i].precio << endl;
        }
    }
    out << fixed << setprecision(2);
    out << "Total a pagar:" << cliente.pagoTotal << endl;
}

void imprimirLibrosNoEntregados(ostream &out, const struct Cliente &cliente){
    for(int i = 0; i < cliente.cantDeLibros; i++){
        if(not cliente.librosSolicitados[i].atendido){
            out << left << setw(5) << " ";
            out << right << setw(5) << cliente.librosSolicitados[i].numeroDePedido;
            out << left << setw(5) << " ";
            out << left << setw(10) << cliente.librosSolicitados[i].codigoDelLibro << endl;
        }
    }
}