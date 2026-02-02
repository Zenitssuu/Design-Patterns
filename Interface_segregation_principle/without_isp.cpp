#include<bits/stdc++.h>
using namespace std;

class Shapes
{
public:
    virtual double area(double l, double b) = 0;
    virtual double volume(double l, double b, double h) = 0;
};

class Square : public Shapes
{
public:
    double area(double l, double b) override {
        return l*b;
    }
    double volume(double l, double b, double h) override {
        // not applicable in 2d shapes
        cout<<"No applicable in 2d shapes"<<endl;
        return 0;
    }; 
};

class Rectangle : public Shapes
{
public:
    double area(double l, double b) override {
        return l*b;
    }
    double volume(double l, double b, double h) override {
        // not applicable in 2d shapes
        cout<<"No applicable in 2d shapes"<<endl;
        return 0;
    }; 
};

class Cube : public Shapes
{
public:
    double area(double l, double b) override {
        return l*b;
    }
    double volume(double l, double b, double h) override {
        return l*b*h;
    }; 
};

int main(){
    Shapes* sq = new Square();
    Shapes* rect = new Rectangle();
    Shapes* cb = new Cube();

    cout<<"area of a square: "<<sq->area(10,10)<<endl;
    cout<<"area of a rectangle: "<<rect->area(10,20)<<endl;
    cout<<"volume of a square: "<<sq->volume(10,10,10)<<endl;
    cout<<"volume of a cube: "<<cb->volume(10,10,10)<<endl;

    return 0;
}