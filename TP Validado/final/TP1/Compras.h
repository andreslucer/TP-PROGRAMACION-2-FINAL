#ifndef COMPRAS_H_INCLUDED
#define COMPRAS_H_INCLUDED
#include "Fecha.h"
#include "GestorArchivoProductos.h"
#include "Producto.h"

class Compras {
private:
    Fecha _Fecha;
    Producto _Producto;
    int _cantidadComprada;
    float _precioTotalCompra;
    int _idCompra;

public:
    Fecha getFecha() const;
    Producto getProducto()const;
    void DescontarProducto(int idBuscado, int cantidadDescontar);
    void setCantidadComprada(int c);
    void setPrecioTotalCompra(float p);
    void setIdCompra(int id);
    int getCantidadComprada() const;
    int getIdCompra()const;
    int generarIdCompra();
    float getPrecioTotalCompra() const;
    void mostrarCompras() const;
};



#endif // COMPRAS_H_INCLUDED
