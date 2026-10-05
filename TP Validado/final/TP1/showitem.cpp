#include <iostream>
#include "rlutil.h"
#include "showitem.h"
using namespace std;

void ShowItem::showItem(const char * text, int posx, int posy, bool selected){ // HACER ESTA FUNCION EN TODOS LOS SUB MENUS
    if(selected ){
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
            rlutil::locate(posx - 2, posy);
            cout<<" "<<(char)175 <<" " << text << " "<< (char)174 <<" ";
    } else {
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
            rlutil::locate(posx - 2, posy);
            cout<<" " << text << " ";

    }
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
}
