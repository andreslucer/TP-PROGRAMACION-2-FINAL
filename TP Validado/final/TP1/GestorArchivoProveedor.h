#ifndef GESTORARCHIVOPROVEEDOR_H_INCLUDED
#define GESTORARCHIVOPROVEEDOR_H_INCLUDED
#include "GestorProveedor.h"
#include "GestorProductos.h"

class GestorArchivosProveedor{
    private:
        GestorProveedor _GestorProveedor;
    public:
        void CargarArchivo();
        void mostrarArchivo();
        void mostrarDNIProveedor(const char * );
};


#endif // GESTORARCHIVOPROVEEDOR_H_INCLUDED
