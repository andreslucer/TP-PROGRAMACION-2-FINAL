#include "rlutil.h"
#include <iostream>
#include "SubMenuReportes.h"
using namespace std;


void SubmenuReportes::SubMenuRepor(){
    ShowItem obj1;
    _Reportes;

    int x = 55, y = 8, a = 0;
    int opcion = 0;
    bool estado = true;
    int xSelect= 55;
    do {
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        //rlutil::cls();
        int yTemp= y;
        rlutil::hidecursor();
        rlutil::locate(x, yTemp++); cout << "----REPORTES---- " << endl;
        obj1.showItem(" MOSTRAR RECAUDACION POR MES", xSelect, yTemp++, a==0);
        obj1.showItem(" MOSTRAR RECAUDACION POR ANIO", xSelect, yTemp++, a==1);
        obj1.showItem(" RECAUDACION DE EL DIA ELEGIDO", xSelect, yTemp++, a==2);
        obj1.showItem(" RANKING DE LOS PROVEEDORES", xSelect, yTemp++, a==3);
        obj1.showItem(" PROMEDIO DE RECAUDACION MENSUAL", xSelect, yTemp++, a==4);
        obj1.showItem(" CANTIDAD COMPRADA POR MES", xSelect, yTemp++, a==5);
        obj1.showItem(" RECAUDACION POR QUINCENA", xSelect, yTemp++, a==6);
        obj1.showItem(" RECAUDACION POR SEMANA", xSelect, yTemp++, a==7);
        obj1.showItem(" TOP 3 PRODUCTOS MAS COMPRADOS", xSelect, yTemp++, a==8);
        obj1.showItem(" TOTAL DE VENTAS POR ANIO", xSelect, yTemp++, a==9);
        obj1.showItem(" VOLVER ATRAS", xSelect, yTemp++, a==10);
        int key = rlutil::getkey();
        switch(key){
            case 14:
                rlutil::locate(xSelect - 2, 9 + a); cout <<"                                                                                                  "<<endl;
                a--;
                if(a < 0) a = 9;
                break;
            case 15:
            rlutil::locate(xSelect - 2, 9 + a ); cout <<"                                                                                                   "<<endl;
                a++;
                if(a > 9) a = 0;
                break;
            case 1:
                opcion = a + 1;
                rlutil::cls();

        switch(opcion){
            case 1:
                _Reportes.ReportesRecaudacionMes();
                rlutil::anykey();
                rlutil::cls();
                break;
            case 2:
                _Reportes.ReportesRecaudacionAnio();
                rlutil::anykey();
                rlutil::cls();
                break;
            case 3 :
                _Reportes.ReportesRecaudacionDia();
                rlutil::cls();
                break;
            case 4:
                _Reportes.RankingProveedores();
                rlutil::anykey();
                rlutil::cls();
                break;
            case 5:
                _Reportes.promedioRecaudacionMensual();
                rlutil::anykey();
                rlutil::cls();
                break;
            case 6:
                _Reportes.cantidadComprasPorMes();
                rlutil::anykey();
                rlutil::cls();
                break;
            case 7:
                _Reportes.ReportesRecaudacionQuincena();
                rlutil::anykey();
                rlutil::cls();
                break;
            case 8:
                _Reportes.ReportesRecaudacionSemana();
                rlutil::anykey();
                rlutil::cls();
                break;
            case 9:
                _Reportes.Top3ProductosMasComprados();
                rlutil::anykey();
                rlutil::cls();
                break;
            case 10:
                _Reportes.totalDeVentas();
                rlutil::anykey();
                rlutil::cls();
            case 11:
                estado = false;
                break;

            }

        }

    } while(estado);


}
