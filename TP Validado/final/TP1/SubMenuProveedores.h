#ifndef SUBMENUPROVEEDORES_H_INCLUDED
#define SUBMENUPROVEEDORES_H_INCLUDED
#include "showitem.h"
#include "GestorArchivoProveedor.h"
#include "GestorArchivoProductos.h"

class SubMenuProveedores{
    private:
        GestorArchivosProveedor _GestorArchivosProveedor;
        GestorArchivosProductos _GestorArchivosProducto;
    public:
        void SubMenuproveedores();
};


#endif // SUBMENUPROVEEDORES_H_INCLUDED
