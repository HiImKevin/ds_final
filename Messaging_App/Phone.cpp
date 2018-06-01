// Kevin Wallace
// Phone implementation file
// 4/23/18
// Phone.cpp
// Description: The phone class contains data about the make, model and carrier of the phone, as well as
//              the name and number of who will use the phone. Also contains functions to enable adding
//              contacts to the phone, as well as sending calls and messages to those Contacts.
// References used in this file:
//https://stackoverflow.com/questions/4184468/sleep-for-milliseconds
//https://stackoverflow.com/questions/15056406/c-fstream-overwrite-instead-of-append
//https://stackoverflow.com/questions/17223096/outputting-date-and-time-in-c-using-stdchrono

#ifndef PHONE_CPP
#define PHONE_CPP

#include "Phone.h"

// Constructor
Phone::Phone(string newBrand, string newModel, string newCarrier) {
	brand = newBrand;
	model = newModel;
	carrier = newCarrier;
	capacity = 100;
	contactsStored = 0;
	contacts = new Contact[capacity];

	cout << "Thank you for purchasing the " << brand << " " << model << " with service from " << carrier << "." << endl << endl;
	cout << "We're going to help you set up your new phone today!" << endl
		<< "First we need to know who will be using this phone." << endl << endl
		<< "Please enter your name: ";

	string userName;
	getline(cin, userName);

	name = userName;

	cout << endl << "Thanks " << name << "! Your assigned phone number is: " << phoneNum << endl;
	cout << "Your phone is now setup and ready for use. Enjoy!" << endl << endl;

}

// Copy constructor
Phone::Phone(const Phone &otherPhone) {

	// Copy non-dynamic data members
	brand = otherPhone.brand;
	model = otherPhone.model;
	carrier = otherPhone.carrier;
	phoneNum = otherPhone.phoneNum;
	name = otherPhone.name;
	capacity = otherPhone.capacity;
	contactsStored = otherPhone.contactsStored;

	// Allocate new array for copy
	contacts = new Contact[contactsStored];

	// Copy each Contact individually
	for (int i = 0; i < contactsStored; i++) {
		contacts[i] = otherPhone.contacts[i];
	}
}

// Assignment Operator
Phone &Phone::operator=(const Phone &otherPhone)
{
	// Avoid self-assignment
	if (this != &otherPhone) {
		// deallocate resources
		delete[] contacts;

		// copy non dynamic data members
		brand = otherPhone.brand;
		model = otherPhone.model;
		carrier = otherPhone.carrier;
		phoneNum = otherPhone.phoneNum;
		name = otherPhone.name;
		capacity = otherPhone.capacity;
		contactsStored = otherPhone.contactsStored;

		// allocate new array
		contacts = new Contact[contactsStored];

		// copy elements element by element
		for (int i = 0; i < contactsStored; i++)
			contacts[i] = otherPhone.contacts[i];
	}

	return *this;

}

// Destructor
Phone::~Phone() {
	// Deallocate dynamic array
	delete[] contacts;
	// Prevents dangling pointer
	contacts = NULL;
	// Resets other data members
	brand = "";
	model = "";
	carrier = "";
	phoneNum = "";
	name = "";
	capacity = 0;
	contactsStored = 0;
}

// Sorts contacts ascending based on ASCII value
void Phone::sortContacts() {
	for (int i = 0; i < contactsStored - 1; i++)
	{
		int minI = i;

		for (int j = i + 1; j < contactsStored; j++)
			if (contacts[j] < contacts[minI])
				minI = j;

		swap(contacts[i], contacts[minI]);
	}
}

// Outputs list of Contacts
void Phone::displayContacts() {
	sortContacts();

	for (int i = 0; i < contactsStored; i++) {
		if (contacts[i].getName() == "Default")
			break;

		cout << endl << "Name: " << contacts[i].getName() << endl
			<< "Phone: " << contacts[i].getPhoneNum() << endl;
	}
	cout << endl;
}

// Add a Contact to dynamic array
bool Phone::addContact() {
	string name, num;

	cout << "Enter the contacts name: ";
	getline(cin, name);

	if (!validateContact(name)) {
		return false;
	}

	cout << "Enter the contacts phone #: ";
	getline(cin, num);

	if (contactsStored < capacity) { // if there is room
		contacts[contactsStored].set(name, num);
		contactsStored++;
		cout << endl << "Contact added." << endl << endl;

		return true;
	}

	cout << endl << "Contact could not be added. Need additional space." << endl << endl;

	return false;
}

// Attempts to complete call and outputs to callLog.txt
bool Phone::makeCall() {
	string callContact;

	cout << "Who would you like to call?: ";
	getline(cin, callContact);

	// Linear search to ensure Contact exists in list
	for (int i = 0; i < capacity; i++) {
		if (contacts[i].getName() == callContact) {
			cout << endl << "Calling " << callContact << ". ";
			this_thread::sleep_for(chrono::milliseconds(1500));
			cout << ". ";
			this_thread::sleep_for(chrono::milliseconds(1500));
			cout << ". ";
			this_thread::sleep_for(chrono::milliseconds(1500));
			cout << ". ";
			this_thread::sleep_for(chrono::milliseconds(1500));
			cout << ". ";
			this_thread::sleep_for(chrono::milliseconds(1500));

			cout << "No answer." << endl << endl;

			auto now = chrono::system_clock::now();
			auto in_time_t = chrono::system_clock::to_time_t(now);

			stringstream ss;
			ss << put_time(localtime(&in_time_t), "%Y-%m-%d %X");

			callLog.push_back(name + " " + phoneNum + " TO " + contacts[i].getName() + " " + contacts[i].getPhoneNum() + " " + ss.str() + " " + "\n");

			ofstream logger("callLog.txt", ios_base::app);
			logger << callLog.back();
			logger.close();

			return true;
		}
	}

	cout << endl << "No \"" << callContact << "\" found in contacts." << endl << endl;
	return false;
}

// Send a message to a Contact
bool Phone::sendMsg() {
	string msgContact, msg;

	cout << "Who would you like to message?: ";
	getline(cin, msgContact);

	// Linear search to verify Contact exists in list
	for (int i = 0; i < capacity; i++) {
		if (contacts[i].getName() == msgContact) {
			contacts[i].messageContact(name);

			return true;
		}
	}

	cout << endl << "No \"" << msgContact << "\" found in contacts." << endl << endl;
	return false;
}

// Reverses log, now stores logs from newest to oldest
void Phone::reverseLog() {
	reverse(callLog.begin(), callLog.end());
}

// Validate the Contact name is unique
bool Phone::validateContact(string desiredName) {
	for (int i = 0; i < contactsStored; i++) {
		if (contacts[i].getName() == desiredName) {
			cout << desiredName + " is already in Contacts. Did not add." << endl;
			return false;
		}
	}
	return true;
}
#endif