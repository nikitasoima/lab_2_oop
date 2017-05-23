// Lab_2_OOP.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


// Lab2_oop.cpp: определяет точку входа для консольного приложения.
//

#include "Container.h"
#include "PushPopContainer.h"
#include "IndexedContainer.h"
#include "InsertableContainer.h"
#include "Deque.h"
#include "Stack.h"
#include "Queue.h"
#include "StaticDeque.h"
#include "StaticDeque.h"
#include "LinkedList.h"
#include "StaticArray.h"
#include <iostream>
#include <conio.h>
using namespace std;

const int countElements = 12;
const int countPopping = 4;
const int countPushFront = 5;

int main()
{
	setlocale(LC_ALL, "Russian");
	PushPopContainer **arr1 = new PushPopContainer*[3];
	IndexedContainer **arr2 = new IndexedContainer*[2];
	Deque **arr3 = new Deque*[3];

	arr1[0] = new Stack();
	arr1[1] = new Queue();
	arr1[2] = new LinkedList();

	arr2[0] = new StaticArray(100);
	arr2[1] = new LinkedList();

	arr3[0] = new StaticDeque();
	arr3[1] = new LinkedList();

	for (int i = 1; i <= countElements; i++) {
	arr1[0]->push(i);
	arr1[1]->push(i);
	arr1[2]->push(i);
	}

	cout << arr1[0]->toString() << endl;
	cout << arr1[1]->toString() << endl;
	cout << arr1[2]->toString() << endl;

	cout << "Извлечение первых n элементов, n = " << countPopping << endl;

	for (int i = 0; i < countPopping; i++) {
	
	cout << "Извлечение со стэка: " << arr1[0]->pop() << endl;
	cout << "Извлечение из очереди: " << arr1[1]->pop() << endl;
	cout << "Извлечение из связанного списка: " << arr1[2]->pop() << endl << endl;
	}

	cout << "После извлечния: " << endl;

	cout << arr1[0]->toString() << endl;
	cout << arr1[1]->toString() << endl;
	cout << arr1[2]->toString() << endl;

	for (int i = 1; i <= countElements; i++) {
	arr2[0]->set(i - 1, i);
	arr2[1]->set(i - 1, i);
	}

	cout << arr2[0]->toString() << endl;
	cout << arr2[1]->toString() << endl;

	cout << "Введите индекс элемента:" << endl;
	int index = 0;
	cin >> index;

	cout << "Элемент" << index << " со статического массива = " << arr2[0]->get(index) << endl;
	cout << "Элемент" << index << " со связанного списка = " << arr2[1]->get(index) << endl;

	for (int i = 0; i < countElements; i++) {
	arr3[0]->pushBack(i);
	arr3[1]->pushBack(i);
	}

	cout << arr3[0]->toString() << endl;
	cout << arr3[1]->toString() << endl;

	cout << "Добавление спереди: " << endl;

	for (int i = 0; i < countPushFront; i++) {
	arr3[0]->pushFront(countElements + i);
	arr3[1]->pushFront(countElements + i);
	}

	cout << "После добавления:" << endl;

	cout << arr3[0]->toString() << endl;
	cout << arr3[1]->toString() << endl;

	cout << "Извлечение с конца: " << endl;

	for (int i = 0; i < countPopping; i++) {
	cout << "Извлечние со статического массива = " << arr3[0]->popBack() << endl;
	cout << "Извлечение со связанного списка = " << arr3[1]->popBack() << endl;
	}

	cout << "После извлечения: " << endl;

	cout << arr3[0]->toString() << endl;
	cout << arr3[1]->toString() << endl;
	
	_getch();

	return 0;
}
