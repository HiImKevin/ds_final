// Kevin Wallace
// Contact implementation file
// 4/23/18
// Contact.cpp
// Description: The Contact class contains data about a Contact which is stored in a Phone.
//              Name and phone number stored, and each Contact contains a list of messages as well.

#ifndef CONTACT_CPP
#define CONTACT_CPP

#include "Contact.h"

// Constructors
Contact::Contact() {
	contactName = "Default";
	contactNum = "000-000-0000";
}

Contact::Contact(string nameEntered, string numberEntered) {
	contactName = nameEntered;
	contactNum = numberEntered;
}

// Accessors
string Contact::getName() const {
	return contactName;
}

string Contact::getPhoneNum() const {
	return contactNum;
}

// Mutators
void Contact::set(string name, string num) {
	contactName = name;
	contactNum = num;
}

// Sends a message to a Contact
bool Contact::messageContact(string source) {
	string msg;

	cout << "Enter your message: ";
	getline(cin, msg);

	messages.addMsg(source, contactName, msg);
	messages.outputMessages();

	return true;
}

// Overloaded < operator for selection sort, based on ASCII value
bool operator<(const Contact &contact1, const Contact &contact2) {
	return contact1.getName() < contact2.getName();
}

#endif