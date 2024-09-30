#include "PunterosGenericos.h"

void cargaproductos(void *&productos){
    ifstream arch("Productos2.csv", ios::in);
    if(not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo Productos2.csv" << endl;
        exit(1);
    }
    void *prod, *buffer[200]{}, **producto;
    int nd = 0;
    while(true){
        prod = leerProducto(arch);
        if(arch.eof()) break;
        buffer[nd] = prod;
        nd++;
    }
    producto = new void*[nd+1]{};
    for(int i = 0; i < nd; i++)
        producto[i] = buffer[i];
    productos = producto;
    imprimeproductos(productos);
}

void *leerProducto(ifstream &arch){
    void **producto;
    double pre, *precio;
    char *codigo, *descripcion, tip, *tipo;
    codigo = leerCadena(arch, 15, ',');
    descripcion = leerCadena(arch, 100, ',');
    arch >> pre;
    arch.get();
    arch >> tip;
    arch.get();
    precio = new double;
    *precio = pre;
    tipo = new char;
    *tipo = tip;
    producto = new void*[4]{};
    producto[0] = codigo;
    producto[1] = descripcion;
    producto[2] = precio;
    producto[3] = tipo;
    return producto;
}

char *leerCadena(ifstream &arch, int n, char c){
    char buffer[n], *cadena;
    arch.getline(buffer, n, c);
    if(arch.eof()) return nullptr;
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    return cadena;
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
    int d, *dni, telefono;
    double lc, *lineaC;
    char *nombre;
    arch >> d;
    arch.get();
    nombre = leerCadena(arch, 100, ',');
    arch >> telefono;
    arch.get();
    arch >> lc;
    arch.get();
    dni = new int;
    lineaC = new double;
    *dni = d;
    *lineaC = lc;
    cliente = new void*[4]{};
    cliente[0] = dni;
    cliente[1] = nombre;
    cliente[3] = lineaC;
    return cliente;
}

void cargapedido(void *productos, void *clientes){
    ifstream arch("Pedidos2.csv", ios::in);
    if(not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo Pedidos2.csv" << endl;
        exit(1);
    }
    void *buffer[200]{};
    void **cli = (void**)clientes;
    for(int i = 0; i < 200; i++) buffer[i] = new void*[100]{};
    int dni, cant, posP, posC, nd[200]{};
    bool esCred;
    double precio, lineaC;
    char *codigo;
    while(true){
        leerPedido(arch, codigo, dni, cant);
        if(arch.eof()) break;
        posP = buscarProducto(productos, codigo, esCred, precio);
        posC = buscarCliente(clientes, dni, lineaC);
        if(posC != -1){
            if((lineaC - (cant*precio) >= 0) or (not esCred)){
                insertarPedido(buffer[posC], nd[posC], codigo, cant, cant*precio);
                if(esCred){
                    void **info = (void**)cli[posC];
                    double *cred = (double*)info[3];
                    *cred = (*cred) - (cant*precio);
                }
            }
        }
    }
    for(int i = 0; cli[i]; i++)
        asignarMemoriaExacta(buffer[i], cli[i], nd[i]);
    imprimerepfinal(clientes);
}

void leerPedido(ifstream &arch, char *&codigo, int &dni, int &cant){
    codigo = leerCadena(arch, 15, ',');
    if(arch.eof()) return;
    arch >> dni;
    arch.get();
    arch >>cant;
    arch.get();
}

int buscarProducto(void *productos, char *codigo, bool &esCred, double &precio){
    void **prod = (void**)productos;
    for(int i = 0; prod[i]; i++){
        if(sonIguales(prod[i], codigo)){
            void **info = (void**)prod[i];
            double *prec = (double*)info[2];
            char *tipo = (char*)info[3];
            if(*tipo == 'S') esCred = true;
            else esCred = false;
            precio = *prec;
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

int buscarCliente(void *clientes, int dni, double &lineaC){
    void **cli = (void**)clientes;
    for(int i = 0; cli[i]; i++){
        if(sonIguales(cli[i], dni)){
            void **info = (void**)cli[i];
            double *lc = (double*)info[3];
            lineaC = *lc;
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

void insertarPedido(void *&buffer, int &nd, char *codigo, int cantt, double totall){
    void **pedido = (void**)buffer;
    int *cant;
    double *total;
    cant = new int;
    total = new double;
    *cant = cantt;
    *total = totall;
    pedido[nd] = new void*[3]{};
    void **prod = (void**)pedido[nd];
    prod[0] = codigo;
    prod[1] = cant;
    prod[2] = total;
    nd++;
}

void asignarMemoriaExacta(void *buffer, void *&cli, int nd){
    void **cliente = (void**)cli;
    cliente[2] = new void*[nd+1]{};
    void **auxC = (void**)cliente[2];
    void **auxB = (void**)buffer;
    for(int i = 0; i < nd; i++)
        auxC[i] = auxB[i];
}

void imprimereporte(void *clientes){
    ofstream arch("ReporteDePedidos.txt", ios::out);
    if(not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo ReporteDePedidos.txt" << endl;
        exit(1);
    }
    void **cli = (void**)clientes;
    for(int i = 0; cli[i]; i++){
        imprimirLinea(arch, 100, '=');
        imprimirCabecera(arch, cli[i]);
        imprimirPedidos(arch, cli[i]);
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
    char *cod = (char*)info[1];
    double *cred = (double*)info[3];
    arch << left << setw(20) << "DNI";
    arch << left << setw(46) << "Nombre";
    arch << left << setw(20) << "Credito" << endl;
    arch << right << *dni << setw(10) << " ";
    arch << left << setw(35) << cod;
    arch << right << setw(20) << *cred << endl;
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
        void **pedido = (void**)pedidos[i];
        char *cod = (char*)pedido[0];
        int *cant = (int*)pedido[1];
        double *total = (double*)pedido[2];
        arch << left << setw(15) << cod;
        arch << right << setw(5) << *cant;
        arch << right << setw(15) << *total << endl;
    }
    arch << endl;
}