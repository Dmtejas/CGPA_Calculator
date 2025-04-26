#include <iostream>
#include <string>
using namespace std;

class Account {
    int accountNumber;
    double balance;
public:
    Account(int accNum, double initialBalance) {
        accountNumber = accNum;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if(amount > 0) {
            balance += amount;
            cout << "Deposit successful.\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(double amount) {
        if(amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful.\n";
        } else {
            cout << "Invalid withdrawal or insufficient funds.\n";
        }
    }

    void displayBalance() {
        cout << "Account Balance: " << balance << endl;
    }

    int getAccountNumber() {
        return accountNumber;
    }
};

class Customer {
    string name;
    Account* account;
public:
    Customer(string n, int accNum, double initialBalance) {
        name = n;
        account = new Account(accNum, initialBalance);
    }

    ~Customer() {
        delete account;
    }

    void deposit(double amount) {
        account->deposit(amount);
    }

    void withdraw(double amount) {
        account->withdraw(amount);
    }

    void displayAccountInfo() {
        cout << "Customer: " << name << endl;
        account->displayBalance();
    }

    int getAccountNumber() {
        return account->getAccountNumber();
    }
};

class BankingService {
    Customer* customer;
public:
    BankingService(Customer* c) {
        customer = c;
    }

    void deposit(double amount) {
        customer->deposit(amount);
    }

    void withdraw(double amount) {
        customer->withdraw(amount);
    }

    void viewAccount() {
        customer->displayAccountInfo();
    }
};

int main() {
    string name;
    int accNum;
    double initialBalance;

    cout << "Enter customer name: ";
    cin >> ws;  // to handle spaces in the name
    getline(cin, name);
    cout << "Enter account number: ";
    cin >> accNum;
    cout << "Enter initial balance: ";
    cin >> initialBalance;

    Customer* customer = new Customer(name, accNum, initialBalance);
    BankingService bank(customer);

    int choice;
    do {
        cout << "\n1. Deposit\n2. Withdraw\n3. View Account\n4. Exit\nEnter your choice: ";
        cin >> choice;
        if(choice == 1) {
            double amount;
            cout << "Enter deposit amount: ";
            cin >> amount;
            bank.deposit(amount);
        } else if(choice == 2) {
            double amount;
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            bank.withdraw(amount);
        } else if(choice == 3) {
            bank.viewAccount();
        } else if(choice == 4) {
            cout << "Thank you for using our banking services.\n";
        } else {
            cout << "Invalid choice.\n";
        }
    } while(choice != 4);

    delete customer; // Free the customer object
    return 0;
}
