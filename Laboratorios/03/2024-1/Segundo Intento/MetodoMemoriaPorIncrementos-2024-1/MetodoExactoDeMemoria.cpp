#include "MetodoExactoDeMemoria.h"

void lecturaDeLibros(const char *filename, char ***&libros, int **&stock){
    ifstream archLibros(filename, ios::in);
    if(not archLibros.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << filename << endl;
        exit(1);
    }
    libros = nullptr;
    stock = nullptr;
    int stockD, nd = 0, cap = 0, *stockA;
    double prec;
    char *codigo, *titulo, *autor, **libro;
    while(true){
        codigo = leerCadena(archLibros, 10, ',');
        if(archLibros.eof()) break;
        titulo = leerCadena(archLibros, 80, ',');
        autor = leerCadena(archLibros, 60, ',');
        archLibros >> stockD;
        archLibros.get();
        archLibros >> prec;
        archLibros.get();
        if(nd == cap)
            aumentarEspacios(libros, stock, nd, cap);
        libro = asignarLibro(codigo, titulo, autor);
        stockA = asignarStock(stockD);
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

char **asignarLibro(char *codigo, char *titulo, char *autor){
    char **libro;
    libro = new char*[3]{};
    libro[0] = codigo;
    libro[1] = titulo;
    libro[2] = autor;
    return libro;
}

int *asignarStock(int stockD){
    int *stock;
    stock = new int[2]{};
    stock[0] = stockD;
    stock[1] = 0;
    return stock;
}

void pruebaDeLecturaDeLibros(const char *filename, char ***libros, int **stock){
    ofstream arch(filename, ios::out);
    if(not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << filename << endl;
        exit(1);
    }
    for(int i = 0; libros[i]; i++){
        char **libro = libros[i];
        int *stockA = stock[i];
        arch << left << setw(10) << libro[0];
        arch << left << setw(60) << libro[1];
        arch << left << setw(40) << libro[2];
        arch << right << setw(5) << stockA[0];
        arch << right << setw(5) << stockA[1] << endl;
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
    int numPed, dni, nd = 0, cap = 0, pos, numDat[60]{}, caP[60]{}, cp = 0;
    while(true){
        arch >> numPed;
        if(arch.eof()) break;
        arch.get();
        arch >> dni;
        if(nd == cap)
            aumentarEspacios(pedidosClientes, nd, cap);
        pos = buscarCliente(pedidosClientes, dni);
        if(pos == -1){
            crearCliente(pedidosClientes[nd-1], dni, numDat[nd-1], caP[nd-1]);
            actualizarCliente(pedidosClientes[nd-1], numPed, numDat[nd-1], caP[nd-1]);
            nd++;
        }
        else
            actualizarCliente(pedidosClientes[pos], numPed, numDat[pos], caP[pos]);
        if(numPed >= cp)
            aumentarEspacios(pedidosLibros, pedidosAtendidos, numPed, cp);
        leerPedidos(arch, pedidosLibros[numPed], pedidosAtendidos[numPed], libros, 
                stock);
    }
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

int buscarCliente(int **pedidosClientes, int dni){
    for(int i = 0; pedidosClientes[i]; i++){
        int *pedido = pedidosClientes[i];
        if(pedido[0] == dni) return i;
    }
    return -1;
}

void crearCliente(int *&pedido, int dni, int &numDat, int &caP){
    pedido = new int[3]{};
    pedido[0] = dni;
    pedido[1] = 0;
    numDat = 3;
}

void actualizarCliente(int *&pedido, int numPed, int &numDat, int &caP){
    if(numDat >= caP)
        aumentarEspacios(pedido, numDat, caP);
    pedido[numDat-1] = numPed;
    pedido[1]++;
    numDat++;
}

void aumentarEspacios(int *&pedido, int &numDat, int &caP){
    caP += INCREMENTO;
    int *aux;
    aux = new int[caP]{};
    for(int i = 0; i < numDat; i++)
        aux[i] = pedido[i];
    delete pedido;
    pedido = aux;
}

void aumentarEspacios(char ***&pedidosLibros, bool **&pedidosAtendidos, int numPed, int &cp){
    cp = numPed += INCREMENTO;
    char ***auxL;
    bool **auxA;
    if(pedidosLibros == nullptr){
        pedidosLibros = new char**[cp]{};
        pedidosAtendidos = new bool*[cp]{};
    }
    else{
        auxL = new char**[cp]{};
        auxA = new bool*[cp]{};
        for(int i = 0; i < cp; i++){
            auxL[i] = pedidosLibros[i];
            auxA[i] = pedidosAtendidos[i];
        }
        delete pedidosLibros;
        delete pedidosAtendidos;
        pedidosLibros = auxL;
        pedidosAtendidos = auxA;
    }
}

void leerPedidos(ifstream &arch, char **&libross, bool *&pedidos, char ***libros, 
        int **stock){
    int nd = 0, cap = 0;
    libross = nullptr;
    pedidos = nullptr;
    char *codigo = nullptr;
    while(true){
        if(nd == cap)
            aumentarEspacios(libross, pedidos, nd, cap);
        arch >> ws;
        codigo = new char[8];
        arch.get(codigo, 8);
        int pos = buscarLibro(codigo, libros);
        if(pos != -1)
            ajustarStock(stock[pos], pedidos[nd-1]);
        else
            pedidos[nd-1] = false;
        libross[nd-1] = codigo;
        nd++;
        if(arch.get() == '\n') break;
    }
}

void aumentarEspacios(char **&libros, bool *&pedidos, int &nd, int &cap){
    char **auxL;
    bool *auxP;
    cap += INCREMENTO;
    if(libros == nullptr){
        libros = new char*[cap]{};
        pedidos = new bool[cap]{};
        nd = 1;
    }
    else{
        auxL = new char*[cap]{};
        auxP = new bool[cap]{};
        for(int i = 0; i < nd; i++){
            auxL[i] = libros[i];
            auxP[i] = pedidos[i];
        }
        delete libros;
        delete pedidos;
        libros = auxL;
        pedidos = auxP;
    }
}

int buscarLibro(char *codigo, char ***libros){
    for(int i = 0; libros[i]; i++){
        char **libro = libros[i];
        if(strcmp(codigo, libro[0]) == 0) return i;
    }
    return -1;
}

void ajustarStock(int *stock, bool &pedido){
    if(stock[0] > 0){
        pedido = true;
        stock[0]--;
    }
    else{
        pedido = false;
        stock[1]++;
    }
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
        int *info1 = pedidosClientes[i];
        int *info2 = pedidosClientes[izq];
        if(info1[1] >= info2[1]){
            limite++;
            if(info1[1] == info2[1]){
                if(info1[0] > info2[0])
                    cambiar(pedidosClientes[limite], pedidosClientes[i]);
            }
            else
                cambiar(pedidosClientes[limite], pedidosClientes[i]);
        }
    }
    cambiar(pedidosClientes[limite], pedidosClientes[izq]);
    qSort(pedidosClientes, izq, limite-1);
    qSort(pedidosClientes, limite+1, der);
}

void cambiar(int *&datosI, int *&datosK){
    int *aux;
    aux = datosI;
    datosI = datosK;
    datosK = aux;
}

void reporteDeEntregaDePedidos(const char *filename, int **pedidosClientes, 
            char ***pedidosLibros, bool **pedidosAtendidos){
    ofstream arch(filename, ios::out);
    if(not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << filename << endl;
        exit(1);
    }
    arch << setw(53) << " " << "REPORTE TOP 5" << endl;
    arch << setw(50) << " " << "ATENCION DE PEDIDOS" << endl;
    imprimirLinea(arch, 120, '=');
    for(int i = 0; i < 5; i++){
        int *cliente = pedidosClientes[i];
        arch << "CLIENTE: " << cliente[0];
        arch << setw(20) << " " << "CANTIDAD PEDIDOS: " << cliente[1] << endl;
        imprimirLinea(arch, 120, '=');
        arch << setw(10) << " " << "Pedido No." << setw(5) << " " << "Codigo del Libro" << 
                setw(5) << " " << "Observacion" << endl;
        for(int j = 2; cliente[j]; j++){
            imprimirLinea(arch, 120, '-');
            arch << setw(10) << " " << right << setw(5) << cliente[j];
            imprimirPedido(arch, pedidosLibros[cliente[j]], pedidosAtendidos[cliente[j]]);
        }
        imprimirLinea(arch, 120, '=');
    }
}

void imprimirLinea(ofstream &arch, int n, char c){
    for(int i = 0; i < n; i++)
        arch.put(c);
    arch << endl;
}

void imprimirPedido(ofstream &arch, char **libros, bool *pedidos){
    arch << setw(15) << " " << left << setw(10) << libros[0];
    if(pedidos[0]) arch << setw(8) << " " << "ATENDIDO" << endl;
    else arch << setw(8) << " " << "NO ATENDIDO" << endl;
    for(int i = 1; libros[i]; i++){
        arch << setw(30) << " " << left << setw(10) << libros[i];
        if(pedidos[i]) arch << setw(8) << " " << "ATENDIDO" << endl;
        else arch << setw(8) << " " << "NO ATENDIDO" << endl;
    }
}