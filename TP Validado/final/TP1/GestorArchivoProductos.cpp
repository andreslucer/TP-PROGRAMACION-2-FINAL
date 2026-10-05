#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include "GestorArchivoProductos.h"
#include "rlutil.h"
using namespace std;

void GestorArchivosProductos::cargarArchivo() {
    Producto obj, aux;
    Proveedor ax;
    int desicion;
    bool estado = true;
    FILE *p;  // declarar una sola vez acá

    do {
        obj.cargar(); // carga el producto en memoria

        FILE *f = fopen("ArchivoProveedor", "rb");
        if (f == NULL) {
            cout << "No se pudo abrir el archivo de proveedores." << endl;
            return;
        }

        int BanderaProveedorExiste = 0;
        while (fread(&ax, sizeof(Proveedor), 1, f) == 1) {
            if (strcmp(obj.GetDniProveedor(), ax.GetDNI()) == 0) {
                BanderaProveedorExiste = 1;
                break;
            }
        }
        fclose(f);

        if (BanderaProveedorExiste == 0) {
            cout << "El proveedor no existe, cargue primero el proveedor." << endl;
            rlutil::anykey();
            return;
        }

        p = fopen("ArchivoProducto", "ab");
        if (p != NULL) {
            while (fread(&aux, sizeof(Producto), 1, p) == 1) {
                if (aux.GetId() == obj.GetId()) {
                    cout << "Error: ya existe un producto con el ID "
                         << obj.GetId() << "." << endl;
                    rlutil::anykey();
                    fclose(p);
                    return;
                }
            }
            fclose(p);
        }

        obj.setEstado(true);

        cout << "ESTE ES EL PRODUCTO QUE QUERES CARGAR?" << endl;
        obj.mostrar();   // corregido
        cout << "1 para s1, 2 para cargar de nuevo: ";
        cin >> desicion;

        if (desicion == 1) {
            estado = false;
        } else {
            rlutil::cls();
        }

    } while (estado);  // ← falta el ; en tu versión

    p = fopen("ArchivoProducto", "ab");
    if (p == NULL) {
        cout << "No se pudo abrir el archivo para escribir." << endl;
        rlutil::anykey();
        return;
    }

    fwrite(&obj, sizeof(Producto), 1, p);
    fclose(p);

    cout << "Producto cargado correctamente." << endl;
    rlutil::anykey();
}








void GestorArchivosProductos::mostrarArchivo(){
    FILE * p;
    Producto obj;
    p = fopen("ArchivoProducto", "rb");
    if(p==NULL){
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }

    while(fread(&obj,sizeof(Producto),1,p)==1){
    obj.mostrar();
    }
    fclose(p);
}


void GestorArchivosProductos::mostrarDadosDeAlta(){
    FILE * p;
    Producto obj;
    ShowItem ob;
    p=fopen("ArchivoProducto","rb");
    if(p==NULL){
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }
    cin.clear();
    int x = 55;
    int y =8;
    int a = 0;
    int xSelect= 60;
    int opcion = 0;
    bool est = true;
    do {
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::hidecursor();
        int yTemp = y;
        rlutil::locate(x, yTemp++); cout << "----QUE PRODUCTOS QUERES VER---- " << endl;
        ob.showItem("ACTIVOS",xSelect, yTemp++,a==0);
        ob.showItem("INACTIVOS",xSelect, yTemp++,a==1);
        ob.showItem("ATRAS",xSelect,yTemp++,a==2);
        int key = rlutil::getkey();
        switch(key){
            case 14:
                rlutil::locate(xSelect - 2, 9 + a); cout <<"                                                                                                  "<<endl;
                a--;
                if(a<0) a = 2;
                break;
            case 15:
                rlutil::locate(xSelect - 2, 9 + a); cout <<"                                                                                                  "<<endl;
                a++;
                if(a>2) a = 0;
                break;
            case 1:
                opcion = a + 1 ;
                rlutil::cls();
                switch(opcion){
                case 1:{
                    int cont = 0;
                    rewind(p);
                    int x = 50;
                    rlutil::locate(x-1,7);cout<<"--PRODUCTOS ACTIVOS--"<<endl;
                    while(fread(&obj,sizeof(Producto),1,p)==1){
                    if(obj.GetEstado()== true){
                     obj.mostrar();
                     cont++;
                        }
                    }
                    if(cont==0){
                        cout<<"no hay productos activos"<<endl;
                    }
                    rlutil::anykey();
                    est = false;
                    break;
                }
                case 2:{
                    rewind(p);
                    int x = 50;
                    int conta= 0;
                    rlutil::locate(x-1,7); cout<<"--PRODUCTOS INACTIVOS--"<<endl;
                    while(fread(&obj,sizeof(Producto),1,p)==1){
                    if(obj.GetEstado()== false){
                            conta++;
                    obj.mostrar();
                        }
                    }
                    if(conta==0){
                        cout<<"No hay productos inactivos"<<endl;
                    }
                    rlutil::anykey();
                    est = false;
                    break;
                }
                case 3:
                    est = false;
                    break;

            }
        }

    }while(est);
    fclose(p);
}


void GestorArchivosProductos::mostrarPorId(int id){
    Producto obj;
    FILE * p;
    p=fopen("ArchivoProducto","rb");
    if(p==NULL){
        cout<<"no se pudo abrir el archivo"<<endl;
        exit(1);
    }
    while(fread(&obj,sizeof(Producto),1,p)==1){
        if(obj.GetId()==id){
            obj.mostrar();
        }
    }
    fclose(p);
}

void GestorArchivosProductos::mostrarPorTipo(const char * tipo){
    Producto obj;
    FILE * p;
    p =fopen("ArchivoProducto","rb");
    if(p==NULL){
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }
    int cont = 0;
    while(fread(&obj,sizeof(Producto),1,p)==1){
        if(strcmp(obj.GetTipoProducto(),tipo)==0){
                if(obj.GetEstado()==true) obj.mostrar();
                cont++;
        }
    }
    if(cont==0){
        cout<<"no hay productos de dicha categoria"<<endl;
    }
    fclose(p);
}

void GestorArchivosProductos::mostrarProductosProveedores(const char * tipo){
    FILE *p;
    Producto obj;
    p = fopen("ArchivoProducto","rb");
    if(p==NULL){
        cout<<"no se pudo abrir el archivo"<<endl;
        exit(1);
    }
     bool bandera = 0;
    cout<<"---------PRODUCTOS DEL PROVEEDOR---------"<<endl;
    while(fread(&obj,sizeof(Producto),1,p)==1){
        if(strcmp(obj.GetDniProveedor(),tipo)==0){
            bandera = 1;

            obj.mostrar();
        }
    }
    if(bandera==0){
        cout<<"No existe tal proveedor"<<endl;
    }
    fclose(p);
}
// VER BIEN QUE HACE
void GestorArchivosProductos::mostrarCategorias() {
    Producto obj;
    FILE *p = fopen("ArchivoProducto", "rb");
    if (p == NULL) {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    vector<string> categorias;
    cout << "LAS CATEGORIAS DE LOS PRODUCTOS" << endl;

    while (fread(&obj, sizeof(Producto), 1, p) == 1) {
        const char *tipo = obj.GetTipoProducto();
        bool repetido = false;

        for (const string & cat : categorias) {
            if (cat == tipo) {
                repetido = true;
                break;
            }
        }

        if (!repetido) {
            categorias.push_back(tipo);
            cout << "CATEGORIA: " << tipo << endl;
        }
    }

    fclose(p);
}
//  HASTA ACA!
void GestorArchivosProductos::RecargarStock(){
    Producto aux;
    int nuevoID, stock;
    cout << "Ingrese el id y el stock a sumar: ";
    cin >> nuevoID >> stock;

    FILE *p = fopen("ArchivoProducto", "rb+");
    if (p == NULL) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    bool encontrado = false;

    while (fread(&aux, sizeof(Producto), 1, p) == 1) {
        if (aux.GetId() == nuevoID) {
            encontrado = true;
            aux.setCantUnidades(aux.GetCantUnidades() + stock);
            if (!aux.GetEstado()) aux.setEstado(true);

            fseek(p, -static_cast<long>(sizeof(Producto)), SEEK_CUR);
            fwrite(&aux, sizeof(Producto), 1, p);
            cout << "Stock actualizado correctamente." << endl;
            break;
        }
    }

    if (!encontrado)
        cout << "No se encontró el producto con ese ID." << endl;

    fclose(p);
}





