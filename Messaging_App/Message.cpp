// Kevin Wallace
// Message implementation file
// 4/23/18
// Message.cpp
// Description: The Message class contains the message to be sent, as well as data about
//              who send and recieved the message. Messages are stored in a linked list implementated as a queue.
#ifndef MESSAGE_CPP
#define MESSAGE_CPP

#include "Message.h"
// Constructor
template<class T>
Message<T>::Message() {
	firstP = NULL; // message list empty to start
	lastP = NULL;
	capacity = 100;
	messagesStored = 0;
}

// Copy constructor
template<class T>
Message<T>::Message(const Message &otherMessage) {
	//// Copy non dynamic members
	//capacity = otherMessage.capacity;
	//messagesStored = otherMessage.messagesStored;
	//firstP = NULL;
	//lastP = NULL;

	//for (Node<T> *traverseP = otherMessage.firstP; traverseP != NULL; traverseP = traverseP->nextP) {
	//	// Allocate new node and store data.
	//	Node<T> *newNodeP = new Node<T>;
	//	newNodeP->messageContent = firstP->messageContent;
	//	newNodeP->sender = firstP->sender;
	//	newNodeP->recipient = firstP->recipient;

	//	// Add node into list.
	//	newNodeP->nextP = firstP;
	//	firstP = newNodeP;
	//}
}

// Assignment Operator
template<class T>
Message<T> &Message<T>::operator=(const Message &otherMessage) {
	//if (this != &otherMessage) {
	//	// Copy non dynamic members
	//	capacity = otherMessage.capacity;
	//	messagesStored = otherMessage.messagesStored;
	//	firstP = NULL;
	//	lastP = NULL;

	//	for (Node<T> *traverseP = otherMessage.firstP; traverseP != NULL; traverseP = traverseP->nextP) {
	//		// Allocate new node and store data.
	//		Node<T> *newNodeP = new Node<T>;
	//		newNodeP->messageContent = firstP->messageContent;
	//		newNodeP->sender = firstP->sender;
	//		newNodeP->recipient = firstP->recipient;

	//		// Add node into list.
	//		newNodeP->nextP = firstP;
	//		firstP = newNodeP;
	//	}
	//}

	return *this;
}

// Destructor
template<class T>
Message<T>::~Message() {
	while (firstP != NULL) {
		Node<T> *deleteP = firstP;
		firstP = firstP->nextP;
		delete deleteP;
	}
}

template<class T>
void Message<T>::outputMessages() const {
	for (Node<T> *traverseP = firstP; traverseP != NULL; traverseP = traverseP->nextP)
		cout << endl << "FROM: " << traverseP->sender << endl
		<< "TO: " << traverseP->recipient << endl
		<< "Message: " << traverseP->messageContent << endl << endl;
}

// Adds a message to the list
template<class T>
bool Message<T>::addMsg(string sender, string recipient, T msg) {
	// Allocate new node
	Node<T> *newNodeP = new Node<T>;
	// Fill data in node
	newNodeP->sender = sender;
	newNodeP->recipient = recipient;
	newNodeP->messageContent = msg;

	// New node added to end of list, so nextP is null
	newNodeP->nextP = NULL;

	if (isEmpty()) { // If creating a new list, newNode is first and last nodes
		firstP = newNodeP;
		lastP = newNodeP;
	}
	else {
		lastP->nextP = newNodeP;
		lastP = newNodeP;
	}

	if (isFull())
		delMsg(); // if at capacity, delete oldest message when adding
	else
		messagesStored++;

	return true; // Message will always be added to list, others deleted if over capacity
}

// Delete a message from the list
// Called when messagesStored at capacity
template<class T>
void Message<T>::delMsg() {
	if (isEmpty()) // nothing to delete
		return;

	Node<T> *deleteP = firstP;
	firstP = firstP->nextP;
	delete deleteP;
}

// Returns true if message queue is empty
template<class T>
bool Message<T>::isEmpty() {
	if (firstP == NULL)
		return true;

	return false;
}

// Returns true if message queue is full
template<class T>
bool Message<T>::isFull() {
	if (messagesStored == capacity)
		return true;

	return false;
}

#endif