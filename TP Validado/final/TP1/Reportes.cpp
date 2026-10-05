#include <iostream>
#include <cstdio>
#include "Reportes.h"
#include "rlutil.h"
#include "Validaciones.h"
#include <limits>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void Reportes::ReportesRecaudacionMes() {
    Compras obj;
    FILE *p = fopen("compras", "rb");
    if (!p) {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    int mes;
    float acu = 0;

    // Validación del mes
    while (true) {
        cout << "Ingrese el mes (1-12) para mostrar la recaudacion: ";
        cin >> mes;
        if (cin.fail() || mes < 1 || mes > 12) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Debe ingresar un numero valido entre 1 y 12.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    while (fread(&obj, sizeof(Compras), 1, p) == 1) {
        if (obj.getFecha().getMes() == mes) {
            acu += obj.getPrecioTotalCompra();
        }
    }
    fclose(p);

    cout << "El mes " << mes << " recaudo: $" << acu << endl;
}

void Reportes::ReportesRecaudacionAnio() {
    Compras obj;
    FILE *p = fopen("compras", "rb");
    if (!p) {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    int anio;
    float recauda = 0;

    // Validación del anio (por ejemplo entre 2000 y 2100)
    while (true) {
        cout << "Ingrese el anio a ver la recaudacion: ";
        cin >> anio;
        if (cin.fail() || anio < 2000 || anio > 2100) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Debe ingresar un anio válido (2000-2100).\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    while (fread(&obj, sizeof(Compras), 1, p) == 1) {
        if (obj.getFecha().getAnio() == anio) {
            recauda += obj.getPrecioTotalCompra();
        }
    }
    fclose(p);

    cout << "El anio " << anio << " recaudo: $" << recauda << endl;
}


void Reportes::ReportesRecaudacionDia() {
    Compras obj;
    FILE *p = fopen("compras", "rb");
    if (!p) {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    int dia;
    int acu = 0;

    // Validación del dia
    while (true) {
        cout << "Ingrese el dia a ver las recaudaciones (1-31): ";
        cin >> dia;
        if (cin.fail() || dia < 1 || dia > 31) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Debe ingresar un numero valido entre 1 y 31.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    while (fread(&obj, sizeof(Compras), 1, p) == 1) {
        if (obj.getFecha().getDia() == dia) {
            acu += obj.getPrecioTotalCompra();
        }
    }
    fclose(p);

    rlutil::cls();
    if (acu == 0) {
        rlutil::locate(55, 7);
        cout << "El dia " << dia << " no se realizaron ventas" << endl;
    } else {
        rlutil::locate(55, 7);
        cout << "La recaudacion del dia " << dia << " es: $" << acu << endl;
    }
    rlutil::anykey();
    rlutil::cls();
}

void Reportes::RankingProveedores() {
    FILE* pCompras = fopen("compras", "rb");
    FILE* pProv = fopen("ArchivoProveedor", "rb");

    if (!pCompras || !pProv) {
        cout << "No se pudieron abrir los archivos" << endl;
        return;
    }

    // Leer todos los proveedores
    Proveedor prov;
    std::vector<Proveedor> proveedores;
    while (fread(&prov, sizeof(Proveedor), 1, pProv) == 1) {
        proveedores.push_back(prov);
    }
    fclose(pProv);

    // Acumular ventas por proveedor (clave: DNI)
    std::map<std::string, float> recaudacionPorProveedor;

    Compras compra;
    while (fread(&compra, sizeof(Compras), 1, pCompras) == 1) {
        const Producto& prod= compra.getProducto();
        const char* dniProv = prod.GetDniProveedor();
        recaudacionPorProveedor[dniProv] += compra.getPrecioTotalCompra();
    }
    fclose(pCompras);

    // Pasar a vector para ordenar y mostrar
    std::vector<std::pair<std::string, float>> ranking;
    for (auto &p : proveedores) {
        ranking.push_back({p.GetDNI(), recaudacionPorProveedor[p.GetDNI()]});
    }

    std::sort(ranking.begin(), ranking.end(), [](auto a, auto b) {
        return a.second > b.second;
    });

    // Mostrar ranking
    cout << "RANKING DE PROVEEDORES POR VENTAS" << endl;
    for (size_t i = 0; i < ranking.size(); i++) {
        cout << i + 1 << ". DNI: " << ranking[i].first
             << " - Total vendido: $" << ranking[i].second << endl;
    }
}

void Reportes::promedioRecaudacionMensual(){
    FILE *p = fopen("compras", "rb");
    if(p == NULL){
        cout << "No se pudo abrir el archivo";
        exit(1);
    }

    Compras obj;
    int recaudacionPorMes[12] = {0};

    int anio = pedirAnio();

    while(fread(&obj, sizeof(Compras), 1, p) == 1){
        if(obj.getFecha().getAnio() == anio){
            int mes = obj.getFecha().getMes();
            recaudacionPorMes[mes - 1] += obj.getPrecioTotalCompra();
        }
    }

    fclose(p);

    int total = 0, mesesConVentas = 0;

    cout << "\nRECAUDACION MES A MES EN " << anio << ":\n";
    cout << "--------------------------------------\n";

    const char *nombresMes[] = {
        "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
        "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"
    };

    for(int i = 0; i < 12; i++){
        cout << nombresMes[i] << ": $ " << recaudacionPorMes[i] << endl;

        if(recaudacionPorMes[i] > 0){
            total += recaudacionPorMes[i];
            mesesConVentas++;
        }
    }

    cout << "--------------------------------------\n";

    if(mesesConVentas == 0){
        cout << "No hubo ventas en el anio " << anio << endl;
    } else {
        cout << "PROMEDIO MENSUAL EN " << anio << ": $ "
             << total / mesesConVentas << endl;
    }
}


void Reportes::cantidadComprasPorMes(){
    FILE *p = fopen("compras", "rb");
    if(p == NULL){
        cout << "No se pudo abrir el archivo";
        exit(1);
    }

    Compras obj;
    int comprasPorMes[12] = {0};

    while(fread(&obj, sizeof(Compras), 1, p) == 1){
        int mes = obj.getFecha().getMes();
        if(mes >= 1 && mes <= 12){
            comprasPorMes[mes - 1]++;
        }
    }

    fclose(p);

    const char *nombresMes[] = {
        "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
        "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"
    };

    cout << "\nCANTIDAD DE COMPRAS POR MES:\n";
    cout << "--------------------------------------\n";

    int totalCompras = 0;

    for(int i = 0; i < 12; i++){
        cout << nombresMes[i] << ": " << comprasPorMes[i] << " compras" << endl;
        totalCompras += comprasPorMes[i];
    }

    cout << "--------------------------------------\n";
    cout << "TOTAL DE COMPRAS DEL ANIO: " << totalCompras << endl;
}

void Reportes::ReportesRecaudacionQuincena() {
    FILE *p = fopen("compras", "rb");
    if (p == NULL) {
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }

    Compras obj;
    float acumulado = 0;

    cout << "Ingrese el mes (1-12): ";
    int mes = pedirEnteroSeguro();

    while (mes < 1 || mes > 12) {
        cout << "ERROR: mes invalido. Ingrese un valor entre 1 y 12: ";
        mes = pedirEnteroSeguro();
    }

    cout << "Ingrese la quincena (1-2): ";
    int quincena = pedirEnteroSeguro();

    while (quincena != 1 && quincena != 2) {
        cout << "ERROR: quincena invalida. Ingrese 1 o 2: ";
        quincena = pedirEnteroSeguro();
    }

    while (fread(&obj, sizeof(Compras), 1, p) == 1) {
        if (obj.getFecha().getMes() == mes) {

            int dia = obj.getFecha().getDia();
            bool coincide = false;

            if (quincena == 1 && dia >= 1 && dia <= 15)
                coincide = true;

            if (quincena == 2 && dia >= 16 && dia <= 31)
                coincide = true;

            if (coincide)
                acumulado += obj.getPrecioTotalCompra();
        }
    }

    fclose(p);

    cout << "En la quincena " << quincena
         << " del mes " << mes
         << " se recaudaron: $" << acumulado << endl;
}


void Reportes::ReportesRecaudacionSemana() {
    FILE *p = fopen("compras", "rb");
    if (p == NULL) {
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }

    Compras obj;
    int mes, semana;
    int diaMin = 0, diaMax = 0;
    float acumulado = 0;

    cout << "Ingrese el mes (1-12) a consultar: ";
    mes = pedirEnteroSeguro();

    while (mes < 1 || mes > 12) {
        cout << "ERROR: mes invalido. Ingrese un valor entre 1 y 12: ";
        mes = pedirEnteroSeguro();
    }

    cout << "Ingrese la semana (1-4): ";
    semana = pedirEnteroSeguro();

    while (semana < 1 || semana > 4) {
        cout << "ERROR: semana invalida. Ingrese un valor entre 1 y 4: ";
        semana = pedirEnteroSeguro();
    }

    // Determinar rango de dias según la semana
    switch (semana) {
        case 1: diaMin = 1;  diaMax = 7;  break;
        case 2: diaMin = 8;  diaMax = 14; break;
        case 3: diaMin = 15; diaMax = 21; break;
        case 4: diaMin = 22; diaMax = 31; break;
    }

    // Calcular lo recaudado
    while (fread(&obj, sizeof(Compras), 1, p) == 1) {
        if (obj.getFecha().getMes() == mes) {
            int dia = obj.getFecha().getDia();
            if (dia >= diaMin && dia <= diaMax) {
                acumulado += obj.getPrecioTotalCompra();
            }
        }
    }

    fclose(p);

    cout << "En la semana " << semana
         << " del mes " << mes
         << " se recaudaron: $" << acumulado << endl;
}
void Reportes::Top3ProductosMasComprados(){
    FILE *p=fopen("compras","rb");
    if(p==NULL){
        cout<<"No se pudo abrir el archivo."<<endl;
        return;
    }
    Compras obj;
    //<id producto, cantidad comprada>
    map<int,int>contador;

    while(fread(&obj,sizeof(Compras),1,p)==1){
        int idProd=obj.getProducto().GetId(); //id prod
        int cant=obj.getCantidadComprada(); //cantidad comprada
        contador[idProd]+=cant;
    }
    fclose(p);

    if(contador.empty()){
        cout<<"No existen compras registradas."<<endl;
        return;
    }
    //pasar el map a un vector para ordenarlo
    vector<pair<int,int>>ranking(contador.begin(),contador.end());

    //ordenar descendente por cantidad
    sort(ranking.begin(),ranking.end(),[](const pair<int,int>&a,const pair<int,int>&b){
            return a.second>b.second;
        });
    cout<<"\n===TOP 3 PRODUCTOS MAS COMPRADOS===\n";

    int limite=min(3,(int)ranking.size());
    for(int i=0;i<limite;i++){
        cout<<i+1<<". Producto ID: "<<ranking[i].first <<"| Cantidad Total: "<<ranking[i].second<<endl;
    }
}

void Reportes::totalDeVentas(){
    FILE *p=fopen("compras","rb");
        if(p==NULL){
            cout<<"no se pudo abrir el archivo"<<endl;
            exit(1);
        }
        Compras obj;
        int cont = 0;
        int anio;
        cout<<"ingrese el anio"<<endl;
        cin>>anio;
        while(fread(&obj,sizeof(Compras),1,p)==1){
            if(obj.getFecha().getAnio()== anio){
            cont++;
            }
        }
        fclose(p);
        cout<<"las compras del anio "<< anio<< " fueron " << cont<<endl;




}
