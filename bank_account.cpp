#include <iostream>
#include <conio.h>

using namespace std;

class bank_account {
private:
    long id;
	double balance;
public:
    bank_account(long i, double bal) {
		id = i;
		balance = bal;
	}
	void deposit(double amount) {
		balance = balance + amount;
	}
	void withdraw(double amount) {
		balance = balance - amount;
	}
	void details() {
		cout << "account id = " << id << endl;
		cout << "account balance = " << balance << endl << endl;
	}
};

int	main() {
    bank_account acc1(151, 150000);
    bank_account acc2(131, 300000);
    acc1.details();
    acc2.details();
    acc1.deposit(100000);
    acc2.withdraw(100000);
    acc1.details();
    acc2.details();
}
