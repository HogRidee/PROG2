#include "PunterosGenericos.h"

void cargaproductos(void *&productos){
    ifstream arch("Productos2.csv", ios::in);
    if(not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo Productos2.csv" << endl;
        exit(1);
    }
    void *producto, *buffer[200]{}, **prod;
    int numDat = 0;
    while(true){
        producto = leerProducto(arch);
        if(arch.eof()) break;
        buffer[numDat] = producto;
        numDat++;
    }
    prod = new void*[numDat+1]{};
    for(int i = 0; i < numDat; i++)
        prod[i] = buffer[i];
    productos = prod;
    imprimeproductos(productos);
}

void *leerProducto(ifstream &arch){
    void **producto;
    double precio, *p;
    char *codigo, *nombre, tipo, *t;
    codigo = leerCadena(arch, 15, ',');
    if(arch.eof()) return nullptr;
    nombre = leerCadena(arch, 100, ',');
    arch >> precio;
    arch.get();
    arch >> tipo;
    arch.get();
    p = new double;
    t = new char;
    *p = precio;
    *t = tipo;
    producto = new void*[4]{};
    producto[0] = codigo;
    producto[1] = nombre;
    producto[2] = p;
    producto[3] = t;
    return producto;
}

//int convertirACodigo(const char* cadena) {
//    int codigo = 0;
//    for (int i = 0; cadena[i] != '\0'; ++i) {
//        codigo = codigo * 10 + (cadena[i] - '0'); 
//    }
//    return codigo;
//}

char *leerCadena(ifstream &arch, int n, char c){
    char buffer[n], *cad;
    arch.getline(buffer, n, c);
    if(arch.eof()) return nullptr;
    cad = new char[strlen(buffer)+1];
    strcpy(cad, buffer);
    return cad;
}

void cargaclientes(void *&clientes){
    ifstream arch("Clientes2.csv", ios::in);
    if(not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo Clientes2.csv" << endl;
        exit(1);
    }
    void *cliente, *buffer[200]{}, **cli;
    int numDat = 0;
    while(true){
        cliente = leerCliente(arch);
        if(arch.eof()) break;
        buffer[numDat] = cliente;
        numDat++;
    }
    cli = new void*[numDat+1]{};
    for(int i = 0; i < numDat; i++)
        cli[i] = buffer[i];
    clientes = cli;
    imprimeclientes(clientes);
}

void *leerCliente(ifstream &arch){
    void **cliente;
    int dni, *d, telefono;
    double lineaC, *lC;
    char *nombre;
    arch >> dni;
    if(arch.eof()) return nullptr;
    arch.get();
    nombre = leerCadena(arch, 100, ',');
    arch >> telefono;
    arch.get();
    arch >> lineaC;
    arch.get();
    d = new int;
    lC = new double;
    *d = dni;
    *lC = lineaC;
    cliente = new void*[4]{};
    cliente[0] = d;
    cliente[1] = nombre;
    cliente[3] = lC;
    return cliente;
}

//FRACASÉ
void cargapedidos(void *productos, void *clientes){
    ifstream arch("Pedidos2.csv", ios::in);
    if(not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo Pedidos2.csv" << endl;
        exit(1);
    }
    void **buffer[200]{}, ***pedidos;
    for(int i = 0; i < 200; i++) buffer[i] = new void*[50]{};
    int dni, cant, nP[200]{}, pos;
    char *codigo;
    while(true){
        codigo = leerCadena(arch, 15, ',');
        if(arch.eof()) break;
        arch >> dni;
        arch.get();
        arch >> cant;
        arch.get();
        pos = buscarCliente(clientes, dni);
        if(pos != -1){
            void **cliente = (void**)clientes;
            cargarPedido(cliente[pos], nP[pos], buffer[pos], productos, codigo, 
                    cant);
        }
        delete codigo;
    }
    int nClientes = devolverCantClientes(clientes);
    void **cli = (void**)clientes;
    pedidos = new void**[nClientes+1]{};
    for(int i = 0; i < nClientes; i++){
        pedidos[i] = new void*[nP[i]+1]{};
        for(int j = 0; j < nP[i]; j++){
            void **ped = (void**)buffer[i];
            void **pedido = (void**)pedidos[i];
            pedido[j] = ped[j];
        }
        void **info = (void**)cli[i];
        info[2] = pedidos[i];
    }
    imprimerepfinal(clientes);
}

int buscarCliente(void *clientes, int dni){
    void **cliente = (void**)clientes;
    for(int i = 0; cliente[i]; i++){
        if(sonIguales(cliente[i], dni)) return i;
    }
    return -1;
}

bool sonIguales(void* cliente, int dni){
    void **info = (void**)cliente;
    int *d = (int*)info[0];
    return *d == dni;
}

void cargarPedido(void *cliente, int &nP, void *buffer, void *productos, 
        char *codigo, int cant){
    void **producto = (void**)productos;
    void **bufferP = (void**)buffer;
    int pos;
    bool necesitaCredito, tieneC;
    pos = buscarProducto(productos, codigo);
    necesitaCredito = verificarTipo(producto[pos]);
    if(necesitaCredito){
        tieneC = verificarCredito(producto[pos], cliente, cant);
        if(tieneC){
            asignarPedido(bufferP[nP], producto[pos], cant);
            disminuirLC(cliente, producto[pos], cant);
            nP++;
        }
    }
    else{
        asignarPedido(bufferP[nP], producto[pos], cant);
        nP++;
    }
}

int buscarProducto(void *productos, char *codigo){
    void **prod = (void**)productos;
    for(int i = 0; prod[i]; i++)
        if(sonIguales(prod[i], codigo)) return i;
    return -1;
}

bool sonIguales(void *producto, char *codigo){
    void **info = (void **)producto;
    char *cod = (char*)info[0];
    return strcmp(cod, codigo) == 0;
}

bool verificarTipo(void *producto){
    void **info = (void**)producto;
    char *tipo = (char*)info[3];
    return *tipo == 'S';
}

bool verificarCredito(void *producto, void *cliente, int cant){
    void **info = (void**)producto;
    void **infoC = (void**)cliente;
    double *precio = (double*)info[2];
    double *lC = (double*)infoC[3];
    double total = cant * (*precio);
    return *lC >= total;
}

void asignarPedido(void *buffer, void *producto, int cant){
    void *pedido;
    pedido = crearPedido(producto, cant);
    buffer = pedido;
}

void *crearPedido(void *producto, int cant){
    void **pedido;
    void **info = (void**)producto;
    int *c;
    char *cod;
    char *codigo = (char*)info[0];
    double *precio = (double*)info[2];
    double total, *t;
    total = (*precio) * cant;
    c = new int;
    *c = cant;
    t = new double;
    cod = new char[strlen(codigo)+1];
    *t = total;
    strcpy(cod, codigo);
    pedido = new void*[3]{};
    pedido[0] = cod;
    pedido[1] = c;
    pedido[2] = t;
    return pedido;
}

void disminuirLC(void *cliente, void *producto, int cant){
    void **info = (void**)cliente;
    void **infoP = (void**)producto;
    double *lC = (double*)info[3];
    double *precio = (double*)infoP[2];
    double total;
    total = cant * (*precio);
    *lC = (*lC) - total;
}

int devolverCantClientes(void *cliente){
    void **clientes = (void**)cliente;
    int i = 0;
    for(i = 0; clientes[i]; i++){
        
    }
    return i;
}

void imprimereporte(void *clientes){
    
}