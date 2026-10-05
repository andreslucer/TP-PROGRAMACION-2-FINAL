#ifndef UTILIDADES_H_INCLUDED
#define UTILIDADES_H_INCLUDED

#include <cctype>
#include <cstring>
using namespace std;

// Convierte todas las letras a minusculas
inline void aMinusculas(char *texto) {
    for (int i = 0; texto[i] != '\0'; i++) {
        texto[i] = tolower(texto[i]);
    }
}

// Verifica que el texto solo tenga letras y espacios
inline bool soloLetras(const char *texto) {
    if (strlen(texto) == 0) return false;  // no puede estar vacio
    for (int i = 0; texto[i] != '\0'; i++) {
        if (!isalpha(texto[i]) && texto[i] != ' ')
            return false;
    }
    return true;
}


// Verifica que el texto solo tenga numeros
inline bool soloNumeros(const char *texto) {
    for (int i = 0; texto[i] != '\0'; i++) {
        if (!isdigit(texto[i])) return false;
    }
    return true;
}

#endif // UTILIDADES_H_INCLUDED
