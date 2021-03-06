/*
 * List.h
 *
 *  Created on: Feb 16, 2014
 *      Author: jon
 *
 *  List class, stores anything.
 *  Created this templated List class since Assignment 3. Previously this list
 *  has been used to store non-pointer types. It still works perfectly fine with
 *  pointers even though some of the code takes pointer references.
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
//		ListNode<T>* node = head;
//		ListNode<T>* next;
//		while (node != null) {
//			next = node->getNext();
////			T* element = node->getElement();
////				delete &element;
////			delete &node->getElement();
//			delete node;
//			node = next;
//		}

	}

	/**
	 * Adds specified element to the end of the list.
	 * @param element
	 * @return
	 */
	bool add(const T& element) {

		T* item = new T(element);

		if (size == 0) { // if empty list
			ListNode<T>* node = new ListNode<T>(item, null, null);
			head = node;
			tail = node;

		} else if (size > 0) { // if elements in list already
			ListNode<T>* node = new ListNode<T>(item, tail, null);
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
			add(*n->getElement());
			n = n->getNext();
		}
	}

	// TODO: Remove this method!
	T& remove(int index) {
		// check if trying to access index that doesn't exist
		if (index >= size) {
			std::cerr << "Removing element index is out of bounds";
			throw "out of bounds!";
		}

		if (size == 1) { // remove element from list of 1
			ListNode<T>* node = head;
			T* element = node->getElement();
			head = null;
			tail = null;
			--size;
			delete node;
			return *element;

		} else if (index == 0) { // removing from head case
			ListNode<T>* node = head;
			T* element = node->getElement();
			head = node->getNext();
			delete node;
			head->setPrev(null);

			--size;
			return *element;

		} else if (index == size - 1) { // removing from tail case;
			ListNode<T>* node = tail;
			T* element = node->getElement();
			tail = tail->getPrev();
			tail->setNext(null);
			--size;
			delete node;
			return *element;
		} else {
			ListNode<T>* node = head;
			for (int j = 0; j < index; ++j) {
				node = node->getNext();
			}
			node->getPrev()->setNext(node->getNext());
			node->getNext()->setPrev(node->getPrev());

			T* element = node->getElement();
			--size;
			delete node;
			return *element;
		}
	}

	/**
	 * Search for element in list. If found call remove(int i) which removes the
	 * element at that index
	 * @param element
	 * @return If found: the element. If not found: Null
	 */
	void remove(T& element) {
		ListNode<T>* node = head;
		int i = 0;

		while (node != null) {
			if (*node->getElement() == element) { // TODO: check if valid, or dereference if not
				remove(i);
				return;
			}
			node = node->getNext();
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
			remove(*node->getElement());

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

			return *node->getElement();
		} else {
			throw "out of bounds!";
		}
	}

	List<T>& operator=(List<T>& list) {
		int size = list.getSize();
		for (int i = 0; i < size; ++i) {
			remove(0);
		}

		addAll(list);

		return this;
	}

	List<T>& operator+=(T& element) {
		add(element);
		return *this;
	}

	List<T>& operator+=(List<T>& list) {
		addAll(list);
		return *this;
	}

	List<T>& operator-=(T& element) {
		remove(element);
		return this;
	}

	List<T>& operator-=(List<T>& list) {
		removeAll(list);
		return *this;
	}

	List<T> operator+(T& element) {
		List<T> list;
		list.add(element);
		return list;
	}

	List<T> operator+(List<T>& element) {
		List<T> list;
		list.addAll(element);
		return list;
	}

	List<T> operator-(T& element) {
		List<T> list;
		list.remove(element);
		return list;
	}

	List<T> operator-(List<T>& element) {
		List<T> list;
		list.removeAll(element);
		return list;
	}

private:
	int size;
	ListNode<T>* head;
	ListNode<T>* tail;

};

#endif /* LIST_H_ */
