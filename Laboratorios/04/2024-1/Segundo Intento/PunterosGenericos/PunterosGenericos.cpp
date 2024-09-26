#include "PunterosGenericos.h"

void cargaclientes(void *&clientes){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, "Cientes.csv");
    void *reg, *buffer[100]{}, **cli;
    int numDat = 0;
    while(true){
        reg = leerCliente(arch);
        if(arch.eof()) break;
        buffer[numDat] = reg;
        numDat++;
    }
    cli = new void*[numDat+1]{};
    for(int i = 0; i < numDat; i++)
        cli[i] = buffer[i];
    clientes = cli;
    muestraclientes(clientes);
}

void *leerCliente(ifstream &arch){
    void **cliente;
    int d, *dni;
    char *nombre;
    arch >> d;
    if(arch.eof()) return nullptr;
    arch.get();
    nombre = leerCadena(arch, 100, '\n');
    dni = new int;
    *dni = d;
    cliente = new void*[2]{};
    cliente[0] = dni;
    cliente[1] = nombre;
    return cliente;
}

char *leerCadena(ifstream &arch, int n, char c){
    char buffer[n], *cad;
    arch.getline(buffer, n, c);
    if(arch.eof()) return nullptr;
    cad = new char[strlen(buffer)+1];
    strcpy(cad, buffer);
    return cad;
}

void creareserva(void *&reserva){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, "Libros.csv");
    void *reg, *buffer[300]{}, **res;
    int numDat = 0;
    while(true){
        reg = leerLibro(arch);
        if(arch.eof()) break;
        buffer[numDat] = reg;
        numDat++;
    }
    res = new void*[numDat+1]{};
    for(int i = 0; i < numDat; i++)
        res[i] = buffer[i];
    reserva = res;
    muestrareservas(reserva);
}

void *leerLibro(ifstream &arch){
    int s, *stock;
    double precio;
    char *codigo, *titulo, *autor;
    void **libro;
    codigo = leerCadena(arch, 15, ',');
    if(arch.eof()) return nullptr;
    titulo = leerCadena(arch, 100, ',');
    autor = leerCadena(arch, 100, ',');
    arch >> s;
    arch.get();
    arch >> precio;
    arch.get();
    stock = new int;
    *stock = s;
    libro = new void*[5]{};
    libro[0] = codigo;
    libro[1] = titulo;
    libro[2] = autor;
    libro[3] = crearPedido(s);
    libro[4] = stock;
    return libro;
}

void *crearPedido(int stock){
    void **pedido;
    pedido = new void*[stock]{};
    return pedido;
}

void cargareservar(void *clientes, void *reserva){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, "Pedidos2.csv");
    int dni;
    char *codigo;
    while(true){
        arch >> dni;
        if(arch.eof()) break;
        arch.get();
        codigo = leerCadena(arch, 15, '\n');
        cargarReservas(clientes, reserva, dni, codigo);
    }
}

void cargarReservas(void *clientes, void *reserva, int dni, char *codigo){
    int pos = buscarLibro(reserva, codigo);
    void **reservas = (void**)reserva;
    if(pos != -1)
        cargarReserva(reservas[pos], clientes, dni);
}

int buscarLibro(void *res, char *codigo){
    void **reserva = (void**)res;
    for(int i = 0; reserva[i]; i++){
        if(sonIguales(reserva[i], codigo)) return i;
    }
    return -1;
}

bool sonIguales(void *res, char *codigo){
    void **reserva = (void**)res;
    char *cod = (char*)reserva[0];
    if(strcmp(cod, codigo) == 0) return true;
    else return false;
}

void cargarReserva(void *res, void *clientes, int dni){
    void **reserva = (void**)res;
    void **cli = (void**)clientes;
    void *pedido;
    int pos = buscarCliente(clientes, dni);
    int *stock = (int*)reserva[4];
    if(*stock == 0) return;
    pedido = crearPedido(cli[pos]);
    int posP = calcularPosicion(reserva[3]);
    void **pedidos = (void**)reserva[3];
    pedidos[posP] = pedido;
    *stock = *stock - 1;
}

int buscarCliente(void *clientes, int dni){
    void **cli = (void**)clientes;
    for(int i = 0; cli[i]; i++){
        if(sonIguales(cli[i], dni)) return i;
    }
    return -1;
}

bool sonIguales(void *cli, int dni){
    void **cliente = (void**)cli;
    int *d = (int*)cliente[0];
    return *d == dni;
}

void *crearPedido(void *cli){
    void **cliente = (void**)cli;
    void **pedido;
    int *d = (int*)cliente[0];
    char *cod = (char*)cliente[1];
    int *dni;
    char *codigo;
    dni = new int;
    *dni = *d;
    codigo = new char[strlen(cod)+1];
    strcpy(codigo, cod);
    pedido = new void*[2]{};
    pedido[0] = dni;
    pedido[1] = codigo;
    return pedido;
}

int calcularPosicion(void *res){
    void **pedidos = (void**)res;
    int i = 0;
    while(pedidos[i] != nullptr) i++;
    return i;
}