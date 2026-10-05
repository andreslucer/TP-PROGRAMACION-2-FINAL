#include <iostream>
#include "Menu.h"
#include <cstring>
#include <string>
#include "rlutil.h"

using namespace std;

ShowItem obj;




void Menu::menuPrincipal() {
    char tipo[20];
    bool est;
    int idProducto, cont;
    int opcion = 0;
    int x = 40;
    int y =8;
    int a = 1;
    int xSelect= 55;
// esconde el cursor
    do {
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        //rlutil::cls();
        int yTemp = y;
        rlutil::hidecursor();
        rlutil::locate(x, yTemp++); cout<<"             Bienvenido al Kiosco Los Loleros!         "<<endl;
        rlutil::locate(x, yTemp++); cout<<"                -------------------"<<endl;
        obj.showItem(" COMPRAS", xSelect, yTemp++, a==1);
        obj.showItem(" PRODUCTOS", xSelect, yTemp++, a==2);
        obj.showItem(" PROVEEDORES", xSelect, yTemp++, a==3);
        obj.showItem(" REPORTES", xSelect, yTemp++, a==4);
        obj.showItem(" SALIR DEL PROGRAMA", xSelect, yTemp++, a==5);


        //rlutil::locate(xSelect - 2, 9 + a); cout << (char)175; ya puedo quitar el cursor

        int key = rlutil::getkey();

        switch (key) {
            case 14: //FLECHA ARRIBA
                rlutil::locate(xSelect - 2, 9 + a); cout <<"                                                    "<<endl;// para limpiar el cursor
                 a--;
                if (a < 1) a = 5;
                break;
            case 15: // FLECHA ABAJO
                rlutil::locate(xSelect - 2, 9 + a); cout <<"                                                     "<<endl;
                 a++;
                 if (a > 5) a = 1;
                break;
            case 1:
                opcion = a;
                rlutil::cls();

                switch (opcion) {
                    case 1:
                        _SubMenuCompras.menu();
                        break;

                    case 2:
                        _SubMenuProductos.SubMenuPro();
                        break;
                    case 3:
                        _SubMenuProveedores.SubMenuproveedores();
                        break;
                    case 4:
                        _SubMenuReportes.SubMenuRepor();
                        break;
                    case 5:
                        exit(1);
                        break;

                }
                break;
        }

    } while (true);
}



