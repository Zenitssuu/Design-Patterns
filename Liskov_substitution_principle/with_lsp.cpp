#include <iostream>
#include <vector>
using namespace std;

class NonWithDrawableAcc
{
public:
    virtual int getBalance() = 0;
    virtual void deposit(int amount) = 0;
};

class Account : public NonWithDrawableAcc
{
public:
    virtual int withdraw(int amount) = 0;
};

class SavingAccount : public Account
{
private:
    int balance;

public:
    SavingAccount(int initialAmount)
    {
        this->balance = initialAmount;
    }

    int getBalance() override
    {
        return this->balance;
    }

    void deposit(int amount) override
    {
        if (amount < 0)
            return;
        cout << "\nAdding amount in saving account";
        this->balance += amount;
    }

    int withdraw(int amount) override
    {
        if (amount < 0 || this->balance < amount)
            return 0;
        cout << "\nWithdrawing amount from saving account\n";
        this->balance -= amount;
        return amount;
    }
};

class CurrentAccount : public Account
{
private:
    int balance;

public:
    CurrentAccount(int initialAmount)
    {
        this->balance = initialAmount;
    }

    int getBalance() override
    {
        return this->balance;
    }

    void deposit(int amount) override
    {
        if (amount < 0)
            return;
        cout << "\nAdding amount in current account\n";
        this->balance += amount;
    }

    int withdraw(int amount) override
    {
        if (amount < 0 || this->balance < amount)
            return 0;
        cout << "\Withdrawing amount from current account\n";
        this->balance -= amount;
        return amount;
    }
};

class FixedDepositAccount : public NonWithDrawableAcc
{
private:
    int balance;

public:
    FixedDepositAccount(int initialAmount)
    {
        this->balance = initialAmount;
    }

    int getBalance() override
    {
        return this->balance;
    }

    void deposit(int amount) override
    {
        if (amount < 0)
            return;
        cout << "\nAdding amount in Fixed Deposit account\n";
        this->balance += amount;
    }
};

class BankClient
{
private:
    vector<Account *> withDrawAccounts;
    vector<NonWithDrawableAcc *> nonWithDrawAccounts;

public:
    BankClient(vector<Account *> &withDrawAccounts, vector<NonWithDrawableAcc *> &nonWithDrawAccounts)
    {
        this->withDrawAccounts = withDrawAccounts;
        this->nonWithDrawAccounts = nonWithDrawAccounts;
    }

    void processTransaction()
    {
        cout << "Processing withdrawable accounts" << endl;
        for (auto acc : withDrawAccounts)
        {
            cout << "\nBalance: " << acc->getBalance();
            acc->deposit(500);
            acc->withdraw(200);
            cout << "Balance: " << acc->getBalance() << endl;
        }

        cout << "\nProcessing fixed deposit accounts" << endl;
        for (auto acc : nonWithDrawAccounts)
        {
            cout << "\nBalance: " << acc->getBalance();
            acc->deposit(500);
            cout << "Balance: " << acc->getBalance() << endl;
        }
    }
};

int main()
{
    vector<Account *> withDrawAccounts;
    vector<NonWithDrawableAcc *> nonWithDrawAccounts;

    withDrawAccounts.push_back(new SavingAccount(100));
    withDrawAccounts.push_back(new CurrentAccount(100));
    nonWithDrawAccounts.push_back(new FixedDepositAccount(100));

    BankClient *newClient = new BankClient(withDrawAccounts, nonWithDrawAccounts);
    newClient->processTransaction();

    return 0;
}