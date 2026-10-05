#include <iostream>
#include "rlutil.h"
#include "SubMenuProveedores.h"
using namespace std;


void SubMenuProveedores::SubMenuproveedores(){

    ShowItem obj;
    int x = 50;
    int y = 8;
    int a = 0;
    int opcion = 0;
    bool est = true;
    int xSelect= 55;
    rlutil::hidecursor();
    do{
        //rlutil::cls();
        int yTemp = y;
        rlutil::hidecursor();
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::locate(x, yTemp++); cout<<"-----------PROVEEDORES-----------"<<endl;
        obj.showItem(" CARGAR UN PROVEEDOR", xSelect, yTemp++, a==0);
        obj.showItem(" LISTAR LOS PROVEEDORES", xSelect, yTemp++, a==1);
        obj.showItem(" MOSTRAR LOS PRODUCTOS DE UN PROVEEDOR", xSelect, yTemp++, a==2);
        obj.showItem(" BUSCAR PROVEEDOR POR EL DNI", xSelect, yTemp++, a==3);
        obj.showItem(" VOLVER AL MENU ANTERIOR", xSelect, yTemp++, a==4);
        int key = rlutil::getkey();

        switch(key){
            case 14: // arriba
                rlutil::locate(xSelect - 2, 9 + a); cout <<"                                                                          "<<endl;
                a--;
                if(a < 0) a = 1;
                break;
            case 15: // abajo
                rlutil::locate(xSelect - 2, 9 + a); cout <<"                                                                              "<<endl;
                a++;
                if(a > 5) a = 5;
                break;
            case 1: // enter
                opcion = a + 1;
                rlutil::cls();
                switch(opcion){
                    case 1:
                        _GestorArchivosProveedor.CargarArchivo();
                        rlutil::anykey();
                        break;
                    case 2:
                        _GestorArchivosProveedor.mostrarArchivo();
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                    case 3:{
                        char DNI[10];
                        cout << "INGRESA EL DNI: ";
                        cin >> DNI;
                        _GestorArchivosProducto.mostrarProductosProveedores(DNI);
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                    }
                    case 4:{
                        char dni[10];
                        cout << "INGRESA EL DNI: ";
                        cin >> dni;
                        _GestorArchivosProveedor.mostrarDNIProveedor(dni);
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                    }
                    case 5:
                        est = false;
                        break;
                }
        }
    }while(est);
}


