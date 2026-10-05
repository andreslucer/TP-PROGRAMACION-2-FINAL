#include <iostream>
#include "SubMenuCompras.h"
#include "rlutil.h"
#include "Validaciones.cpp"
#include "Validaciones.h"

using namespace std;


void SubMenuCompras::menu(){

    ShowItem obj;

    int x = 55, y = 8, a = 0;
    int opcion = 0;
    bool estado = true;
    int xSelect= 55;
    do {
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        //rlutil::cls();
        int yTemp= y;
        rlutil::hidecursor();
        rlutil::locate(x, yTemp++); cout << "----COMPRAS---- " << endl;
        obj.showItem(" CARGAR COMPRAS", xSelect, yTemp++, a==0);
        obj.showItem(" MOSTRAR COMPRAS", xSelect, yTemp++, a==1);
        obj.showItem(" VOLVER ATRAS", xSelect, yTemp++, a==2);
        int key = rlutil::getkey();
        switch(key){
            case 14:
                rlutil::locate(xSelect - 2, 9 + a); cout <<"                                                                                                  "<<endl;
                a--;
                if(a < 0) a = 2;
                break;
            case 15:
            rlutil::locate(xSelect - 2, 9 + a ); cout <<"                                                                                                   "<<endl;
                a++;
                if(a > 2) a = 0;
                break;
            case 1:
                opcion = a + 1;
                rlutil::cls();

        switch(opcion){
case 1: {
    cout << "LOS PRODUCTOS DISPONIBLES SON LOS SIGUIENTES" << endl;
    _GestorProductos.ProductosActivos();

    int id, cantidad;
    bool seguir = true;

    while(seguir){
        cout << "Ingrese el ID del producto: ";
        id = pedirEntero();

        cout << "Ingrese la cantidad a comprar: ";
        cantidad = pedirEntero();

        _GestorCompras.cargarCompra(id, cantidad);

        cout << "Agregar otro producto? (1 SI / 0 NO): ";
        int opc = pedirEntero();

        if(opc == 0) seguir = false;
    }

    break;
}

            case 2:
                _GestorCompras.MostrarCompras();
                rlutil::anykey();
                rlutil::cls();
                break;
            case 3 :
                estado = false;
                break;
            }

        }

    } while(estado);
}

