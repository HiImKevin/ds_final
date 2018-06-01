// Kevin Wallace
// Message interface file
// 4/23/18
// Message.h
// Description: The Message class contains the message to be sent, as well as data about
//              who send and recieved the message. Messages are stored in a linked list implementated as a queue.

#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <iostream>
using namespace std;

// Each Node stores data about the message
template<class T>
struct Node {
	string sender;
	string recipient;
	T messageContent; // messageContent is a T because can potentionally send any type of message (string/file/maybe JSON object)
	Node *nextP;
};

template<class T>
class Message {
public:
	// Constructor
	Message();

	// Copy Constructor
	Message(const Message &otherMessage);

	// Assignment Operator
	Message &operator =(const Message &otherMessage);

	// Destructor
	~Message();

	void outputMessages() const;

	// Adds a message to the list
	bool addMsg(string sender, string recipient, T msg);

	// Delete a message from the list
	void delMsg();

	// Returns true if message queue is empty
	bool isEmpty();

	// Returns true is message queue is full
	bool isFull();

private:
	Node<T> *firstP;
	Node<T> *lastP;
	int capacity;
	int messagesStored;
};

#endif
