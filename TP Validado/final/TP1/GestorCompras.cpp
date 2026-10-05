#include <iostream>
#include "GestorCompras.h"
#include <cstdio>
using namespace std;

void GestorCompras::cargarCompra(int id,int cant){
    _compras.DescontarProducto(id,cant);
}

void GestorCompras::MostrarCompras(){
    _compras.mostrarCompras();
}






