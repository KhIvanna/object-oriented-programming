#include <iostream>
#include <string>
#include "Lab_1.h"

using namespace std;


void dodav(cina x, cina y, cina& result){
    result.grn = x.grn + y.grn;
    result.kop = x.kop + y.kop;

    if (result.kop >= 100) {
        result.grn += result.kop/100;
        result.kop = result.kop%100;
    }
}

void mn(cina x, int z, cina& result){
    result.grn = x.grn * z;
    result.kop = x.kop * z;

    if (result.kop >= 100) {
        result.grn += result.kop/100;
        result.kop = result.kop%100;
    }
}

void okr(cina x, cina& result) {  
    result = x; 
    int ostacha = result.kop % 10;  
    if(ostacha < 5){
        result.kop -= ostacha;
    } else {
        result.kop += (10 - ostacha);
    }

    if (result.kop >= 100) {
        result.grn += result.kop/100;
        result.kop = result.kop%100;
    }
}

void printcina(cina z) {
    cout << z.grn << " грн" << " " << z.kop << " коп";

}

