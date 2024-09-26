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
    int dni, *d;
    char *nombre;
    arch >> dni;
    if(arch.eof()) return nullptr;
    arch.get();
    nombre = leerCadena(arch, 100, '\n');
    d = new int;
    *d = dni;
    cliente = new void*[2]{};
    cliente[0] = d;
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
    void *reg, *buffer[300], **res;
    int numDat = 0;
    while(true){
        reg = leerReserva(arch);
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

void *leerReserva(ifstream &arch){
    void **reserva;
    int s, *stock;
    double p;
    char *codigo, *titulo, *autor;
    codigo = leerCadena(arch, 15, ',');
    if(arch.eof()) return nullptr;
    titulo = leerCadena(arch, 100, ',');
    autor = leerCadena(arch, 100, ',');
    arch >> s;
    arch.get();
    arch >> p;
    arch.get();
    stock = new int;
    *stock = s;
    reserva = new void*[5]{};
    reserva[0] = codigo;
    reserva[1] = titulo;
    reserva[2] = autor;
    reserva[3] = crearPedidos(s);
    reserva[4] = stock;
    return reserva;
}

void *crearPedidos(int stock){
    void **pedidos;
    pedidos = new void*[stock+1]{};
    return pedidos;
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
        cargarPedidos(clientes, reserva, dni, codigo);
        delete codigo;
    }
}

void cargarPedidos(void *clientes, void *reserva, int dni, char *codigo){
    void **reservas = (void**)reserva;
    int pos = buscarLibro(reserva, codigo);
    if(pos != -1){
        cargarPedido(clientes, reservas[pos], dni);
    }
}

int buscarLibro(void *reserva, char *codigo){
    void **res = (void**)reserva;
    for(int i = 0; res[i]; i++){
        if(sonIguales(res[i], codigo)) return i;
    }
    return -1;
}

bool sonIguales(void *res, char *codigo){
    void **libro = (void**)res;
    char *cod = (char*)libro[0];
    return strcmp(cod, codigo) == 0;
}

void cargarPedido(void *clientes, void *res, int dni){
    void **libro = (void**)res;
    void **cli = (void**)clientes;
    void *pedido;
    int pos = buscarCliente(clientes, dni);
    if(pos != -1){
        int *stock = (int*)libro[4];
        if(*stock == 0) return;
        int posP = calcularPosicion(libro[3]);
        pedido = crearPedido(cli[pos]);
        asignarPedido(pedido, libro[3], posP);
        *stock = *stock - 1;
    }
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

int calcularPosicion(void *pedidos){
    void **pedido = (void**)pedidos;
    int i = 0;
    while(pedido[i] != nullptr) i++;
    return i;
}

void *crearPedido(void *cli){
    void **pedido;
    void **cliente = (void**)cli;
    int *d = (int*)cliente[0];
    char *nomb = (char*)cliente[1];
    int *dni;
    char *nombre;
    dni = new int;
    *dni = *d;
    nombre = new char[strlen(nomb)+1];
    strcpy(nombre, nomb);
    pedido = new void*[2]{};
    pedido[0] = dni;
    pedido[1] = nombre;
    return pedido;
}

void asignarPedido(void *pedido, void *pedidos, int posP){
    void **ped = (void**)pedidos;
    ped[posP] = pedido;
}