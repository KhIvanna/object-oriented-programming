#include <iostream>
#include <string>
#include <fstream>
#include "Lab_1.h"

using namespace std;

void output() {
    ifstream file("products.txt");
    if (!file.is_open()) {
        cout << "Файл не відкривається" << endl;
        return;
    }

    cina totalcina = {0, 0};
    cina mn_result;
    cina okr_result;

    int grn, count;
    short int kop;

    while (file >> grn >> kop >> count) {
        cina one_thing = {grn, kop};
        mn(one_thing, count, mn_result);
        dodav(totalcina, mn_result, totalcina);
    }

    file.close();

    cout << "Загальна сума: " << endl;
    printcina(totalcina);
    cout << endl;

    okr(totalcina, okr_result);
    cout << "Сума до оплати (після округлення): " << endl;

    printcina(okr_result);
}


void dodav(cina x, cina y, cina& result){
    result.grn = x.grn + y.grn;
    result.kop = x.kop + y.kop;
}

void mn(cina x, int z, cina& result){
    result.grn = x.grn * z;
    result.kop = x.kop * z;
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

