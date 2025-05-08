#include "Lab_4.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    Tree *oakTree = new Tree("Oak", "Brown", 15.2);
    Flower *daisy = new Flower("Daisy", "White", true);
    Conifer *pineTree = new Conifer("Pine", "Green", 8.0, true);
    Rose *redRose = new Rose("Rose", "Red", true, true);
    FruitTree *appleTree = new FruitTree("Apple Tree", "Green", 5.5, "Apple");

    oakTree->displayInfo();
    oakTree->grow();
    oakTree->grow(0.1);
    cout << endl;

    daisy->displayInfo();
    daisy->grow();
    daisy->grow(true);
    cout << endl;

    pineTree->displayInfo();
    pineTree->grow();
    cout << endl;

    redRose->displayInfo();
    redRose->grow();
    redRose->prick();
    cout << endl;

    appleTree->displayInfo();
    appleTree->grow();
    cout << endl;

    delete oakTree;
    delete daisy;
    delete pineTree;
    delete redRose;
    delete appleTree;

    return 0;
}