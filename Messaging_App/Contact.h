// Kevin Wallace
// Contact Interface file
// 4/23/18
// Contact.h
// Description: The Contact class contains data about a Contact which is stored in a Phone.
//              Name and phone number stored, and each Contact contains a list of messages as well.

#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>
#include "Message.cpp"
using namespace std;

class Contact {
public:
	// Constructors
	Contact();
	Contact(string name, string num);

	// Accessors
	string getName() const;
	string getPhoneNum() const;

	// Mutators
	void set(string name, string num);

	// Sends a message to a Contact
	bool messageContact(string source);

private:
	string contactNum;
	string contactName;
	Message<string> messages; //linked list of messages
};

// Overloaded < operator for selection sort, based on ASCII value
bool operator<(const Contact &contact1, const Contact &contact2);

#endif