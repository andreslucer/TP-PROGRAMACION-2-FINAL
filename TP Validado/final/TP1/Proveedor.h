#ifndef PROVEEDOR_H_INCLUDED
#define PROVEEDOR_H_INCLUDED


class Proveedor {
    private:
        char _dni[20];
        char _cuit[20];
        char _NombreProveedor[20];
        char _numeroTelefono[20];
        char _Gmail[40];
        char _Direccion[40];
    public:
        Proveedor();
        Proveedor(const char*,const char*,const char*,const char*,const char*,const char*);
        void setDni(const char*);
        void setCuit(const char*);
        void setNombreProveedor(const char * );
        void setNumeroTelefono(const char*);
        void setGmail(const char * );
        void setDireccion(const char * );
        const char * GetDNI();
        const char * GetCuit();
        const char * GetnombreProveedor();
        const char * GetNumeroTelefono();
        const char * GetGmail();
        const char * GetDireccion();
        void cargar ();
        void mostrar();


};
#endif // PROVEEDOR_H_INCLUDED
