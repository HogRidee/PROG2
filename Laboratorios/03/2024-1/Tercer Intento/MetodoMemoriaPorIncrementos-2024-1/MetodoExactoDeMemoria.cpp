#include "MetodoExactoDeMemoria.h"

void lecturaDeLibros(const char *filename, char ***&libros, int **&stock){
    ifstream arch(filename, ios::in);
    if(not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << filename << endl;
        exit(1);
    }
    libros = nullptr;
    stock = nullptr;
    int stockD, *stockA, nd = 0, cap = 0;
    double prec;
    char *codigo, *autor, *titulo, **libro;
    while(true){
        codigo = leerCadena(arch, 15, ',');
        if(arch.eof()) break;
        titulo = leerCadena(arch, 80, ',');
        autor = leerCadena(arch, 60, ',');
        arch >> stockD;
        arch.get();
        arch >> prec;
        arch.get();
        libro = crearLibro(codigo, titulo, autor);
        stockA = crearStock(stockD);
        if(nd == cap)
            aumentarEspacios(libros, stock, nd, cap);
        libros[nd-1] = libro;
        stock[nd-1] = stockA;
        nd++;
    }
}

char *leerCadena(ifstream &arch, int n, char c){
    char buffer[n], *cadena;
    arch.getline(buffer, n, c);
    if(arch.eof()) return nullptr;
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    return cadena;
}

char **crearLibro(char *codigo, char *titulo, char *autor){
    char **libro;
    libro = new char*[3]{};
    libro[0] = codigo;
    libro[1] = titulo;
    libro[2] = autor;
    return libro;
}

int *crearStock(int stockD){
    int *stock;
    stock = new int[2]{};
    stock[0] = stockD;
    stock[1] = 0;
    return stock;
}

void aumentarEspacios(char ***&libros, int **&stock, int &nd, int &cap){
    cap += INCREMENTO;
    char ***auxL;
    int **auxS;
    if(libros == nullptr){
        libros = new char**[cap]{};
        stock = new int*[cap]{};
        nd = 1;
    }
    else{
        auxL = new char**[cap]{};
        auxS = new int*[cap]{};
        for(int i = 0; i < nd; i++){
            auxL[i] = libros[i];
            auxS[i] = stock[i];
        }
        delete libros;
        delete stock;
        libros = auxL;
        stock = auxS;
    }
}

void pruebaDeLecturaDeLibros(const char *filename, char ***libros, int **stock){
    ofstream arch(filename, ios::out);
    if(not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << filename << endl;
        exit(1);
    }
    for(int i = 0; libros[i]; i++){
        char **libro = libros[i];
        int *bloque = stock[i];
        arch << left << setw(10) << libro[0];
        arch << left << setw(60) << libro[1];
        arch << left << setw(30) << libro[2];
        arch << right << setw(5) << bloque[0];
        arch << right << setw(5) << bloque[1] << endl;
    }
}

void atencionDePedidos(const char *filename, char ***libros, int **stock, 
        int **&pedidosClientes, char ***&pedidosLibros, bool **&pedidosAtendidos){
    ifstream arch(filename, ios::in);
    if(not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << filename << endl;
        exit(1);
    }
    pedidosClientes = nullptr;
    pedidosLibros = nullptr;
    pedidosAtendidos = nullptr;
    int numPed, dni, nd = 0, cap = 0, pos, nC[60]{}, capC[60]{}, capP = 0;
    while(true){
        arch >> numPed;
        if(arch.eof()) break;
        arch.get();
        arch >> dni;
        pos = buscarCliente(pedidosClientes, dni);
        if(nd == cap)
            aumentarEspacios(pedidosClientes, nd, cap);
        if(pos == -1){
            crearCliente(pedidosClientes[nd-1], dni, nC[nd-1]);
            actualizarCliente(pedidosClientes[nd-1], numPed, nC[nd-1], capC[nd-1]);
            nd++;
        }
        else
            actualizarCliente(pedidosClientes[pos], numPed, nC[pos], capC[pos]);
        if(numPed >= capP)
            aumentarEspacios(pedidosLibros, pedidosAtendidos, capP, numPed);
        
        break;
    }
}

int buscarCliente(int **pedidosClientes, int dni){
    if(pedidosClientes == nullptr) return -1;
    for(int i = 0; pedidosClientes[i]; i++){
        int *bloque = pedidosClientes[i];
        if(bloque[0] == dni) return i;
    }
    return -1;
}

void aumentarEspacios(int **&pedidosClientes, int &nd, int &cap){
    cap += INCREMENTO;
    int **aux;
    if(pedidosClientes == nullptr){
        pedidosClientes = new int*[cap]{};
        nd = 1;
    }
    else{
        aux = new int*[cap]{};
        for(int i = 0; i < nd; i++)
            aux[i] = pedidosClientes[i];
        delete pedidosClientes;
        pedidosClientes = aux;
    }
}

void crearCliente(int *&cliente, int dni, int &nC){
    cliente = new int[3]{};
    cliente[0] = dni;
    cliente[1] = 0;
    nC = 3;
}

void actualizarCliente(int *&cliente, int numPed, int &nC, int &capC){
    if(nC >= capC)
        aumentarEspacios(cliente, nC, capC);
    cliente[nC-1] = numPed;
    cliente[1]++;
    nC++;
}

void aumentarEspacios(int *&cliente, int &nC, int &capC){
    capC += INCREMENTO;
    int *aux;
    aux = new int[capC]{};
    for(int i = 0; i < nC; i++)
        aux[i] = cliente[i];
    delete cliente;
    cliente = aux;
}

void aumentarEspacios(char ***&pedidosLibros, bool **&pedidosAtendidos, int &capP, 
        int numPed){
    capP = INCREMENTO + numPed;
    char ***auxL;
    bool **auxA;
    if(pedidosLibros == nullptr){
        pedidosLibros = new char**[capP]{};
        pedidosAtendidos = new bool*[capP]{};
    }
    else{
        auxL = new char**[capP]{};
        auxA = new bool*[capP]{};
        for(int i = 0; pedidosLibros[i]; i++){
            auxL[i] = pedidosLibros[i];
            auxA[i] = pedidosAtendidos[i];
        }
        delete pedidosLibros;
        delete pedidosAtendidos;
        pedidosLibros = auxL;
        pedidosAtendidos = auxA;
    }
}