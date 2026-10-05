#ifndef SUBMENUPRODUCTOS_H_INCLUDED
#define SUBMENUPRODUCTOS_H_INCLUDED
#include "showitem.h"
#include "GestorArchivoProductos.h"
#include "GestorProductos.h"

class SubMenuProductos{
    private:
            GestorArchivosProductos _GestorArchivosProductos;
            GestorProductos _GestorProductos;
    public:
        void SubMenuPro();

};

#endif // SUBMENUPRODUCTOS_H_INCLUDED
