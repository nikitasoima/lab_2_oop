#include "stdafx.h"
#include "Stack.h"
#include <string>


Stack::Stack()
{
	head = NULL;
	numberOfElements = 0;
}

int Stack::size() const {
	return numberOfElements;
}
bool Stack::isEmpty() const {
	return numberOfElements == 0;
}
char* Stack::toString() const {
	DataNode *currents = head;
	char *description = new char[256]{ NULL };

	strcat(description, "Стэк\nГолова: ");
	do {
		if (currents != head) {
			strcat(description, ", ");
		}
		char *val = new char[256]{ NULL };
		itoa(currents->value, val, 10);

		strcat(description, val);
		currents = currents->next;

		delete val;
	} while (currents != NULL);

	

	delete currents;

	return description;
}

int Stack::pop() {
	if (isEmpty()) throw "Стэк пуст!";

	int value = head->value;

	DataNode *popedElement = head;
	head = head->next;

	delete popedElement;

	numberOfElements -= 1;

	if (!isEmpty()) head->prev = NULL;

	return value;
}

bool Stack::push(int value) {
	DataNode *newNode = new DataNode();

	newNode->value = value;

	if (!isEmpty()) {
		newNode->next = head;
		head->prev = newNode;
	}

	head = newNode;

	numberOfElements += 1;

	return true;
}

int Stack::peek() const {
	if (isEmpty()) throw "Стэк пуст!";

	return head->value;
}

Stack::~Stack()
{
	DataNode *current;
	DataNode *next = head;

	while (next != NULL) {
		current = next;
		next = current->next;
		delete current;
	}

	delete next;
}
