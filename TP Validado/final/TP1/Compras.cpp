#include <iostream>
#include <cstdio>
#include "Compras.h"
#include <map>
#include <string>
#include "rlutil.h"
using namespace std;

int Compras::generarIdCompra() {
    FILE *f = fopen("compras", "rb");
    if (f == NULL) return 1;

    Compras reg;
    int ultimoId = 0;

    while (fread(&reg, sizeof(Compras), 1, f) == 1) {
        if (reg.getIdCompra() > ultimoId) {
            ultimoId = reg.getIdCompra();
        }
    }

    fclose(f);
    return ultimoId + 1;
}


void Compras::DescontarProducto(int idBuscado, int cantidadDescontar) {

    Compras listaCompras[50];   // Máximo 50 productos por compra
    int cantItems = 0;
    bool seguir = true;

    while (seguir) {

        FILE *p = fopen("ArchivoProducto", "rb+");
        if (p == NULL) {
            cout << "No se pudo abrir el archivo de productos" << endl;
            exit(1);
        }

        Producto reg;
        bool encontrado = false;

        while (fread(&reg, sizeof(Producto), 1, p) == 1) {
            if (reg.GetId() == idBuscado) {
                encontrado = true;
                int stock = reg.GetCantUnidades();

                if (stock >= cantidadDescontar) {

                    // Descuento el stock
                    reg.setCantUnidades(stock - cantidadDescontar);
                    if (reg.GetCantUnidades() == 0) {
                        reg.setEstado(false);
                    }

                    fseek(p, -static_cast<long>(sizeof(Producto)), SEEK_CUR);
                    fwrite(&reg, sizeof(Producto), 1, p);

                    cout << "Se descontaron " << cantidadDescontar << " unidades." << endl;

                    // *** NO REGISTRAMOS LA COMPRA YA ***
                    // Guardamos la compra en memoria:
                    listaCompras[cantItems]._Producto = reg;
                    listaCompras[cantItems].setCantidadComprada(cantidadDescontar);
                    listaCompras[cantItems].setPrecioTotalCompra(reg.GetPrecioUnitario() * cantidadDescontar);
                    cantItems++;

                } else {
                    cout << "Stock insuficiente" << endl;
                }
                break;
            }
        }

        if (!encontrado) {
            cout << "Producto con ID " << idBuscado << " no encontrado." << endl;
        }

        fclose(p);

        cout << "Agregar otro producto? (1 SI / 0 NO): ";
        cin >> seguir;

        if (seguir) {
            cout << "ID del producto: ";
            cin >> idBuscado;
            cout << "Cantidad a descontar: ";
            cin >> cantidadDescontar;
        }
    }

    Fecha fechaFinal;
    fechaFinal.cargar();
    FILE *comprasFile = fopen("compras", "ab");
    if (comprasFile == NULL) {
        cout << "No se pudo abrir el archivo de compras" << endl;
        return;
    }
    int idCompra = generarIdCompra();
    for (int i = 0; i < cantItems; i++) {
        listaCompras[i]._Fecha = fechaFinal;
        listaCompras[i].setIdCompra(idCompra);
        fwrite(&listaCompras[i], sizeof(Compras), 1, comprasFile);
    }

    fclose(comprasFile);

    cout << "Se registro la compra completa con " << cantItems << " productos." << endl;
    rlutil::getkey();
    rlutil::cls();
}


void Compras::setCantidadComprada(int c) {
    _cantidadComprada = c;
}

void Compras::setPrecioTotalCompra(float p) {
    _precioTotalCompra = p;
}
void Compras::setIdCompra(int id){
    _idCompra = id;
}
int Compras::getCantidadComprada() const {
    return _cantidadComprada;
}

float Compras::getPrecioTotalCompra() const {
    return _precioTotalCompra;
}

int Compras::getIdCompra() const {
    return _idCompra;
}

void Compras::mostrarCompras() const {
    int x = 40;
    int y = 2;
    FILE *p = fopen("compras", "rb");
    if (p == NULL) {
        cout << "No se pudo abrir el archivo de compras." <<endl;
        return;
    }
    Compras reg;
    int contador = 0;
    rlutil::cls();
    cout<<"---------COMPRAS---------"<<endl;
    while (fread(&reg, sizeof(Compras), 1, p) == 1) {

        reg._Producto.mostrarCompra();
        reg._Fecha.mostrarFecha();
        cout<<"Cantidad comprada: " << reg._cantidadComprada <<endl;
        cout<<"Precio total: $" << reg._precioTotalCompra<<endl;
        cout<<"id de compra es "<<reg._idCompra<<endl;
        cout<<"---------------------------" <<endl;
        contador++;
    }
    if (contador == 0) {
        cout << "No hay compras registradas." <<endl;
    }
    fclose(p);
}

Fecha Compras::getFecha()const{
    return _Fecha;
}
Producto Compras::getProducto()const{
    return _Producto;
}


