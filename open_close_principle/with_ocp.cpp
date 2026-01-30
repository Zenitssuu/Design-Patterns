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
};

class ShoppingCartPrinter{
private:
    ShoppingCart* cart;
public:
    ShoppingCartPrinter(ShoppingCart* cart){
        this->cart = cart;
    }

    void printInvoice(){
        cout<<"\nPrinting invoice: "<<endl;
        for(auto it:cart->getProducts()){
            cout<<it->name<<" "<<it->price<<endl; 
        }
        cout<<"Invoice completed"<<endl;
    }
};

class ShoppingCartPersistence{
public:
    virtual void saveToDB(ShoppingCart* cart) = 0;
};

class saveToSQLDB : public ShoppingCartPersistence {
public:
    void saveToDB(ShoppingCart* cart) override {
        cout<<"\nSaving to SQL DB..."<<endl;
        cout<<"Saving completed"<<endl;
    }
};

class saveToNoSQLDB : public ShoppingCartPersistence {
public:
    void saveToDB(ShoppingCart* cart) override {
        cout<<"\nSaving to No SQL DB..."<<endl;
        cout<<"Saving completed"<<endl;
    }
};

class saveToFile : public ShoppingCartPersistence {
public:
    void saveToDB(ShoppingCart* cart) override {
        cout<<"\nSaving to File..."<<endl;
        cout<<"Saving completed"<<endl;
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

    ShoppingCartPrinter* cartPrinter = new ShoppingCartPrinter(sc);
    cartPrinter->printInvoice();

    ShoppingCartPersistence* sql = new saveToSQLDB();
    ShoppingCartPersistence* nosql = new saveToNoSQLDB();
    ShoppingCartPersistence* file = new saveToFile();

    sql->saveToDB(sc);
    nosql->saveToDB(sc);
    file->saveToDB(sc);

    return 0;
}