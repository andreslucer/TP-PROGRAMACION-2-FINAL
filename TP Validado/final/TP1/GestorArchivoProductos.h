#ifndef GESTORARCHIVO_H_INCLUDED
#define GESTORARCHIVO_H_INCLUDED
#include "showitem.h"
#include "Proveedor.h"
#include "GestorProductos.h"

class GestorArchivosProductos{
    private:
        GestorProductos _Producto;
        ShowItem _ShowItem;

    public:
        // CargarArchivo
        void cargarArchivo();
        void mostrarArchivo();
        void mostrarPorId(int);
        void mostrarPorTipo(const char *);
        void mostrarProductosProveedores(const char *);
        void RecargarStock();
        void mostrarCategorias();
        void mostrarDadosDeAlta();
};

#endif // GESTORARCHIVO_H_INCLUDED
