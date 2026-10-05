#include <iostream>
#include "GestorProductos.h"
#include <cstdio>
#include <limits>

#include "rlutil.h"
using namespace std;


void GestorProductos::CargarProducto(){
    _Producto.cargar();
}

void GestorProductos::MostrarProducto(){
    _Producto.mostrar();
}



void GestorProductos::cambiarEstado(int id, bool &est){
    FILE * p = fopen("ArchivoProducto","rb+");
    if(p == NULL){
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }

    Producto obj;
    bool encontrado = false;
    while(fread(&obj, sizeof(Producto), 1, p) == 1){
        if(obj.GetId() == id){
            encontrado = true;
            if(obj.GetEstado() == est){
                if(est == false){
                    cout << "El producto con ID " << id << " ya se encuentra inactivo." << endl;
                } else {
                    cout << "El producto con ID " << id << " ya se encuentra activo." << endl;
                }
            } else {
                // Mover el puntero atrás un registro
                fseek(p, -static_cast<long>(sizeof(Producto)), SEEK_CUR);
                obj.setEstado(est);
                fwrite(&obj, sizeof(Producto), 1, p);
                if(est == false){
                    cout << "El producto con ID " << id << " se cambio a inactivo." << endl;
                } else {
                    cout << "El producto con ID " << id << " se cambio a activo." << endl;
                }
            }
            break;
        }
    }

    if(!encontrado){
        cout << "No se encontró un producto con ID " << id << endl;
    }

    fclose(p);
}


void GestorProductos::cambiarPrecioProducto() {
    FILE *p;
    Producto obj;
    p = fopen("ArchivoProducto", "rb+");
    if (p == NULL) {
        cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
        exit(1);
    }

    int id;
    float precio;

    // --- Validación del ID ---
    while (true) {
        cout << "INGRESE EL ID DEL PRODUCTO A CAMBIAR EL PRECIO: ";
        cin >> id;
        if (cin.fail()) {
            cin.clear(); // limpia estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // descarta buffer
            cout << "Error: Debe ingresar un numero valido.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    // --- Validación del precio ---
    while (true) {
        cout << "INGRESE EL PRECIO A CAMBIAR: ";
        cin >> precio;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Debe ingresar un numero valido.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    int bandera = 0;
    while (fread(&obj, sizeof(Producto), 1, p) == 1) {
        if (obj.GetId() == id) {
            obj.setPrecioUnitario(precio);
            fseek(p, -static_cast<long>(sizeof(Producto)), SEEK_CUR);
            fwrite(&obj, sizeof(Producto), 1, p);
            cout << "Precio cambiado correctamente" << endl;
            rlutil::anykey();
            bandera = 1;
            break;
        }
    }

    if (bandera == 0) {
        cout << "No se encontro el ID" << endl;
        rlutil::anykey();
    }

    rlutil::cls();
    fclose(p);
}


void GestorProductos::mostrarProductoyID(){
    Producto obj;
    FILE *p;
    p = fopen("ArchivoProducto","rb");
    if(p==NULL){
        cout<<"no se pudo abrir el archivo"<<endl;
        exit(1);
    }
    while(fread(&obj,sizeof(Producto),1,p)==1){
        cout<<"ID del producto : "<<obj.GetId()<<endl;
        cout<<"NOMBRE DEL PRODUCTO : "<<obj.GetnombreProducto()<<endl;
        cout<<"STOCK DISPONIBLE : "<<obj.GetCantUnidades()<<endl;
        cout<<"ESTADO  : " <<obj.GetEstado()<<endl;
        cout<<"PRECIO : " <<obj.GetPrecioUnitario()<<endl;
        cout<<"-------------------"<<endl;
    }
    fclose(p);
    return;
}

void GestorProductos::ProductosActivos(){
    Producto obj;
    FILE *p;
    p = fopen("ArchivoProducto","rb");
    if(p==NULL){
        cout<<"no se pudo abrir el archivo"<<endl;
        exit(1);
    }
    while(fread(&obj,sizeof(Producto),1,p)==1){
            if(obj.GetEstado()==true){
            cout<<"ID del producto : "<<obj.GetId()<<endl;
            cout<<"NOMBRE DEL PRODUCTO : "<<obj.GetnombreProducto()<<endl;
            cout<<"STOCK DISPONIBLE : "<<obj.GetCantUnidades()<<endl;
            cout<<"ESTADO  : " <<obj.GetEstado()<<endl;
            cout<<"PRECIO : " <<obj.GetPrecioUnitario()<<endl;
            cout<<"-------------------"<<endl;
            }

    }
    fclose(p);
    return;
}


