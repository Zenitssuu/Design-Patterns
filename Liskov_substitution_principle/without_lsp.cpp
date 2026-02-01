#include<iostream>
#include<vector>
using namespace std;

class Account{
public:
    virtual int getBalance() = 0;
    virtual void deposit(int amount) = 0;
    virtual int withdraw(int amount) = 0;
};

class SavingAccount : public Account{
private: 
    int balance;
public:
    SavingAccount(int initialAmount) {
        this->balance = initialAmount;
    }

    int getBalance() override {
        return this->balance;
    }

    void deposit(int amount) override { 
        if(amount < 0) return;
        cout<<"\nAdding amount in saving account";
        this->balance+=amount;
    }
    
    int withdraw(int amount) override {
        if(amount<0 || this->balance < amount) return 0;
        cout<<"\nWithdrawing amount from saving account\n";
        this->balance -= amount;
        return amount;
    }
};

class CurrentAccount : public Account{
    private: 
    int balance;
    public:
    CurrentAccount(int initialAmount) {
        this->balance = initialAmount;
    }
    
    int getBalance() override {
        return this->balance;
    }
    
    void deposit(int amount) override { 
        if(amount < 0) return;
        cout<<"\nAdding amount in current account\n";
        this->balance+=amount;
    }
    
    int withdraw(int amount) override {
        if(amount<0 || this->balance < amount) return 0;
        cout<<"\Withdrawing amount from current account\n";
        this->balance -= amount;
        return amount;
    }
};

class FixedDepositAccount : public Account{
    private: 
    int balance;
    public:
    FixedDepositAccount(int initialAmount) {
        this->balance = initialAmount;
    }
    
    int getBalance() override {
        return this->balance;
    }
    
    void deposit(int amount) override { 
        if(amount < 0) return;
        cout<<"\nAdding amount in Fixed Deposit account\n";
        this->balance+=amount;
    }

    // here withdrawl is not possible so we can't use this as substitue for the base class which violated the LSP
    int withdraw(int amount) override {
        cout<<"Withdrawl not possible"<<endl;
        return 0;
    }
};

class BankClient{
private:
    vector<Account*> accounts;
public:
    BankClient(vector<Account*> &accounts){
        this->accounts = accounts;
    }

    void processTransaction(){
        for(auto acc : accounts){
            cout<<"\nBalance: "<<acc->getBalance();
            acc->deposit(500);
            acc->withdraw(200);
            cout<<"Balance: "<<acc->getBalance()<<endl;
        }
    }
};

int main(){
    vector<Account*> accounts;

    accounts.push_back(new SavingAccount(100));
    accounts.push_back(new CurrentAccount(100));
    accounts.push_back(new FixedDepositAccount(100));

    BankClient* newClient = new BankClient(accounts);
    newClient->processTransaction();

    return 0;
}