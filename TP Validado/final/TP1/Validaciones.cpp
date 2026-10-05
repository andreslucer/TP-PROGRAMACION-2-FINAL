#include <iostream>
#include <string>
#include <limits>
#include "Validaciones.h"
using namespace std;

bool esNumero(const string &s) {
    if (s.empty()) return false;
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    return true;
}

int pedirEntero(){
    int valor;
    cin >> valor;

    while(cin.fail()){
        cin.clear();              // limpia el error
        cin.ignore(10000, '\n');  // limpia el buffer
        cout << "ERROR: ingrese solo numeros: ";
        cin >> valor;
    }

    cin.ignore(10000, '\n'); // por si quedan caracteres
    return valor;
}
int pedirAnio(){
    string entrada;
    cout << "Ingrese el anio: ";
    getline(cin, entrada);

    // Si quedó basura del buffer por usos previos
    if (entrada.size() == 0){
        getline(cin, entrada);
    }

    // validar
    while(true){
        bool ok = true;
        for(char c : entrada){
            if(!isdigit(c)){
                ok = false;
                break;
            }
        }

        if(ok && entrada.size() > 0){
            return stoi(entrada);   // convertir a entero
        }

        cout << "ERROR: solo numeros. Reingrese anio: ";
        getline(cin, entrada);
    }
}

int pedirMes(){
    string entrada;
    cout << "Ingrese el mes (1-12): ";
    getline(cin, entrada);

    // si quedó basura de un cin
    if(entrada.size() == 0){
        getline(cin, entrada);
    }

    while(true){
        bool ok = true;

        // validar que todos sean dígitos
        for(char c : entrada){
            if(!isdigit(c)){
                ok = false;
                break;
            }
        }

        if(ok){
            int mes = stoi(entrada);
            if(mes >= 1 && mes <= 12){
                return mes;
            }
        }

        cout << "ERROR: ingrese un mes valido (1-12): ";
        getline(cin, entrada);
    }
}

int pedirEnteroSeguro() {
    string entrada;
    getline(cin, entrada);

    while (!esNumero(entrada)) {
        cout << "ERROR: ingrese solo numeros: ";
        getline(cin, entrada);
    }

    return stoi(entrada);
}

