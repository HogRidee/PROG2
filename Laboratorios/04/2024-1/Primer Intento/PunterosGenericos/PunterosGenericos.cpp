#include "PunterosGenericos.h"

void cargaclientes(void *&clientes){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, "Cientes.csv");
    int numDat = 0;
    void *buffCli[100]{}, **cli, *reg;
    while(true){
        reg = leerRegistro(arch);
        if(arch.eof()) break;
        buffCli[numDat] = reg;
        numDat++;
    }
    cli = new void*[numDat+1]{};
    for(int i = 0; i < numDat; i++)
        cli[i] = buffCli[i];
    clientes = cli;
    muestraclientes(clientes);
}

void *leerRegistro(ifstream &arch){
    void **registro;
    int *dni, d;
    char *nombre;
    arch >> d;
    if(arch.eof()) return nullptr;
    dni = new int;
    *dni = d;
    arch.get();
    nombre = leerCadena(arch, 100, '\n');
    registro = new void*[2]{};
    registro[0] = dni;
    registro[1] = nombre;
    return registro;
}

char *leerCadena(ifstream &arch, int n, char c){
    char buffer[n], *cad;
    arch.getline(buffer, n, c);
    cad = new char[strlen(buffer)+1];
    strcpy(cad, buffer);
    return cad;
}

void creareserva(void *&reserva){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, "Libros.csv");
    int numDat = 0;
    void *buffRe[300]{}, **re, *reg;
    while(true){
        reg = leerReserva(arch);
        if(arch.eof()) break;
        buffRe[numDat] = reg;
        numDat++;
    }
    re = new void*[numDat+1]{};
    for(int i = 0; i < numDat; i++)
        re[i] = buffRe[i];
    reserva = re;
    muestrareservas(reserva);
}

void *leerReserva(ifstream &arch){
    void **registro;
    int *stock, s;
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
    registro = new void*[5]{};
    registro[0] = codigo;
    registro[1] = titulo;
    registro[2] = autor;
    registro[3] = crearPedido(s);
    registro[4] = stock;
    return registro;
}

void *crearPedido(int s){
    void **pedido;
    pedido = new void*[s]{};
    return pedido;
}

void cargareserva(void *clientes, void *reserva){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, "Pedidos2.csv");
    int dni;
    char *codigo;
    while(true){
        arch >> dni;
        if(arch.eof()) break;
        arch.get();
        codigo = leerCadena(arch, 15, '\n');
        colocarPedido(clientes, reserva, dni, codigo);
    }
    delete codigo;
}

void colocarPedido(void *cli, void *res, int dni, char *codigo){
    void **reservas = (void**)res;
    int pos = buscarLibro(res, codigo);
    if(pos != -1)
        colocarCliente(reservas[pos], dni, cli);
}

int buscarLibro(void *res, char *codigo){
    void **reservas = (void**)res;
    for(int i = 0; reservas[i]; i++)
        if(sonIguales(codigo, reservas[i])) return i;
    return -1;
}

bool sonIguales(char *codigo, void *res){
    void **reserva = (void**)res;
    char *cod = (char *)reserva[0];
    if(strcmp(cod, codigo) == 0) return true;
    else return false;
}

void colocarCliente(void *res, int dni, void *cli){
    void **reserva = (void**)res;
    void **cliente = (void**)cli;
    void *pedido;
    int *stock = (int*)reserva[4];
    int pos = buscarCliente(cli, dni);
    if(pos != -1){
        int posP = calcularPosicion(reserva[3]);
        if(*stock == 0) return;
        pedido = crearPedido(cliente[pos]);
        colocarPedido(reserva[3], pedido, posP);
        *stock = *stock-1;
    }
}

int buscarCliente(void *cli, int dni){
    void **clientes = (void**)cli;
    for(int i = 0; clientes[i]; i++)
        if(sonIguales(dni, clientes[i])) return i;
    return -1;
}

bool sonIguales(int dni, void *cli){
    void **cliente = (void**)cli;
    int *d = (int*)cliente[0];
    return *d == dni;
}

void *crearPedido(void *cli){
    void **cliente = (void**)cli;
    void **pedido;
    pedido = new void*[2]{};
    int *dni, *d;
    char *nombre;
    dni = new int;
    d = (int*)cliente[0];
    *dni = *d;
    char *nomb = (char*)cliente[1];
    nombre = new char[strlen(nomb)+1];
    strcpy(nombre, nomb);
    pedido[0] = dni;
    pedido[1] = nombre;
    return pedido;
}

int calcularPosicion(void *res){
    void **pedidos = (void**)res;
    int i = 0;
    for(i = 0; pedidos[i]; i++){
        
    }
    return i;    
}

void colocarPedido(void *res, void *pedido, int posP){
    void **pedidos = (void**)res;
    pedidos[posP] = pedido;
}