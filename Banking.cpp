#include <iostream>
#include <ctime>

typedef std::string string;

// pre defining methods as i put them under main
void withdraw(int amount);
void depoist(int amount);
void start();

// global variables
int balance;

int main() {
	//output("test", true);
	//output("test2", true);


	//set balance to random
	srand(time(NULL));
	balance = (rand() % 5000) + 1;

	//startup
	start();

	return 0;
}

// The start of the bank interface
void start() {

	//local variable
	char mode = ' ';
	do {
		std::cout << "************ Skitbet Banking ************\n";
		std::cout << "Please type the corisponding number for what you wish to do.\n";
		std::cout << " - 1 | Withdraw\n";
		std::cout << " - 2 | Depoist\n";
		std::cout << "Your current balance is: " << balance << std::endl;
		std::cin >> mode;
	} while (mode == ' ');

	switch (mode) {
		case '1':
			int withdrawAmount;
			std::cout << "How much would you like to withdraw?\n";
			std::cin >> withdrawAmount;
			withdraw(withdrawAmount);
			break;
		case '2':
			int depoistAmount;
			std::cout << "How much would you like to depoist?\n";
			std::cin >> depoistAmount;
			depoist(depoistAmount);
			break;
		default:
			start();
			break;
	}

}

// The depoist method, takes in a amount of money to depoist in.
void depoist(int amount) {
	balance += amount;
	std::cout << "You have depoisted $" << amount << " into your account" << std::endl;

	start();
}

// The withdraw method, tkaes the amount of money to take out of the account.
void withdraw(int amount) {
	if (balance < amount) {
		std::cout << "You do not have enough money to widthdraw: " << amount << std::endl;
		start();
	}

	balance -= amount;
	std::cout << "You have withdrawn $" << amount << " from your account" << std::endl;

	start();
}