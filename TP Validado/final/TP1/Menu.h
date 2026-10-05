#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
/////////
#include "showitem.h"
#include "SubMenuCompras.h"
#include "SubMenuProductos.h"
#include "SubMenuProveedores.h"
#include "SubmenuReportes.h"

class Menu{
    private:
        ///////////////
        SubMenuCompras _SubMenuCompras;
        SubMenuProductos _SubMenuProductos;
        SubMenuProveedores _SubMenuProveedores;
        SubmenuReportes _SubMenuReportes;
    public:
        void menuPrincipal();
        void showItem(const char * , int , int,bool);
};


#endif // MENU_H_INCLUDED
