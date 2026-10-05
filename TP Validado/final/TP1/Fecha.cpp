#include <iostream>
#include <cstring>
#include <string>
#include "Fecha.h"
using namespace std;


Fecha::Fecha(){
    _dia = 0;
    _mes = 0;
    _anio = 0;
}

Fecha::Fecha(int dia, int mes,int anio){
    _dia = dia;
    _mes = mes;
    _anio = anio;

}

void Fecha::setDia(int dia){
    _dia = dia;

}
void Fecha::setMes(int mes){
    _mes = mes;

}
void Fecha::setAnio(int anio){
    _anio = anio;

}

int Fecha::getDia()const{
    return _dia;
}
int Fecha::getMes()const{
    return _mes;
}
int Fecha::getAnio()const{
    return _anio;
}

void Fecha::cargar(){
      int dia, mes, anio;
        cout << "Ingrese el dia: ";
        cin >> dia;
        while(cin.fail()|| dia < 0 || dia > 31 ){
        cout << "Entrada invalida. Ingrese un numero entero para el dia: ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> dia;
    }
      cout<<"ingrese el mes: ";
      cin>>mes;
      while(cin.fail() || mes <=0 || mes > 12){
        cout<<"Entrada invalida. Ingrese un numero entero para el mes o un mes del 1 al 12"<<endl;
        cin.clear();
        cin.ignore(10000,'\n'); cin>>mes;
}
      cout<<"ingrese el anio: ";
      cin>>anio;
        while(cin.fail() ||  anio < 0 ||  anio > 2025){
        cout<<"Entrada invalida, ingrese un año actual o un numero entero"<<endl;
        cin.clear();
        cin.ignore(10000,'\n'); cin>>anio;
      }
        setAnio(anio);
        bool esBisiesto = (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
        switch(mes){
    case 1: // Enero
        while(dia < 1 || dia > 31){
            cout << "Enero tiene 31 dias. Ingresa un dia valido: ";
            cin.clear(); cin.ignore(10000, '\n'); cin >> dia;
        }
        break;
    case 2: // Febrero
        while(dia < 1 || dia > (esBisiesto ? 29 : 28)){
            cout << "Febrero tiene " << (esBisiesto ? "29" : "28") << " dias. Ingresa un dia valido: ";
            cin.clear(); cin.ignore(10000, '\n'); cin >> dia;
        }
        break;
    case 3: // Marzo
        while(dia < 1 || dia > 31){
            cout << "Marzo tiene 31 dias. Ingresa un dia valido:  ";
            cin.clear(); cin.ignore(10000, '\n'); cin >> dia;
        }
        break;
    case 4: // Abril
        while(dia < 1 || dia > 30){
            cout << "Abril tiene 30 dias. Ingresa un dia valido: ";
            cin.clear(); cin.ignore(10000, '\n'); cin >> dia;
        }
        break;
    case 5: // Mayo
        while(dia < 1 || dia > 31){
            cout << "Mayo tiene 31 dias. Ingresa un dia valido: ";
            cin.clear(); cin.ignore(10000, '\n'); cin >> dia;
        }
        break;
    case 6: // Junio
        while(dia < 1 || dia > 30){
            cout << "Junio tiene 30 dias. Ingresa un dia valido: ";
            cin.clear(); cin.ignore(10000, '\n'); cin >> dia;
        }
        break;
    case 7: // Julio
        while(dia < 1 || dia > 31){
            cout << "Julio tiene 31 dias. Ingresa un dia valido: ";
            cin.clear(); cin.ignore(10000, '\n'); cin >> dia;
        }
        break;
    case 8: // Agosto
        while(dia < 1 || dia > 31){
            cout << "Agosto tiene 31 dias. Ingresa un dia valido: ";
            cin.clear(); cin.ignore(10000, '\n'); cin >> dia;
        }
        break;
    case 9: // Septiembre
        while(dia < 1 || dia > 30){
            cout << "Septiembre tiene 30 dias. Ingresa un dia valido: ";
            cin.clear(); cin.ignore(10000, '\n'); cin >> dia;
        }
        break;
    case 10: // Octubre
        while(dia < 1 || dia > 31){
            cout << "Octubre tiene 31 dias. Ingresa un dia valido: ";
            cin.clear(); cin.ignore(10000, '\n'); cin >> dia;
        }
        break;
    case 11: // Noviembre
        while(dia < 1 || dia > 30){
            cout << "Noviembre tiene 30 dias. Ingresa un dia valido: ";
            cin.clear(); cin.ignore(10000, '\n'); cin >> dia;
        }
        break;
    case 12: // Diciembre
        while(dia < 1 || dia > 31){
            cout << "Diciembre tiene 31 dias. Ingresa un dia valido: ";
            cin.clear(); cin.ignore(10000, '\n'); cin >> dia;
        }
        break;
    default:
        cout << "Mes invalido. Ingresa un numero entre 1 y 12." << endl;
        break;
}
      setDia(dia);
      setMes(mes);


}

void Fecha::mostrarFecha()const{
    cout<<"El producto se compro el : "<<getDia()<<"/"<<getMes()<<"/"<<getAnio()<<endl;

}
