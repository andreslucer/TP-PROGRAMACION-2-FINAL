#ifndef GESTORPRODUCTOS_H_INCLUDED
#define GESTORPRODUCTOS_H_INCLUDED
#include "Producto.h"



class GestorProductos{
    private:
        Producto _Producto;
    public:
        void CargarProducto();
        void MostrarProducto();
        void cambiarEstado(int ,bool&);
        void cambiarPrecioProducto();
        void mostrarProductoyID();
        void ProductosActivos();


};

#endif // GESTORPRODUCTOS_H_INCLUDED
