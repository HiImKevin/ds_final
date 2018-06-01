// Kevin Wallace
// Program: Phone System
// 4/24/18
// main.cpp
// Description: This program stores a list of Contacts and
//              simulates the call and text message functions 
//              commonly found in phones.

#include "Phone.h"
#include <iostream>
using namespace std;

void showMenu();

int main() {
	Phone myPhone("Samsung", "Galaxy S8", "T-Mobile");
	int option;

	// Main Menu loop
	do {
		showMenu();
		cout << "Choose an option: ";
		cin >> option;
		cin.ignore();

		switch (option) {
		case 1:
			myPhone.displayContacts();
			break;
		case 2:
			myPhone.addContact();
			break;
		case 3:
			myPhone.makeCall();
			break;
		case 4:
			myPhone.sendMsg();
			break;
		}

	} while (option != 5);

	return 0;
}

void showMenu() {
	cout << "=========================================================" << endl
		<< "                        MAIN MENU                        " << endl
		<< "=========================================================" << endl << endl
		<< "  1.) Display Contacts" << endl
		<< "  2.) Add Contact" << endl
		<< "  3.) Call" << endl
		<< "  4.) Message" << endl
		<< "  5.) Shutdown" << endl << endl;
}