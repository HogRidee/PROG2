#include "MetodoExactoDeMemoria.h"

void lecturaDeLibros(const char *filename, char ***&libros, int **&stock){
    ifstream archLibros(filename, ios::in);
    if(not archLibros.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << filename << endl;
        exit(1);
    }
    int numDat = 0, cap = 0, stockD, *stockP;
    double precio;
    char *codigo, *titulo, *autor, **libro;
    libros = nullptr;
    stock = nullptr;
    while(true){
        codigo = leerCadena(archLibros, 10, ',');
        if(archLibros.eof()) break;
        titulo = leerCadena(archLibros, 100, ',');
        autor = leerCadena(archLibros, 80, ',');
        archLibros >> stockD;
        archLibros.get();
        archLibros >> precio;
        archLibros.get();
        if(numDat == cap)
            aumentarEspacios(libros, stock, numDat, cap);
        libro = crearLibro(codigo, titulo, autor);
        stockP = crearStock(stockD);
        libros[numDat-1] = libro;
        stock[numDat-1] = stockP;
        numDat++;
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

void aumentarEspacios(char ***&libros, int **&stock, int &numDat, int &cap){
    int **auxStock;
    char ***auxLibros;
    cap += INCREMENTO;
    if(libros == nullptr){
        libros = new char **[cap]{};
        stock = new int*[cap]{};
        numDat = 1;
    }
    else{
        auxStock = new int*[cap]{};
        auxLibros = new char**[cap]{};
        for(int i = 0; i < numDat; i++){
            auxStock[i] = stock[i];
            auxLibros[i] = libros[i];
        }
        delete stock;
        delete libros;
        stock = auxStock;
        libros = auxLibros;
    }
}

char **crearLibro(char *codigo, char *titulo, char *autor){
    char **libro;
    libro = new char*[3]{};
    libro[0] = codigo;
    libro[1] = titulo;
    libro[2] = autor;
    return libro;
}

int *crearStock(int stock){
    int *bufferStock;
    bufferStock = new int[2]{};
    bufferStock[0] = stock;
    bufferStock[1] = 0;
    return bufferStock;
}

void pruebaDeLecturaDeLibros(const char *filename, char ***libros, int **stock){
    ofstream archReporte(filename, ios::out);
    if(not archReporte.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << filename << endl;
        exit(1);
    }
    archReporte << setw(40) << " " << "REPORTE DE LIBROS INICIAL" << endl;
    imprimirLinea(archReporte, 120, '=');
    for(int i = 0; libros[i]; i++){
        imprimirLibro(archReporte, libros[i]);
        imprimirStock(archReporte, stock[i]);
    }
}

void imprimirLibro(ofstream &arch, char **libro){
    arch << left << setw(10) << libro[0];
    arch << left << setw(60) << libro[1];
    arch << left << setw(30) << libro[2];
}

void imprimirStock(ofstream &arch, int *stock){
    arch << right << setw(5) << stock[0];
    arch << right << setw(5) << stock[1] << endl;
}

void imprimirLinea(ofstream &arch, int n, char c){
    for(int i = 0; i < n; i++)
        arch.put(c);
    arch << endl;
}

void atencionDePedidos(const char *filename, char ***libros, int **stock, 
        int **&pedidosClientes, char ***&pedidosLibros, bool **&pedidosAtendidos){
    ifstream archPedidos(filename, ios::in);
    if(not archPedidos.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << filename << endl;
        exit(1);
    }
    pedidosClientes = nullptr;
    pedidosAtendidos = nullptr;
    pedidosLibros = nullptr;
    int codigo, dni, pos, numDat = 0, capacidad = 0, nD[60]{}, cap[60]{};
    int capPedidos = 0;
    while(true){
        archPedidos >> codigo;
        if(archPedidos.eof()) break;
        archPedidos.get();
        archPedidos >> dni;
        pos = buscarCliente(dni, pedidosClientes);
        if(numDat == capacidad)
            aumentarEspacios(pedidosClientes, numDat, capacidad);
        if(codigo >= capPedidos)
            aumentarEspacios(pedidosLibros, pedidosAtendidos, capPedidos, codigo);
        if(pos != -1){
            actualizarCliente(pedidosClientes[pos], codigo, nD[pos], cap[pos]);
        }
        else{
            crearCliente(pedidosClientes[numDat-1], dni);
            nD[numDat-1] = 3;
            actualizarCliente(pedidosClientes[numDat-1], codigo, nD[numDat-1], 
                    cap[numDat-1]);
            numDat++;
        }
        procesarPedidos(archPedidos, pedidosLibros[codigo], pedidosAtendidos[codigo], 
                libros, stock);
    }
}

void aumentarEspacios(int **&pedidosClientes, int &numDat, int &capacidad){
    int **auxC;
    capacidad += INCREMENTO;
    if(pedidosClientes == nullptr){
        pedidosClientes = new int*[capacidad]{};
        numDat = 1;
    }
    else{
        auxC = new int*[capacidad]{};
        for(int i = 0; i < numDat; i++){
            auxC[i] = pedidosClientes[i];
        }
        delete pedidosClientes;
        pedidosClientes = auxC;
    }
}

int buscarCliente(int dni, int **pedidosClientes){
    if(pedidosClientes == nullptr) return -1;
    for(int i = 0; pedidosClientes[i]; i++){
        int *pedido = pedidosClientes[i];
        if(pedido[0] == dni) return i;
    }
    return -1;
}

void crearCliente(int *&pedido, int dni){
    pedido = new int[3]{};
    pedido[0] = dni;
    pedido[1] = 0;
}

void actualizarCliente(int *&pedido, int codigo, int &nd, int &cap){
    if(nd >= cap){
        aumentarEspacios(pedido, nd, cap);
    }
    pedido[nd-1] = codigo;
    pedido[1]++;
    nd++;
}

void aumentarEspacios(int *&pedido, int &nd, int &cap){
    cap += INCREMENTO;
    int *aux;
    aux = new int[cap]{};
    for(int i = 0; i < nd; i++)
        aux[i] = pedido[i];
    delete pedido;
    pedido = aux;
}

void aumentarEspacios(char ***&pedidosLibros, bool **&pedidosAtendidos, int &capPedidos, 
        int codigo){
    capPedidos = codigo + INCREMENTO;
    char ***auxL;
    bool **auxA;
    if(pedidosLibros == nullptr){
        pedidosLibros = new char**[capPedidos]{};
        pedidosAtendidos = new bool*[capPedidos]{};
    }
    else{
        auxL = new char**[capPedidos]{};
        auxA = new bool*[capPedidos]{};
        for(int i = 0; i < capPedidos; i++){
            auxL[i] = pedidosLibros[i];
            auxA[i] = pedidosAtendidos[i];
        }
        delete pedidosLibros;
        delete pedidosAtendidos;
        pedidosLibros = auxL;
        pedidosAtendidos = auxA;
    }
}

void procesarPedidos(ifstream &archPedidos, char **&pedidosLibros, bool *&pedidosAtendidos,
        char ***libros, int **stock){
    int nd = 0, cap = 0, pos;
    char *codigo = nullptr;
    pedidosLibros = nullptr;
    pedidosAtendidos = nullptr;
    while(true){
        archPedidos >> ws;
        codigo = new char[8];
        archPedidos.get(codigo, 8);
        if(nd == cap)
            aumentarEspacios(pedidosLibros, pedidosAtendidos, nd, cap);
        pedidosLibros[nd-1] = codigo;
        pos = buscarLibro(codigo, libros);
        if(pos != -1)
            actualizarStock(stock[pos], pedidosAtendidos[nd-1]);
        nd++;
        if(archPedidos.get() == '\n') break;
    }
}

void aumentarEspacios(char **&pedidosLibros, bool *&pedidosAtendidos, int &nd, int &cap){
    char **auxL;
    bool *auxA;
    cap += INCREMENTO;
    if(pedidosLibros == nullptr){
        pedidosLibros = new char*[cap]{};
        pedidosAtendidos = new bool[cap]{};
        nd = 1;
    }
    else{
        auxL = new char*[cap]{};
        auxA = new bool[cap]{};
        for(int i = 0; i < nd; i++){
            auxL[i] = pedidosLibros[i];
            auxA[i] = pedidosAtendidos[i];
        }
        delete pedidosLibros;
        delete pedidosAtendidos;
        pedidosLibros = auxL;
        pedidosAtendidos = auxA;
    }
}

int buscarLibro(char *codigo, char ***libros){
    for(int i = 0; libros[i]; i++){
        char **libro = libros[i];
        if(strcmp(libro[0], codigo) == 0) return i;
    }
    return -1;
}

void actualizarStock(int *stock, bool &pedidosAtendidos){
    if(stock[0] > 0){
        pedidosAtendidos = true;
        stock[0]--;
    }
    else
        stock[1]++;
}

void ordenarPedidosClientes(int **pedidosClientes){
    int numDat = 0;
    while(pedidosClientes[numDat]) numDat++;
    qSort(pedidosClientes, 0, numDat-1);
}

void qSort(int **pedidosClientes, int izq, int der){
    int limite, pos;
    if(izq >= der) return;
    pos = (izq+der)/2;
    cambiar(pedidosClientes[izq], pedidosClientes[pos]);
    limite = izq;
    for(int i = izq+1; i <= der; i++){
        int *datosI = pedidosClientes[i];
        int *datosK = pedidosClientes[izq];
        if(datosI[1] >= datosK[1]){
            limite++;
            if(datosI[1] == datosK[1]){
                if(datosI[0] > datosK[0]){
                    cambiar(pedidosClientes[limite], pedidosClientes[i]);
                }
            }
            else{
                cambiar(pedidosClientes[limite], pedidosClientes[i]);
            }
        }
    }
    cambiar(pedidosClientes[limite], pedidosClientes[izq]);
    qSort(pedidosClientes, izq, limite-1);
    qSort(pedidosClientes, limite+1, der);
}

void cambiar(int *&datoI, int *&datoK){
    int *aux = datoI;
    datoI = datoK;
    datoK = aux;
}

void reporteDeEntregaDePedidos (const char *filename, int **pedidosClientes,
            char ***pedidosLibros, bool **pedidosAtendidos){
    ofstream archReporte(filename, ios::out);
    if(not archReporte.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << filename << endl;
        exit(1);
    }
    archReporte << setw(50) << " " << "REPORTE TOP 5" << endl;
    archReporte << setw(48) << " " << "ATENCION DE PEDIDOS" << endl;
    imprimirLinea(archReporte, 120, '=');
    for(int i = 0; i < 5; i++){
        int *cliente = pedidosClientes[i];
        archReporte << "CLIENTE: " << right << setw(10) << cliente[0] << setw(10) << " ";
        archReporte << "CANTIDAD PEDIDOS: " << right << setw(10) << cliente[1] << endl;
        imprimirLinea(archReporte, 120, '=');
        for(int j = 2; cliente[j]; j++){
            archReporte << setw(5) << " " << "PEDIDO No.";
            archReporte << setw(5) << " " << "Codigo del Libro";
            archReporte << setw(5) << " " << "Observacion" << endl;
            imprimirLinea(archReporte, 120, '-');
            archReporte << setw(5) << " " << right << setw(5) << cliente[j];
            imprimirPedido(archReporte, cliente[j], pedidosLibros, pedidosAtendidos);
            imprimirLinea(archReporte, 120, '=');
        }
    }
}

void imprimirPedido(ofstream &arch, int pedido, char ***pedidosLibros, bool **pedidosAtendidos){
    char **libros = pedidosLibros[pedido];
    bool *atendidos = pedidosAtendidos[pedido];
    arch << setw(15) << " " << left << setw(10) << libros[0];
    if(atendidos[0]) arch << setw(5) << " " << "ATENDIDO" << endl;
    else arch << setw(5) << " " << "NO ATENDIDO" << endl;
    for(int i = 1; libros[i]; i++){
        arch << setw(25) << " " << left << setw(10) << libros[i];
        if(atendidos[i]) arch << setw(5) << " " << "ATENDIDO" << endl;
        else arch << setw(5) << " " << "NO ATENDIDO" << endl;
    }
}