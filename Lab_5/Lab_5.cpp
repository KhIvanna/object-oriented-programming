#include "Lab_5.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
Plant::Plant() {
    cout << "Plant constructor" << endl;
}
Plant::Plant(string plantName, string plantColor) {
    name = plantName;
    color = plantColor;
    cout << "Plant constructor" << endl;
}

Plant::~Plant() {
    cout << "Plant destructor called\n" << endl;
}

string Plant::getName() const {
    return name;
}

string Plant::getColor() const {
    return color;
}

void Plant::displayInfo() const {
    cout << "Plant: " << name << ", color: " << color << endl;
}

Tree::Tree(string treeName, string treeColor, double treeHeight) {
    height = treeHeight;
    name = treeName;
    color = treeColor;
    cout << "Constructor Tree" << endl;
}

Tree::~Tree() {
    cout << "Destructor Tree called" << endl;
}

double Tree::getHeight() const {
    return height;
}

void Tree::displayInfo() const {
    Plant::displayInfo();
    cout << "Height: " << height << " meters." << endl;
}


Flower::Flower(string flowerName, string flowerColor, bool flowerSmell) {
    name = flowerName;
    color = flowerColor;
    hasSmell = flowerSmell;
    cout << "Constructor Flower" << endl;
}

Flower::~Flower() {
    cout << "Destructor Flower called" << endl;
}

bool Flower::getHasSmell() const {
    return hasSmell;
}

void Flower::displayInfo() const {
    Plant::displayInfo();
    if (hasSmell) {
        cout << "Has a pleasant smell." << endl;
    } else {
        cout << "Has no smell." << endl;
    }
}

FruitTree::FruitTree(string fruitTreeName, string fruitTreeColor, double treeHeight, bool flowerSmell, string fruitType)
    : Flower(fruitTreeName, fruitTreeColor, flowerSmell),
      Tree(fruitTreeName, fruitTreeColor, treeHeight),
      Plant(fruitTreeName, fruitTreeColor),
      fruittype(fruitType)
{
    cout << "Constructor FruitTree" << endl;
}

FruitTree::~FruitTree() {
    cout << "Destructor FruitTree Called" << endl;
}

string FruitTree::getFruitType() const {
    return fruittype;
}

void FruitTree::displayInfo() const {
    cout << "--- Fruit Tree Info ---" << endl;
    Tree::displayInfo();
    if (getHasSmell()) {
        cout << "It has a pleasant smell." << endl;
    } else {
        cout << "It has no smell." << endl;
    }
    cout << "Fruit: " << getFruitType() << "." << endl;
}

StoneFruitTree::StoneFruitTree(string fruitTreeName, string fruitTreeColor, double treeHeight, bool flowerSmell, string fruitType)
    : FruitTree(fruitTreeName, fruitTreeColor, treeHeight, flowerSmell, fruitType)
{
    cout << "Constructor StoneFruitTree" << endl;
}


StoneFruitTree::~StoneFruitTree() {
    cout << "Destructor StoneFruitTree called" << endl;
}

void StoneFruitTree::displayInfo() const {
    FruitTree::displayInfo();
}

PomeFruitTree::PomeFruitTree(string fruitTreeName, string fruitTreeColor, double treeHeight, bool flowerSmell, string fruitType)
    : FruitTree(fruitTreeName, fruitTreeColor, treeHeight, flowerSmell, fruitType)
{
    cout << "Constructor PomeFruitTree" << endl;
}


PomeFruitTree::~PomeFruitTree() {
     cout << "Destructor PomeFruitTree called" << endl;
}

void PomeFruitTree::displayInfo() const {
    FruitTree::displayInfo();
    cout << "Core type: " << coreType << endl;
}

BerryFruitTree::BerryFruitTree(string fruitTreeName, string fruitTreeColor, double treeHeight, bool flowerSmell, string fruitType)
    : FruitTree(fruitTreeName, fruitTreeColor, treeHeight, flowerSmell, fruitType)
{
    cout << "Constructor BerryFruitTree" << endl;
}


BerryFruitTree::~BerryFruitTree() {
    cout << "Destructor BerryFruitTree called" << endl;
}

void BerryFruitTree::displayInfo() const {
    FruitTree::displayInfo();
    cout << "Cluster size: " << clusterSize << endl;
}

HybridFruitTree::HybridFruitTree(string fruitTreeName, string fruitTreeColor, double treeHeight, bool flowerSmell)
    : Plant(fruitTreeName, fruitTreeColor),
      StoneFruitTree(fruitTreeName, fruitTreeColor, treeHeight, flowerSmell, "peach"),
      PomeFruitTree(fruitTreeName, fruitTreeColor, treeHeight, flowerSmell, "apple"),
      BerryFruitTree(fruitTreeName, fruitTreeColor, treeHeight, flowerSmell, "cherry"),
      FruitTree(fruitTreeName, fruitTreeColor, treeHeight, flowerSmell, "hybrid")
{
    cout << "Constructor HybridFruitTree" << endl;
}

HybridFruitTree::~HybridFruitTree() {
    cout << "Destructor HybridFruitTree called" << endl;
}

void HybridFruitTree::displayInfo() const {
    cout << "--- Hybrid Fruit Tree Info ---" << endl;
    cout << "Plant: " << getName() << ", color: " << getColor() << endl;

}
