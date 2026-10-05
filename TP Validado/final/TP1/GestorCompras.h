#ifndef GESTORCOMPRAS_H_INCLUDED
#define GESTORCOMPRAS_H_INCLUDED
#include "Compras.h"
#include "Fecha.h"

class GestorCompras{
    private:
            Compras _compras;
    public:
        void cargarCompra(int id,int cant);
        void MostrarCompras();
};


#endif // GESTORCOMPRAS_H_INCLUDED
