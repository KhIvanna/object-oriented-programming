#include "Lab_4.h"
#include <iostream>
#include <string>

using namespace std;

Plant::Plant(string plantName, string plantColor) : name(plantName), color(plantColor) {}

Plant::~Plant() {}

string Plant::getName() const {
    return name;
}

string Plant::getColor() const {
    return color;
}

void Plant::displayInfo() const {
    cout << "Plant: " << name << ", color: " << color << endl;
}

void Plant::grow() {
    cout << name << " grows slowly." << endl;
}

Tree::Tree(string treeName, string treeColor, double treeHeight)
    : Plant(treeName, treeColor), height(treeHeight) {}

void Tree::displayInfo() const {
    Plant::displayInfo();
    cout << "Height: " << height << " meters." << endl;
}

void Tree::grow() {
    height += 0.05;
    cout << name << " grows. New height: " << height << " meters." << endl;
}

void Tree::grow(double additionalHeight) {
    height += additionalHeight;
    cout << name << " grows intensively by " << additionalHeight << " meters. New height: " << height << " meters." << endl;
}

Flower::Flower(string flowerName, string flowerColor, bool flowerSmell)
    : Plant(flowerName, flowerColor), hasSmell(flowerSmell) {}

void Flower::displayInfo() const {
    Plant::displayInfo();
    if (hasSmell) {
        cout << "Has a pleasant smell." << endl;
    } else {
        cout << "Has no smell." << endl;
    }
}

void Flower::grow() {
    cout << name << " blossoms." << endl;
}

void Flower::grow(bool sunny) {
    if (sunny) {
        cout << name << " reaches for the sun and grows quickly." << endl;
    } else {
        cout << name << " grows slower in the shade." << endl;
    }
}

Conifer::Conifer(string coniferName, string coniferColor, double coniferHeight, bool needles)
    : Tree(coniferName, coniferColor, coniferHeight), hasNeedles(needles) {}

void Conifer::displayInfo() const {
    Tree::displayInfo();
    if (hasNeedles) {
        cout << "Has needles." << endl;
    } else {
        cout << "Is a deciduous tree." << endl;
    }
}

void Conifer::grow() {
    cout << name << " grows, producing new needles." << endl;
}

Rose::Rose(string roseName, string roseColor,  bool flowerSmell, bool thorns)
    : Flower(roseName, roseColor, true), hasThorns(thorns) {}

void Rose::displayInfo() const {
    Flower::displayInfo();
    if (hasThorns) {
        cout << "Has thorns." << endl;
    } else {
        cout << "Is thornless." << endl;
    }
}

void Rose::grow() {
    cout << name << " produces new shoots." << endl;
}

void Rose::prick()const {
    if (hasThorns) {
        cout << name << " can prick you!" << endl;
    } else {
        cout << name << " is thornless and safe to touch." << endl;
    }
}

FruitTree::FruitTree(string fruitTreeName, string fruitTreeColor, double treeHeight, string fruitType)
    : Tree(fruitTreeName, fruitTreeColor, treeHeight), fruitType(fruitType) {}

void FruitTree::displayInfo() const {
    Tree::displayInfo();
    cout << "Fruit: " << fruitType << "." << endl;
}

void FruitTree::grow() {
    cout << name << " develops its crown for fruits." << endl;
}