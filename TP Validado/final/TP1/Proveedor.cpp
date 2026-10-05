#include <iostream>
#include <cstring>
#include <string>
#include <limits>
#include <cctype>
#include "Proveedor.h"
#include "Utilidades.h"

using namespace std;

Proveedor::Proveedor(){
    strcpy(_dni,"0");
    strcpy(_cuit,"0");
    strcpy(_NombreProveedor,"sin nombre");
    strcpy(_numeroTelefono,"0");
    strcpy(_Gmail,"Sin gmail");
    strcpy(_Direccion,"Sin direccion");

}
Proveedor::Proveedor(const char * dni, const char * cuit, const char * NombreProveedor, const char * numeroTelefono, const char * Gmail, const char * Direccion){
    strcpy(_NombreProveedor,NombreProveedor);
    strcpy(_Gmail,Gmail);
    strcpy(_Direccion,Direccion);
    strcpy(_dni,dni);
    strcpy(_cuit,cuit);
    strcpy(_numeroTelefono,numeroTelefono);
}

void Proveedor::setDni(const char * dni ){
    strcpy(_dni,dni);
}
void Proveedor::setCuit(const char * cuit){
    strcpy(_cuit,cuit);
}
void Proveedor::setNombreProveedor(const char * NombreProveedor){
    strcpy(_NombreProveedor,NombreProveedor);
}
void Proveedor::setNumeroTelefono(const char * numeroTelefono){
    strcpy(_numeroTelefono,numeroTelefono);
}
void Proveedor::setGmail(const char * Gmail){
    strcpy(_Gmail,Gmail);
}

void Proveedor::setDireccion(const char * Direccion){
    strcpy(_Direccion,Direccion);
}



const char * Proveedor::GetDNI(){
    return _dni;
}
const char * Proveedor::GetCuit(){
    return _cuit;
}
const char * Proveedor::GetNumeroTelefono(){
    return _numeroTelefono;
}
const char * Proveedor::GetnombreProveedor(){
    return _NombreProveedor;
}
const char * Proveedor::GetGmail(){
    return _Gmail;
}
const char * Proveedor::GetDireccion(){
    return _Direccion;
}

void Proveedor::cargar() {
    char buffer[50];

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (true) {
        cout << "Ingrese el DNI: ";
        cin.getline(buffer, 50);

        if (!soloNumeros(buffer))
            cout << "DNI invalido. Solo se permiten numeros.\n";
        else {
            strcpy(_dni, buffer);
            setDni(_dni);
            break;
        }
    }
    while (true) {
        cout << "Ingrese el CUIT: ";
        cin.getline(buffer, 50);

        if (!soloNumeros(buffer))
            cout << "CUIT invalido. Solo se permiten numeros.\n";
        else {
            strcpy(_cuit, buffer);
            setCuit(_cuit);
            break;
        }
    }
    while (true) {
        cout << "Ingrese el nombre del proveedor: ";
        cin.getline(_NombreProveedor, 50);

        if (strlen(_NombreProveedor) == 0)
            cout << "El nombre no puede estar vacio.\n";
        else if (!isalpha(_NombreProveedor[0]))
            cout << "El nombre debe comenzar con una letra.\n";
        else {
            setNombreProveedor(_NombreProveedor);
            break;
        }
    }

    while (true) {
        cout << "Ingrese el numero de telefono: ";
        cin.getline(buffer, 50);

        if (!soloNumeros(buffer))
            cout << "Telefono invalido. Solo se permiten numeros.\n";
        else {
            strcpy(_numeroTelefono, buffer);
            break;
        }
    }
    while (true) {
        cout << "Ingrese el Gmail: ";
        cin.getline(_Gmail, 50);

        if (strlen(_Gmail) == 0)
            cout << "El Gmail no puede estar vacio.\n";
        else if (strchr(_Gmail, '@') == nullptr || strchr(_Gmail, '.') == nullptr)
            cout << "Gmail invalido. Debe contener '@' y un dominio (por ejemplo: .com).\n";
        else {
            setGmail(_Gmail);
            break;
        }
    }

    while (true) {
        cout << "Ingrese la direccion: ";
        cin.getline(_Direccion, 50);

        if (strlen(_Direccion) == 0)
            cout << "La direccion no puede estar vacia.\n";
        else {
            setDireccion(_Direccion);
            break;
        }
    }
}



void Proveedor::mostrar(){

cout<<"----------------------------"<<endl;
cout<<"DNI : "<<GetDNI()<<endl;
cout<<"CUIT : "<<GetCuit()<<endl;
cout<<"NOMBRE : "<<GetnombreProveedor()<<endl;
cout<<"TELEFONO : "<<GetNumeroTelefono()<<endl;
cout<<"GMAIL : "<<GetGmail()<<endl;
cout<<"DIRECCION : "<<GetDireccion()<<endl;
cout<<"----------------------------"<<endl;
}




