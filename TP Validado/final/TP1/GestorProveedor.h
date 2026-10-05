#ifndef GESTORPROVEEDOR_H_INCLUDED
#define GESTORPROVEEDOR_H_INCLUDED
#include "Proveedor.h"

class GestorProveedor{
    private:
        Proveedor _Proveedor;
    public:
        void cargar();
        void mostrar();
};



#endif // GESTORPROVEEDOR_H_INCLUDED
