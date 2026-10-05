
#include <iostream>
#include <cstring>
#include <limits>
#include <cctype>
#include "Producto.h"
#include "Utilidades.h"
#define byte rlutil_byte
#include "rlutil.h"
#undef byte
using namespace std;



Producto::Producto(){
    _id = 0;
    strcpy(_nombreProducto,"sin nombre");
    strcpy(_TipoProducto,"Sin tipoProducto");
    _PrecioUnitario = 0;
    _CantUnidades = 0;
    _estado = 0;
}
Producto::Producto(int id, const char * nombreProducto, const char* TipoProducto,const char * DniProveedor, float PrecioUnitario,int CantUnidades, bool estado ){
    _id = id;
    strcpy(_nombreProducto,nombreProducto);
    strcpy(_DniProveedor,DniProveedor);
    strcpy(_TipoProducto,TipoProducto);
    _PrecioUnitario = PrecioUnitario;
    _CantUnidades = CantUnidades;
    _estado = estado;
}


void Producto::setIdProducto(int id){
    _id=id;
}
void Producto::setDniProveedor(const char * DniProveedor){
    strcpy(_DniProveedor, DniProveedor);
}

void Producto::setNombreProducto(const char * nombreProducto){
    strcpy(_nombreProducto, nombreProducto);
}

void Producto::setTipoProducto(const char * TipoProducto){
    strcpy(_TipoProducto, TipoProducto);
}

void Producto::setPrecioUnitario(float precioUnitario){
    _PrecioUnitario= precioUnitario;
}
void Producto::setCantUnidades(float CantUnidades){
    _CantUnidades = CantUnidades;
}
void Producto::setEstado(bool estado){
    _estado=estado;
}
int Producto::GetId()const{
    return _id;
}
int Producto::GetCantUnidades()const{
    return _CantUnidades;
}

const char * Producto::GetnombreProducto()const{
    return _nombreProducto;
}
const char * Producto::GetDniProveedor()const{
    return _DniProveedor;
}
float Producto::GetPrecioUnitario()const{
    return _PrecioUnitario;
}

const char * Producto::GetTipoProducto()const{
    return _TipoProducto;
}

bool Producto::GetEstado()const{
    return _estado;
}

void Producto::cargar() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer al iniciar por seguridad

    // --- PROVEEDOR ---
    while (true) {
        cout << "Ingrese el DNI del proveedor: ";
        cin.getline(_DniProveedor, 50);

        if (strlen(_DniProveedor) == 0) {
            cout << "El dni no puede estar vacío.\n";
        }
        else {
            setDniProveedor(_DniProveedor);
            break;
        }
    }

    // --- ID DEL PRODUCTO ---
    while (true) {
        cout << "Ingrese ID del producto: ";
        cin >> _id;
        if (cin.fail() || _id <= 0) {
            cout << "ID invalido, Tiene que ser un entero mayor a 0.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            setIdProducto(_id);
            break;
        }
    }

// --- NOMBRE DEL PRODUCTO ---
while (true) {
    cout << "Ingrese el nombre del producto: ";
    cin.getline(_nombreProducto, 50);
    aMinusculas(_nombreProducto);

    if (!soloLetras(_nombreProducto))
        cout << "El nombre solo puede contener letras y espacios (no numeros).\n";
    else {
        setNombreProducto(_nombreProducto);
        break;
    }
}

// --- TIPO DE PRODUCTO ---
while (true) {
    cout << "Ingrese el tipo de producto: ";
    cin.getline(_TipoProducto, 50);
    aMinusculas(_TipoProducto);

    if (!soloLetras(_TipoProducto))
        cout << "El tipo de producto solo puede contener letras y espacios (no numeros).\n";
    else {
        setTipoProducto(_TipoProducto);
        break;
    }
}

    // --- PRECIO UNITARIO ---
    while (true) {
        cout << "Ingrese el precio unitario: ";
        cin >> _PrecioUnitario;
        if (cin.fail() || _PrecioUnitario <= 0) {
            cout << "Precio invalido. Debe ser un numero positivo.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            setPrecioUnitario(_PrecioUnitario);
            break;
        }
    }

    // --- CANTIDAD DE UNIDADES ---
    while (true) {
        cout << "Ingrese la cantidad de unidades: ";
        cin >> _CantUnidades;
        if (cin.fail() || _CantUnidades < 0) {
            cout << "Cantidad invalida. tiqne que ser un entero mayor a 0.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            setCantUnidades(_CantUnidades);
            break;
        }
    }

    // --- ESTADO ---
}


void Producto::mostrar(){

cout << "-----------------------------------------------------"<< endl;
cout <<"El Id del producto es : "<<GetId()<<endl;
cout <<"El DNI del proveedor es : "<<GetDniProveedor()<<endl;
cout <<"Nombre del producto : "<<GetnombreProducto()<<endl;
cout <<"Tipo de producto : "<<GetTipoProducto()<<endl;;
cout <<"Precio Unitario : "<<GetPrecioUnitario()<<endl;
cout <<"Cantidad de stock disponible : "<<GetCantUnidades()<<endl;
cout <<"el estado del producto es : "<<GetEstado()<<endl;

}

void Producto::mostrarCompra()const{
    cout<<"---------------------------" <<endl;
    cout<<"EL Id del producto es : "<<GetId()<<endl;
    cout<<"el Nombre del producto es : " <<GetnombreProducto()<<endl;
    cout<<"Del proveedor : "<< GetDniProveedor()<<endl;
}


