/*
programmer: muhammad Sabeeh
id; 23k-0002
*/
#include <iostream>
#include <cstring>

using namespace std;

class BankAccount {
private:
    int accountId;
    double balance;
    int* transactionHistory;
    int numTransactions;

public:
    // Constructor
    BankAccount(int id, double initialBalance, int* transactions, int numTrans) 
        : accountId(id), balance(initialBalance), numTransactions(numTrans) {
       
        transactionHistory = new int[numTrans];
        memcpy(transactionHistory, transactions, numTrans * sizeof(int));
    }

    // Copy constructor
    BankAccount(const BankAccount& other) 
        : accountId(other.accountId), balance(other.balance), numTransactions(other.numTransactions) {
       
        transactionHistory = new int[numTransactions];
        memcpy(transactionHistory, other.transactionHistory, numTransactions * sizeof(int));
    }

    // Destructor
    ~BankAccount() {
        delete[] transactionHistory;
    }

    // Display function
    void display() {
        cout << "Account ID: " << accountId << endl;
        cout << "Balance: $" << balance << endl;
        cout << "Transaction History:" << endl;
        for (int i = 0; i < numTransactions; ++i) {
            cout << "Transaction " << i+1 << ": " << transactionHistory[i] << endl;
        }
    }

    // Function to update transaction history
    void updateTransactionHistory(int* newTransactions, int newNumTransactions) {
        
        delete[] transactionHistory;
       
        transactionHistory = new int[newNumTransactions];
        memcpy(transactionHistory, newTransactions, newNumTransactions * sizeof(int));
        // Update number of transactions
        numTransactions = newNumTransactions;
    }
};

int main() {
    int initialTransactions[] = {100, 200, -50};
    int numInitialTransactions = sizeof(initialTransactions) / sizeof(int);

    
    BankAccount originalAccount(123456, 500.0, initialTransactions, numInitialTransactions);

   
    BankAccount copiedAccount(originalAccount);

    // Displaying details of both original and copied accounts
    cout << "Original Account Details:" << endl;
    originalAccount.display();
    cout << endl;

    cout << "Copied Account Details:" << endl;
    copiedAccount.display();
    cout << endl;

    
    int newTransactions[] = {300, -100};
    int numNewTransactions = sizeof(newTransactions) / sizeof(int);
    originalAccount.updateTransactionHistory(newTransactions, numNewTransactions);

    
    cout << "Original Account Details after updating transaction history:" << endl;
    originalAccount.display();

    return 0;
}
