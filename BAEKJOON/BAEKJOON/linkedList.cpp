#pragma once

#include <iostream>
#include "linkedList.h"

void linkedList::insert(int data) {
	Node* ptr;
	Node* newNode = nullptr;
	newNode = (Node*)malloc(sizeof(Node));

	if (newNode == NULL) {
		free(newNode);
		std::cout << "메모리 확보 실패" << std::endl;
		return;
	}

	newNode->data = data;
	newNode->next = nullptr;

	if (head == nullptr) {
		head = newNode;
	}
	else {
		// changing head data, ascending order
		if (head->data > newNode->data) {
			newNode->next = head;
			head = newNode;
			return;
		}

		for (ptr = head; ptr->next; ptr = ptr->next) {
			if (ptr->data < newNode->data && ptr->next->data > newNode->data) {
				newNode->next = ptr->next;
				ptr->next = newNode;
				return;
			}
		}

		ptr->next = newNode;
	}
}

bool linkedList::searching(int data)
{
	Node* ptr = nullptr;

	for (ptr = head; ptr->next; ptr = ptr->next) {
		if (ptr->data == data) {
			return true;
		}
	}

	return false;
}

bool linkedList::deleteData(int data)
{
	Node* prev = head;
	Node* cur = head;

	if (head == nullptr) {
		std::cout << "This Linkedlist is Empty!" << std::endl;
		return false;
	}

	if (head->data == data) {
		head = cur->next;
		cur->next = nullptr;
		free(cur);
		return true;
	}

	for (; cur->next; cur = cur->next) {
		if (cur->data == data) {
			prev->next = cur->next;
			cur->next = nullptr;
			free(cur);
			return true;
		}

		prev = cur;
	}

	return false;
}

void linkedList::printList() {
	Node* ptr;

	for (ptr = head; ptr->next; ptr = ptr->next) {
		std::cout << ptr->data << " -> ";
	}

	std::cout << ptr->data;
}
