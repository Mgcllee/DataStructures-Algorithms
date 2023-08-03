#pragma once

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
class linkedList {
private:
	typedef struct _Node {
		int data;
		struct _Node* next;
	} Node;

public:
	Node* head;

	void insert(int data);
	bool searching(int data);
	bool deleteData(int data);
	void printList();
};
#endif LINKEDLIST_H