#ifndef SUBMENUCOMPRAS_H_INCLUDED
#define SUBMENUCOMPRAS_H_INCLUDED
#include "showitem.h"
#include "GestorCompras.h"

class SubMenuCompras{
    private:
        GestorCompras _GestorCompras;
        GestorProductos _GestorProductos;

    public:
        void menu();

};



#endif // SUBMENUCOMPRAS_H_INCLUDED

