/*
 * ListNode.h
 *
 *  Created on: Feb 18, 2014
 *      Author: jon
 */

#ifndef LISTNODE_H_
#define LISTNODE_H_

template<class T>

class ListNode {

public:
	ListNode(T* element, ListNode<T>* prev, ListNode<T>* next) :
			element(element), prev(prev), next(next) {
	}

	~ListNode() {
	}

	T* getElement() {
		return element;
	}

	T* setElement(T* newElement) {
		T* oldElement = element;
		element = newElement;

		return oldElement;
	}

	ListNode<T>* getNext() {
		return next;
	}

	void setNext(ListNode<T>* next) {
		this->next = next;
	}

	ListNode<T>* getPrev() {
		return prev;
	}

	void setPrev(ListNode<T>* prev) {
		this->prev = prev;
	}

private:
	T* element;
	ListNode<T>* prev;
	ListNode<T>* next;
};

#endif /* LISTNODE_H_ */
