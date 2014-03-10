#ifndef LIST_H
#define LIST_H

#include "Student.h"

class List {
	class Node {
		friend class List;
	public:
		Node(Student* stu, Node* node) : data(stu), next(node) {}
	private:
		Student* data;
		Node* next;
	};

public:
	List();
	~List();
	List(List&);
	void addFront(Student*);
	void addAlpha(Student*);
	void print() const;


private:
	Node* head;
};

#endif
