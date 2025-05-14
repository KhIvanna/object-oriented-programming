#ifndef LAB_5_H
#define LAB_5_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Plant {
protected:
    string name;
    string color;

public:
    Plant();
    Plant(string plantName, string plantColor);
    ~Plant();

    string getName() const;
    string getColor() const;

    virtual void displayInfo() const;
};

class Tree : public virtual Plant {
protected:
    double height;

public:
    Tree(string treeName, string treeColor, double treeHeight);
    ~Tree();

    double getHeight() const;
    virtual void displayInfo() const override;
};

class Flower : public virtual Plant {
protected:
    bool hasSmell;

public:
    Flower(){};
    Flower(string flowerName, string flowerColor, bool flowerSmell);
    ~Flower();

    bool getHasSmell() const;
    virtual void displayInfo() const override;
};

class FruitTree : public Flower, public Tree {
protected:
    string fruittype;

public:
    FruitTree(string fruitTreeName, string fruitTreeColor, double treeHeight, bool flowerSmell, string fruitType);
    ~FruitTree();

    string getFruitType() const;
    virtual void displayInfo() const override;
};

class StoneFruitTree : virtual public FruitTree {
protected:
    double pitHardness;
public:
    StoneFruitTree(string fruitTreeName, string fruitTreeColor, double treeHeight, bool flowerSmell, string fruitType);
    ~StoneFruitTree();
    virtual void displayInfo() const override;
};

class PomeFruitTree : virtual public FruitTree {
protected:
    string coreType;
public:
    PomeFruitTree(string fruitTreeName, string fruitTreeColor, double treeHeight, bool flowerSmell, string fruitType);
    ~PomeFruitTree();
     virtual void displayInfo() const override;
};

class BerryFruitTree : virtual public FruitTree {
protected:
    int clusterSize;
public:
    BerryFruitTree(string fruitTreeName, string fruitTreeColor, double treeHeight, bool flowerSmell, string fruitType);
    ~BerryFruitTree();
     virtual void displayInfo() const override;
};

class HybridFruitTree : public StoneFruitTree, public PomeFruitTree, public BerryFruitTree {
public:
    HybridFruitTree(string fruitTreeName, string fruitTreeColor, double treeHeight, bool flowerSmell);
     ~HybridFruitTree();
    virtual void displayInfo() const override;
};

#endif