/*
Name: Muhammad Sabeeh
ID: 23k0002
*/

#include <iostream>
#include <string>

using namespace std;

class Account
{
    int AccountNum;
    double Balance;

public:
    // parameterized constructor
    Account(int n, double b) : AccountNum(n), Balance(b) {}
    int getnum()
    {
        return AccountNum;
    }
    double getbal()
    {
        return Balance;
    }

    virtual void Deposit(double amount) = 0;
    virtual void Withdraw(double amount) = 0;
    virtual void CalculateInterest() = 0;
};

class SavingsAccount : public Account
{
    double InterestRate;

public:
    // constructor
    SavingsAccount(int num, double b, double rate) : Account(num, b), InterestRate(rate) {}
    void Deposit(double amount) override
    {
        double ball = getbal();
        ball += amount;
    }
    void Withdraw(double n) override
    {
        double ball = getbal();
        ball -= n;
    }
    void CalculateInterest() override
    {
        double ball = getbal();
        cout << "Interest = " << ball * InterestRate << endl;
    }
};
class CurrentAccount : public Account
{
    double OverDraftLimit;

public:
    CurrentAccount(int num, double b, double limit) : Account(num, b), OverDraftLimit(limit) {}
    void Deposit(double amount) override
    {
        double ball = getbal();
        ball += amount;
    }
    void Withdraw(double n) override
    {
        double ball = getbal();
        ball -= n;
    }
    void CalculateInterest() override
    {
        cout << "No Interest Available For Current Account." << endl;
    }
};

int main()
{
    cout<<"Name: Muhammad Sabeeh\nRoll no: 23k-0002\n"<<endl;

    SavingsAccount s1(20, 500, 1.5);
    CurrentAccount c1(7, 1000, 4000);

    s1.CalculateInterest();
    c1.CalculateInterest();

    return 0;
}
