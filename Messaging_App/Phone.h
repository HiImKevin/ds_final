// Kevin Wallace
// Phone interface file
// 4/23/18
// Phone.h
// Description: The phone class contains data about the make, model and carrier of the phone, as well as
//              the name and number of who will use the phone. Also contains functions to enable adding
//              contacts to the phone, as well as sending calls and messages to those Contacts.

#ifndef PHONE_H
#define PHONE_H

#pragma warning(disable : 4996) //for deprecated localtime; okay for now - fix later

#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <fstream>
#include <ctime>   // localtime
#include <sstream> // stringstream
#include <iomanip> // put_time
#include <string>  // string
#include <algorithm>

#include "Contact.h"
using namespace std;

class Phone {
public:
	//Constructor
	Phone(string newBrand, string newModel, string newCarrier);

	//Copy constructor
	Phone(const Phone &otherPhone);

	//Assignment operator
	Phone &operator =(const Phone &otherPhone);

	//Destructor
	~Phone();

	// Sorts contacts ascending based on ASCII value
	void sortContacts();

	// Outputs list of Contacts
	void displayContacts();

	// Add a Contact to dynamic array
	bool addContact();

	// Attempts to complete call and outputs to callLog.txt
	bool makeCall();

	// Send a message to a Contact
	bool sendMsg();

	// Reverses log, now stores logs from newest to oldest using STL reverse()
	void reverseLog();

	// Validate the Contact name
	// Returns true when name is not taken
	bool validateContact(string desiredName);

private:
	string brand, model, carrier;
	string phoneNum = "774-265-9844";
	string name;
	Contact *contacts; //point to dynamic array of Contacts
	int capacity;
	int contactsStored;
	vector<string> callLog; //holds list of strings, also printed to txt file
};

#endif


