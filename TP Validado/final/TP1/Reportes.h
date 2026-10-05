#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED
#include "GestorCompras.h"

class Reportes {
    private:
        Compras _Compras;
    public:
        void ReportesRecaudacionMes();
        void ReportesRecaudacionAnio();
        void ReportesRecaudacionDia();
        void RankingProveedores();
        void promedioRecaudacionMensual();
        void cantidadComprasPorMes();
        void ReportesRecaudacionQuincena();
        void ReportesRecaudacionSemana();
        void Top3ProductosMasComprados();
        void totalDeVentas();
};

#endif // REPORTES_H_INCLUDED
