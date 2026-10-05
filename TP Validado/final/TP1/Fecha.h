#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha{
private:
    int _dia;
    int _mes;
    int _anio;

    bool fechaValida(int dia,int mes,int anio);
public:
    Fecha();
    Fecha(int,int,int);

    void setDia(int );
    void setMes(int );
    void setAnio(int );

    int getDia()const;
    int getMes()const;
    int getAnio()const;

    void cargar();
    void mostrarFecha()const;

};

#endif // FECHA_H_INCLUDED
