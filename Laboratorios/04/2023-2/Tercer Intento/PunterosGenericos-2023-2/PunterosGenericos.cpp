#include "PunterosGenericos.h"

void cargaproductos(void *&productos){
    ifstream arch("Productos2.csv", ios::in);
    if(not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo Productos2.csv" << endl;
        exit(1);
    }
    void *producto, *buffer[200]{}, **prod;
    int nd = 0;
    while(true){
        producto = leerProducto(arch);
        if(arch.eof()) break;
        buffer[nd] = producto;
        nd++;
    }
    prod = new void*[nd+1]{};
    for(int i = 0; i < nd; i++)
        prod[i] = buffer[i];
    productos = prod;
    imprimeproductos(productos);
}

void *leerProducto(ifstream &arch){
    void **producto;
    double precio, *p;
    char *codigo, *descripcion, tipo, *t;
    codigo = leerCadena(arch, 15, ',');
    if(arch.eof()) return nullptr;
    descripcion = leerCadena(arch, 100, ',');
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
    producto[1] = descripcion;
    producto[2] = p;
    producto[3] = t;
    return producto;
}

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
    int nd = 0;
    while(true){
        cliente = leerCliente(arch);
        if(arch.eof()) break;
        buffer[nd] = cliente;
        nd++;
    }
    cli = new void*[nd+1]{};
    for(int i = 0; i < nd; i++)
        cli[i] = buffer[i];
    clientes = cli;
    imprimeclientes(clientes);
}

void *leerCliente(ifstream &arch){
    void **cliente;
    int dni, telefono, *d;
    double lc, *lineaC;
    char *nombre;
    arch >> dni;
    if(arch.eof()) return nullptr;
    arch.get();
    nombre = leerCadena(arch, 100, ',');
    arch >> telefono;
    arch.get();
    arch >> lc;
    arch.get();
    d = new int;
    lineaC = new double;
    *d = dni;
    *lineaC = lc;
    cliente = new void*[4]{};
    cliente[0] = d;
    cliente[1] = nombre;
    cliente[3] = lineaC;
    return cliente;
}

void cargapedidos(void *productos, void *clientes){
    ifstream arch("Pedidos2.csv");
    if(not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo Pedidos2.csv" << endl;
        exit(1);
    }
    void *buffer[200]{};
    void **cliente = (void**)clientes;
    for(int i = 0; i < 200; i++) buffer[i] = new void*[100]{};
    int dni, cant, posP, posC, nd[200]{};
    bool necesitaC;
    double precio, lC;
    char *codigo;
    while(true){
        leerPedido(arch, codigo, dni, cant);
        if(arch.eof()) break;
        posP = buscarProducto(productos, codigo, precio, necesitaC);
        posC = buscarCliente(clientes, dni, lC);
        if(posC != -1){
            if(lC - (cant*precio) >= 0 or not necesitaC){
                insertarPedido(buffer[posC], nd[posC], codigo, cant, cant*precio);
                if(necesitaC){
                    void **info = (void**)cliente[posC];
                    double *linea = (double*)info[3];
                    *linea = (*linea) - (cant*precio);
                }
            }
        }
    }
    for(int i = 0; cliente[i]; i++)
        asignarMemoriaExacta(cliente[i], buffer[i], nd[i]);
    imprimerepfinal(clientes);
}

void leerPedido(ifstream &arch, char *&codigo, int &dni, int &cant){
    codigo = leerCadena(arch, 15, ',');
    if(arch.eof()) return;
    arch >> dni;
    arch.get();
    arch >> cant;
    arch.get();
}

int buscarProducto(void *productos, char *codigo, double &precio, bool &necesitaC){
    void **producto = (void**)productos;
    for(int i = 0; producto[i]; i++){
        if(sonIguales(producto[i], codigo)){
            void **info = (void**)producto[i];
            double *p = (double*)info[2];
            char *tipo = (char*)info[3];
            precio = *p;
            if(*tipo == 'S') necesitaC = true;
            else necesitaC = false;
            return i;
        }
    }
    return -1;
}

bool sonIguales(void *producto, char *codigo){
    void **info = (void**)producto;
    char *cod = (char*)info[0];
    return strcmp(cod, codigo) == 0;
}

int buscarCliente(void *clientes, int dni, double &lC){
    void **cliente = (void**)clientes;
    for(int i = 0; cliente[i]; i++){
        if(sonIguales(cliente[i], dni)){
            void **info = (void**)cliente[i];
            double *linea = (double*)info[3];
            lC = *linea;
            return i;
        }
    }
    return -1;
}

bool sonIguales(void *cliente, int dni){
    void **info = (void**)cliente;
    int *d = (int*)info[0];
    return *d == dni;
}

void insertarPedido(void *&buffer, int &nd, char *codigo, int cant, double total){
    void **pedido = (void **)buffer;
    pedido[nd] = new void*[3]{};
    void **info = (void**)pedido[nd];
    int *c;
    double *t;
    c = new int;
    t = new double;
    *c = cant;
    *t = total;
    info[0] = codigo;
    info[1] = c;
    info[2] = t;
    nd++;
}

void asignarMemoriaExacta(void *&cliente, void *buffer, int nd){
    void **infoC = (void**)cliente;
    infoC[2] = new void*[nd+1]{};
    void **auxC = (void**)infoC[2];
    void **auxB = (void**)buffer;
    for(int i = 0; i < nd; i++)
        auxC[i] = auxB[i];
}

void imprimereporte(void *clientes){
    void **cliente = (void**)clientes;
    ofstream arch("ReporteDePedidos.txt", ios::out);
    if(not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo ReporteDePedidos.txt" << endl;
        exit(1);
    }
    for(int i = 0; cliente[i]; i++){
        imprimirLinea(arch, 100, '=');
        imprimirCabecera(arch, cliente[i]);
        imprimirPedidos(arch, cliente[i]);
    }
}

void imprimirLinea(ofstream &arch, int n, char c){
    for(int i = 0; i < n; i++)
        arch.put(c);
    arch << endl;
}

void imprimirCabecera(ofstream &arch, void *cliente){
    void **info = (void**)cliente;
    int *dni = (int*)info[0];
    char *nombre = (char*)info[1];
    double *credito = (double*)info[3];
    arch << left << setw(15) << "DNI";
    arch << left << setw(40) << "Nombre";
    arch << left << setw(15) << "Credito" << endl;
    arch << right << *dni << setw(5) << " ";
    arch << left << setw(35) << nombre;
    arch << right << setw(15) << *credito << endl;
    imprimirLinea(arch, 100, '-');
}

void imprimirPedidos(ofstream &arch, void *cliente){
    void **info = (void**)cliente;
    void **pedidos = (void**)info[2];
    arch << "Pedidos atendidos: " << endl;
    imprimirLinea(arch, 100, '-');
    arch << left << setw(15) << "Codigo";
    arch << left << setw(15) << "Cantidad";
    arch << left << setw(15) << "Total" << endl;
    imprimirLinea(arch, 100, '-');
    for(int i = 0; pedidos[i]; i++){
        void **infoP = (void**)pedidos[i];
        char *cod = (char*)infoP[0];
        int *cant = (int*)infoP[1];
        double *total = (double*)infoP[2];
        arch << left << setw(15) << cod;
        arch << right << setw(5) << *cant;
        arch << right << setw(15) << *total << endl;
    }
    arch << endl;
}