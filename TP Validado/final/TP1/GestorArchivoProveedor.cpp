#include <iostream>
#include <cstdio>
#include <cstring>
#include "GestorArchivoProveedor.h"
#include "rlutil.h"
using namespace std;


void GestorArchivosProveedor::CargarArchivo() {
    Proveedor obj, aux;
    obj.cargar();
    FILE* p = fopen("ArchivoProveedor", "rb");
    if (p != NULL) {
        while (fread(&aux, sizeof(Proveedor), 1, p) == 1) {
            if (strcmp(aux.GetDNI(), obj.GetDNI()) == 0) {
                cout << "ya existe un proveedor con ese dni." << endl;
                fclose(p);
                return;
            }
        }
        fclose(p);
    }

    p = fopen("ArchivoProveedor", "ab");
    if (p == NULL) {
        cout << " No se pudo abrir el archivo para escribir." << endl;
        return;
    }

     bool  a = (fwrite(&obj, sizeof(Proveedor), 1, p) == 1);
     if(a){
        cout << " Proveedor cargado correctamente." << endl;
    } else {
        cout << " Error al guardar el proveedor." << endl;
    }

    fclose(p);
}


void GestorArchivosProveedor::mostrarArchivo(){
    FILE * p;
    Proveedor obj;
    p = fopen("ArchivoProveedor", "rb");
    if(p==NULL){
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }
    cout<<"-----------PROVEEDORES-----------"<<endl;
    while(fread(&obj,sizeof(Proveedor),1,p)==1){
    obj.mostrar();
    }
    fclose(p);
}

void GestorArchivosProveedor::mostrarDNIProveedor(const char * nombre){
    FILE *p;
    Proveedor obj;
    bool encontrado = false;
    p = fopen("ArchivoProveedor", "rb");
    if(p == NULL){
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    while(fread(&obj, sizeof(Proveedor), 1, p) == 1){
        if(strcmp(obj.GetDNI(), nombre) == 0){
            cout << "PROVEEDOR" << endl;
            obj.mostrar();
            encontrado = true;
            break;
        }
    }
    if(!encontrado){
        cout << "No existe tal proveedor" << endl;
    }
    fclose(p);
}

