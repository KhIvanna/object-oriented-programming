#include <iostream>
#include <fstream>
#include "Lab_1.h"
 
using namespace std;

int main() { 
    ifstream file("products.txt");
    if (!file.is_open()) {
        cout << "Файл не відкривається" << endl;
        return 1;
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

    return 0;
}