#include<iostream>
using namespace std;

class Shapes2D
{
public:
    virtual double area(double l, double b) = 0;
};

class Shapes3D{
public:
    virtual double area(double l, double b) = 0;
    virtual double volume(double l, double b, double h) = 0;
};

class Square : public Shapes2D
{
public:
    double area(double l, double b) override {
        return l*b;
    }
};

class Rectangle : public Shapes2D
{
public:
    double area(double l, double b) override {
        return l*b;
    } 
};

class Cube : public Shapes3D
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
    Shapes2D* sq = new Square();
    Shapes2D* rect = new Rectangle();
    Shapes3D* cb = new Cube();

    cout<<"area of a square: "<<sq->area(10,10)<<endl;
    cout<<"area of a rectangle: "<<rect->area(10,20)<<endl;

    cout<<"volume of a cube: "<<cb->volume(10,10,10)<<endl;

    return 0;
}