#include "MetodoExactoDeMemoria.h"

void lecturaDeLibros (const char *filename,char ***&libros, int **&stock){
    ifstream archLibros(filename, ios::in);
    if(not archLibros.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << filename << endl;
        exit(1);
    }
    int *buffStock[300]{}, numDat = 0;
    char **buffLib[300]{};
    while(true){
        buffLib[numDat] = leeLibro(archLibros);
        if(archLibros.eof()) break;
        buffStock[numDat] = leeStock(archLibros);
        numDat++;
    }
    libros = new char **[numDat+1]{};
    stock = new int *[numDat+1]{};
    for(int i = 0; i < numDat; i++){
        libros[i] = buffLib[i];
        stock[i] = buffStock[i];
    }
}

char ** leeLibro(ifstream &archLibros){
    char *cod, *titulo, *autor, **libro;
    cod = leerCadenaExacta(archLibros, 10, ',');
    if(archLibros.eof()) return nullptr;
    titulo = leerCadenaExacta(archLibros, 100, ',');
    autor = leerCadenaExacta(archLibros, 80, ',');
    libro = new char*[3]{};
    libro[0] = cod;
    libro[1] = titulo;
    libro[2] = autor;
    return libro;
}

char *leerCadenaExacta(ifstream &arch, int n, char c){
    char buffer[n], *cadena;
    arch.getline(buffer, n, c);
    if(arch.eof()) return nullptr;
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    return cadena;
}

int *leeStock(ifstream &archLibros){
    int *stock;
    stock = new int[2]{};
    double prec;
    archLibros >> stock[0];
    archLibros.get();
    archLibros >> prec;
    archLibros.get();
    stock[1] = 0;
    return stock;
}

void pruebaDeLecturaDeLibros (const char *filename, char ***libros, 
        int **stock){
    ofstream archReporte(filename, ios::out);
    if(not archReporte.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << filename << endl;
        exit(1);
    }
    archReporte << setw(40) << " " << "Reporte de Libros" << endl;
    imprimirLinea(archReporte, 140, '=');
    archReporte << left << setw(10) << "Codigo";
    archReporte << left << setw(60) << "Titulo";
    archReporte << left << setw(50) << "Autor";
    archReporte << left << setw(8) << "Stock";
    archReporte << left << setw(10) << "Cantidad no atendida" << endl;
    imprimirLinea(archReporte, 140, '-');
    for(int i = 0; libros[i]; i++){
        reporteLibros(archReporte, libros[i]);
        reporteStock(archReporte, stock[i]);
    }
}

void imprimirLinea(ofstream &archReporte, int n, char c){
    for(int i = 0; i < n; i++)
        archReporte.put(c);
    archReporte << endl;
}


void reporteLibros(ofstream &arch, char **libros){
    arch << left << setw(10) << libros[0];
    arch << left << setw(60) << libros[1];
    arch << left << setw(50) << libros[2];
}

void reporteStock(ofstream &archReporte, int *stock){
    archReporte << right << setw(5) << stock[0];
    archReporte << right << setw(5) << stock[1] << endl;
}

void atencionDePedidos(const char *filename, char ***&libros, int **&stock, 
        int **&pedidosClientes, char ***&pedidosLibros, bool **&pedidosAtendidos){
    ifstream archPedidos(filename, ios::in);
    if(not archPedidos.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << filename << endl;
        exit(1);
    }
    int *buffPedCli[200]{}, numDat = 0, numPed, dni, pos, n = 0;
    char **buffPedLib[200]{};
    bool *buffPedA[200]{};
    while(true){
        archPedidos >> numPed;
        if(archPedidos.eof()) break;
        archPedidos.get();
        archPedidos >> dni;
        buffPedLib[numPed] = leerLibrosPedido(archPedidos);
        n++;
        pos = buscarCliente(dni, buffPedCli);
        if(pos != -1){
            
        }
        else{
            buffPedCli[numDat] = crearCliente(dni);
            numDat++;
        }
    }
    pedidosClientes = new int*[numDat+1]{};
    pedidosLibros = new char**[n+1]{};
    pedidosAtendidos = new bool*[n+1]{};
    for(int i = 0; i < numDat; i++){
        pedidosClientes[i] = buffPedCli[i];
    }
    for(int i = 0; i < n; i++){
        pedidosLibros[i] = buffPedLib[i];
        pedidosAtendidos[i] = buffPedA[i];
    }
}

char ** leerLibrosPedido(ifstream &archPedidos){
    char *buffLibros[10]{}, *libro, **pedidos;
    int nLibros = 0;
    archPedidos >> ws;
    libro = new char[8];
    archPedidos.get(libro, 8);
    buffLibros[nLibros] = libro;
    nLibros++;
    while(true){
        if(archPedidos.get() == '\n') break;
        archPedidos >> ws;
        buffLibros[nLibros] = leerLibro(archPedidos);
        nLibros++;
    }
    pedidos = new char *[nLibros+1]{};
    for(int i = 0; i < nLibros; i++){
        pedidos[i] = buffLibros[i];
    }
    return pedidos;
}

char *leerLibro(ifstream &archPedidos){
    char *libro;
    libro = new char[8];
    archPedidos.get(libro, 8);
    return libro;
}

int buscarCliente(int dni, int **buffPedCli){
    int *dniC;
    for(int i = 0; buffPedCli[i]; i++){
        dniC = buffPedCli[i];
        if(dniC[0] == dni) return i;
    }
    return -1;
}

int *crearCliente(int dni){
    int *cliente;
    cliente = new int[3]{};
    cliente[0] = dni;
    cliente[1] = 0;
    return cliente;
}

void reporteDeEntregaDePedidos (const char *filename, int **pedidosClientes, 
            char ***pedidosLibros, bool **pedidosAtendidos){
    
}