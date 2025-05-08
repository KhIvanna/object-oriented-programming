#ifndef LAB_4_H
#define LAB_4_H

#include <string>
#include <iostream>

using namespace std;

class Plant {
protected:
    string name;
    string color;

public:
    Plant(string plantName, string plantColor);
    ~Plant();

    string getName() const;
    string getColor() const;

    virtual void displayInfo() const;
    virtual void grow();
};

class Tree : public Plant {
protected:
    double height;

public:
    Tree(string treeName, string treeColor, double treeHeight);
    void displayInfo() const override;
    void grow() override;
    void grow(double additionalHeight); 
};

class Flower : public Plant {
protected:
    bool hasSmell;

public:
    Flower(string flowerName, string flowerColor, bool flowerSmell);
    void displayInfo() const override;
    void grow() override;
    void grow(bool sunny);
};

class Conifer : public Tree {
protected:
    bool hasNeedles;

public:
    Conifer(string coniferName, string coniferColor, double coniferHeight, bool needles);
    void displayInfo() const override;
    void grow() override;
};

class Rose : public Flower {
protected:
    bool hasThorns;

public:
    Rose(string roseName, string roseColor,  bool flowerSmell, bool thorns);
    void displayInfo() const override;
    void grow() override;
    void prick() const;
};

class FruitTree : public Tree {
protected:
    string fruitType;

public:
    FruitTree(string fruitTreeName, string fruitTreeColor, double treeHeight, string fruitType);
    void displayInfo() const override;
    void grow() override;
};

#endif