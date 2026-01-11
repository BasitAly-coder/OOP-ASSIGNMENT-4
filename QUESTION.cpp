#include <iostream>
using namespace std;

class BankAccount {
private:
    string holderName;
    double balance;

public:
    BankAccount(string name, double initialBalance) {
		cout << "Constructor called." << endl;
        cout << endl;
        cout << "NAME: " << name << endl;

        if (initialBalance < 0) {
            throw invalid_argument("Initial balance cannot be negative.");
        }
		cout << "Initial Balance: " << initialBalance << endl;

        holderName = name;
        balance = initialBalance;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            throw runtime_error("Insufficient money balance for withdrawal.");
        }
        balance -= amount;
        cout << "Withdrawal successful. Remaining balance in your account is: " << balance << endl;
    }

    ~BankAccount() {
        cout << "Destructor called for " << holderName << endl;
    }
};

int main() {

    BankAccount* account = nullptr;

    try {
        account = new BankAccount("Ali", -500);
    }
    catch ( exception& e) {
        cout << "Account creation failed: " << e.what() << endl;
    }

    try {
        account = new BankAccount("Basit", 1000);

        account->withdraw(2000);
    }
    catch ( exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    delete account;
    return 0;
}
