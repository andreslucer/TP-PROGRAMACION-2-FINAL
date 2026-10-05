#include "rlutil.h"
#include <iostream>
#include "SubMenuProductos.h"
#include <limits>
using namespace std;

void SubMenuProductos::SubMenuPro(){
    ShowItem bj;

    int xSelect = 55;
    int y = 8;
    int a = 0;
    int opcion = 0;
    bool est = true;
    rlutil::hidecursor();
    do {


        int yTemp = y; // esto si o si es necesario por que siempre tiene que partir del 2 inicial si no se mueve todo
        rlutil::locate(xSelect, yTemp++);cout<<"------------PRODUCTOS------------"<<endl;
        bj.showItem(" LISTAR LOS PRODUCTOS", xSelect, yTemp++, a==0);
        bj.showItem(" CARGAR UN PRODUCTO", xSelect, yTemp++, a==1);
        bj.showItem(" MOSTRAR LAS CATEGORIAS", xSelect, yTemp++, a==2);
        bj.showItem(" CAMBIAR EL ESTADO DEL PRODUCTO", xSelect, yTemp++, a==3);
        bj.showItem(" MOSTRAR EL PRODUCTO POR EL ID", xSelect, yTemp++, a==4);
        bj.showItem(" MOSTRAR LAS CATEGORIAS DE LOS PRODUCTOS", xSelect, yTemp++, a==5);
        bj.showItem(" RECARGAR STOCK DE PRODUCTO POR ID", xSelect, yTemp++, a==6);
        bj.showItem(" CAMBIAR PRECIO DE PRODUCTO", xSelect, yTemp++, a==7);
        bj.showItem(" VOLVER AL MENU ANTERIOR", xSelect, yTemp++, a==8);
        int key = rlutil::getkey();
        switch(key){
            case 14:
            rlutil::locate(xSelect - 2, 9 + a); cout <<"                                                                                                  "<<endl;
            a--;
            if (a<0) a = 8;
            break;
            case 15:
            rlutil::locate(xSelect - 2, 9 + a); cout <<"                                                                                                  "<<endl;
            a++;
            if(a > 8) a = 0;
            break;
            case 1:
                opcion = a + 1;
                rlutil::cls();
                switch(opcion){
                    case 1:
                        _GestorArchivosProductos.mostrarDadosDeAlta();
                        break;
                    case 2:
                        _GestorArchivosProductos.cargarArchivo();
                        break;
                    case 3:
                        _GestorArchivosProductos.mostrarCategorias();
                        rlutil::anykey();
                        break;
                    case 4:
                        int id;
                        bool es;
                        _GestorProductos.mostrarProductoyID();
                        cout<<"ingresa el id del producto a cambiar estado"<<endl;
                        cin>>id;
                        cout<<"ingresa el estado a cambiar"<<endl;
                        cin>>es;
                       _GestorProductos.cambiarEstado(id,es);
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                        case 5: {
                            int id;
                            while (true) {
                                cout << "Ingrese el ID a mostrar: ";
                                cin >> id;

                                if (cin.fail()) { // si ingreso algo que no es nmero
                                    cin.clear(); // limpia el estado de error de cin
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // descarta el buffer
                                    cout << "Error: debe ingresar un numero valido.\n";
                                } else {
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpia resto del buffer
                                    break; // entrada valida, salimos del while
                                }
                            }

                            _GestorArchivosProductos.mostrarPorId(id);
                            rlutil::anykey();
                            break;
                        }

                    case 6:
                        char tipo[20];
                        cout<<"ingrese el tipo de categoria que desea ver los productos"<<endl;
                        cin>>tipo;
                        _GestorArchivosProductos.mostrarPorTipo(tipo);
                        rlutil::anykey();
                        break;
                    case 7:
                        _GestorProductos.mostrarProductoyID();
                        _GestorArchivosProductos.RecargarStock();
                        rlutil::anykey();
                        break;
                    case 8:
                        _GestorProductos.mostrarProductoyID();
                        _GestorProductos.cambiarPrecioProducto();
                        break;
                    case 9:
                        est = false;
                        break;



                }
        }


    }while(est);
}
