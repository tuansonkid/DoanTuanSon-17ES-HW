package bank_account;

public class bank_account {
	private long id;
	private double balance;
	public bank_account(long id, double balance) {
		this.id = id;
		this.balance = balance;
	}
	public void deposit(double amount) {
		balance = balance + amount;
	}
	public void withdraw(double amount) {
		balance = balance - amount;
	}
	public void details() {
		System.out.println("account id="+id);
		System.out.println("account balance="+balance);
	}

	public static void main(String args[]) {
		bank_account acc1 = new bank_account(151, 150000);
		bank_account acc2 = new bank_account(131, 300000);
		acc1.details();
		acc2.details();
		acc1.deposit(100000);
		acc2.withdraw(100000);
		acc1.details();
		acc2.details();
	}
}
