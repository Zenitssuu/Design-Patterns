#include<iostream>
#include<vector>
using namespace std;

class Product{
public:
    string name;
    int price;

    Product(string name, int price){
        this->name = name;
        this->price = price;
    }
};

class ShoppingCart{
private:
    vector<Product*> items;

public:
    void addProduct(Product* p){
        items.push_back(p); 
    }

    const vector<Product*> getProducts(){
        return items;
    }

    //calculating total pprice of cart items
    double calculatePrice(){
        double price=0;
        for(auto it:items){
            price+=it->price;
        }
        return price;
    }

    //violating SRP as we are adding multiple responsibility
    //printing invoice
    void printInvoice(){
        for(auto it:items){
            cout<<it->name<<" "<<it->price<<endl;
        }
    }

    //saving the items to db
    void saveToDB(){
        cout<<"Saved to DB"<<endl;
    }
};

int main(){
    Product* p1 = new Product("Football", 800);
    Product* p2 = new Product("Football Boots", 1000);
    Product* p3 = new Product("Football Socks", 200);

    ShoppingCart* sc = new ShoppingCart();
    sc->addProduct(p1);
    sc->addProduct(p2);
    sc->addProduct(p3);

    cout<<sc->calculatePrice()<<endl;

    sc->printInvoice();
    sc->saveToDB();


    return 0;
}