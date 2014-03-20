/*
 * List.h
 *
 *  Created on: Feb 16, 2014
 *      Author: jon
 */

#ifndef LIST_H_
#define LIST_H_

#include "ListNode.h"
#include <iostream>

#ifndef null
#define null 0
#endif // #ifndef NULL

template<class T>

class List {
public:
	List() {
		size = 0;
		head = null;
		tail = null;
	}

	virtual ~List() {
		ListNode<T>* node = head;
		ListNode<T>* next;
		while (node != null) {
			next = node->getNext();
			delete &node->getElement();
			delete node;
			node = next;
		}
	}

	/**
	 * Adds specified element to the end of the list.
	 * @param element
	 * @return
	 */
	bool add(const T& element) {

		T* item = new T(element);

		if (size == 0) { // if empty list
			ListNode<T>* node = new ListNode<T>(*item, null, null);
			head = node;
			tail = node;

		} else if (size > 0) { // if elements in list already
			ListNode<T>* node = new ListNode<T>(*item, tail, null);
			tail->setNext(node);
			tail = node;

		} else { // if somehow not able to add element
			std::cerr << "List::add() Error adding an element to the List\n";
			return false;
		}

		// if add was successful, increment size of list
		++size;
		return true;
	}
	void addAll(List<T>& list) {

		ListNode<T>* n = list.head;

		while (n != null) {
			add(n->getElement());
			n = n->getNext();
		}
	}

	// TODO: Remove this method!
	T& remove(int index) {
		// check if trying to access index that doesn't exist
		if (index >= size) {
			throw "out of bounds!";
		}

		if (size == 1) { // remove element from list of 1
			ListNode<T>* node = head;
			T& element = node->getElement();
			head = null;
			tail = null;
			delete node;
			return element;

		} else if (index == 0) { // removing from head case
			ListNode<T>* node = head;
			T& element = node->getElement();
			head = node->getNext();
			delete node;
			head->setPrev(null);

			--size;
			return element;

		} else if (index == size - 1) { // removing from tail case;
			ListNode<T>* node = tail;
			T& element = node->getElement();
			tail = tail->getPrev();
			tail->setNext(null);
			delete node;
			return element;
		} else {
			ListNode<T>* node = head;
			for (int j = 0; j < index; ++j) {
				node = node->getNext();
			}
			node->getPrev()->setNext(node->getNext());
			node->getNext()->setPrev(node->getPrev());

			T& element = node->getElement();
			delete node;
			return element;
		}
	}

	/**
	 * Search for element in list. If found call remove(int i) which removes the
	 * element at that index
	 * @param element
	 * @return If found: the element. If not found: Null
	 */
	void remove(const T& element) {
		ListNode<T>* node = head;
		int i = 0;

		while (node != null) {
			if (node->getElement() == element) { // TODO: check if valid, or dereference if not
				remove(i);
				return;
			}
			++i;
		}

//		while (node != NULL) {
//			if (*(node->element) == *element) {
//				// found the element
//				if (head == element) {
//					head = head->next;
//				} else {
//					node->prev->next = node->next;
//				}
//				if (tail == element) {
//					tail = tail->prev;
//				} else {
//					node->next->prev = node->prev;
//				}
//
//				delete node->element;
//				delete node;
//				return;
//
//			}
//		}
	}
	void removeAll(List<T>& list) {
		ListNode<T>* node = list.head;

		while (node != null) {
			remove(node->getElement());

			node = node->getNext();
		}
	}

	int getSize() {
		return size;
	}
//	bool contains(T* element);

	T& get(int index) {

		if (index < size) {

			ListNode<T>* node = head;
			for (int i = 0; i < index; ++i) {
				node = node->getNext();
			}

			return node->getElement();
		} else {
			throw "out of bounds!";
		}
	}

	T& set(int index, const T& element) {
		if (index >= size) {
			throw "out of bounds!";
		}

		ListNode<T>* node = head;
		for (int i = 0; i < index; ++i) {
			node = node->getNext();
		}

		return node->setElement(element);
	}

private:
	int size;
	ListNode<T>* head;
	ListNode<T>* tail;

};

#endif /* LIST_H_ */
