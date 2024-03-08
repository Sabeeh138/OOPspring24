/*
Name: Muhammad Sabeeh
id:23k-0002
*/
#include<iostream>

using namespace std;

class BankAccount{
    public:
        int accountNumber;
        string accountHolderName;
        double balance;
   
    public:
        BankAccount(int accnum, string accname, int abalance) {
            accountNumber=accnum;
            accountHolderName=accname;
            balance=abalance;
        }

        void deposit(double amount) {
            balance=balance+amount;
        }

        int withdraw(double amount) {
            if(amount>balance){
                cout<<"insufficent amount"<<endl;
            } else {
                balance=balance-amount;
            }
        }

        void display() {
            cout<<"following are the account details"<<endl;
            cout<<"the account number is: "<<accountNumber<<endl;
            cout<<"the name of the account holder is: "<<accountHolderName<<endl;
            cout<<"the balance currently in the account is: "<<balance<<endl;
        }
};

int main() {
    //array of banckaccount objects
	BankAccount accounts[3]={
    BankAccount(1010, "bill gates", 0),
    BankAccount(1011, "rothschild", 2000), 
    BankAccount(1111, "stradman", 3000)
    };

    cout<<"welcome to bank account management system"<<endl;

    for(int i = 0; i<3; i++) {
        accounts[i].display();
        cout<<"\n";
    }

    accounts[0].deposit(0);
    accounts[0].withdraw(200);

    cout<<"new account details are: "<<endl;
    accounts[0].display();

}
