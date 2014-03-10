#include <iostream>
using namespace std;

#include "List.h"

List::List() :
		head(0) {
}

List::~List() {
	Node *currNode, *nextNode;

	currNode = head;

	while (currNode != 0) {
		nextNode = currNode->next;
		delete currNode;
		currNode = nextNode;
	}
}

List::List(List& list) : head(list.head) {

}

// Adds a student to the front of the list

void List::addFront(Student* newStu) {
	Node* tmpNode = new Node(newStu, head);
	head = tmpNode;
}

// Adds a student in alphabetical order

void List::addAlpha(Student* newStu) {
	Node* tmpNode = new Node(newStu, 0);

	Node *currNode = 0, *prevNode = 0;

	currNode = head;

//  while (currNode->next != 0) {
	while (currNode != 0) {
		if (currNode->data->getName() > tmpNode->data->getName())
			break;
		prevNode = currNode;
		currNode = currNode->next;
	}

	if (prevNode == 0) {
		head = tmpNode;
	} else {
		prevNode->next = tmpNode;
	}
	tmpNode->next = currNode;
}

void List::print() const {
	Node* currNode = head;

	while (currNode != 0) {
		currNode->data->print();
		currNode = currNode->next;
	}

}

