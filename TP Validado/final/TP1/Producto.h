#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

class Producto {
    private:
        int _id;
        char _nombreProducto[20];
        char _DniProveedor[20];
        char _TipoProducto[20];
        float _PrecioUnitario;
        int _CantUnidades;
        bool _estado;
    public:
        Producto();
        Producto(int,const char *,const char * ,const char *, float,int, bool);
        void setIdProducto(int );
        void setDniProveedor(const char * );
        void setNombreProducto(const char* );
        void setTipoProducto(const char * );
        void setPrecioUnitario(float );
        void setCantUnidades(float );
        void setEstado(bool);
        int GetId()const;
        float GetPrecioUnitario()const;
        int GetCantUnidades()const;
        const char * GetnombreProducto()const;
        const char * GetTipoProducto()const;
        const char * GetDniProveedor()const;
        bool GetEstado()const;
        void cargar ();
        void mostrar();
        void mostrarCompra()const;

};





#endif // PRODUCTO_H_INCLUDED
