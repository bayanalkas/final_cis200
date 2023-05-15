#pragma once

#ifndef SHOPINFO_H
#define SHOPINFO_H

#include <iostream>
#include <string>
using namespace std;

template<typename Type>
struct itemNode {
	Type shopInfo;
	itemNode<Type>* next = NULL;
	itemNode<Type>* prev = NULL;
};

template<typename Type>
class shopInfo {
public:
	shopInfo();
	~shopInfo();

	bool isItemAvailable(const Type& searchItem);
	itemNode<Type>* findItem(const Type& searchItem);

	void insertItemEnd(const Type& listItem);
	void insertItemStart(const Type& listItem);
	void insertItemAfter(itemNode<Type>* prevItem, const Type& listItem);
	void returnItems(const Type& listItem, const Type& itemToReturn);

	void moveItemEnd(const Type& listItem);
	void moveItemStart(const Type& listItem);
	void moveItemAfter(itemNode<Type>* prevItem, const Type& listItem);
	
	void removeItem(const Type& itemToRemove);
	void checkoutItems(const Type& listItem, const Type& amountBought);

	void print();
	void printItem(const Type& listItem);

	void sort();

private:
	int count;
	itemNode<Type>* first;
	itemNode<Type>* last;
	itemNode<Type>* current;
};

template<typename Type>
shopInfo<Type>::shopInfo() {
	first = nullptr;
	last = nullptr;
	count = 0;
}

template<typename Type>
shopInfo<Type>::~shopInfo() {
	while (first) {
		itemNode<Type>* next = first->next;
		delete first;
		first = next;
	}
}

template<typename Type>
bool shopInfo<Type>::isItemAvailable(const Type& searchItem) {
	bool found = false;

	current = first;
	while (current != nullptr && !found) {
		if (current->shopInfo == searchItem) {
			found = true;
		}
		else {
			current = current->next;
		}
	}

	if (found) {
		found = (current->shopInfo == searchItem);
	}

	return found;
}

template<typename Type>
itemNode<Type>* shopInfo<Type>::findItem(const Type& searchItem) {
	current = first;
	while (current != nullptr) {
		if (current->shopInfo == searchItem) {
			return current;
		}
		else {
			current = current->next;
		}
	}
	return nullptr;
}

template<typename Type>
void shopInfo<Type>::insertItemEnd(const Type& listItem) {
	itemNode<Type>* newItem;

	newItem = new itemNode<Type>;
	newItem->shopInfo = listItem;

	if (first == nullptr) {
		first = newItem;
		last = newItem;
		count++;
	}
	else {
		last->next = newItem;
		newItem->prev = last;
		last = newItem;
		count++;
	}
}

template<typename Type>
void shopInfo<Type>::insertItemStart(const Type& listItem) {
	itemNode<Type>* newItem;

	newItem = new itemNode<Type>;
	newItem->shopInfo = listItem;

	if (first == nullptr) {
		first = newItem;
		last = newItem;
		count++;
	}
	else {
		newItem->next = first;
		first->prev = newItem;
		first = newItem;
		count++;
	}
}

template<typename Type>
void shopInfo<Type>::insertItemAfter(itemNode<Type>* prevItem, const Type& listItem) {
	itemNode<Type>* newItem;

	newItem = new itemNode<Type>;
	newItem->shopInfo = listItem;

	newItem->next = prevItem->next;
	prevItem->next = newItem;
	newItem->prev = prevItem;

	if (newItem->next != nullptr) {
		newItem->next->prev = newItem;
	}

	count++;
}

template<typename Type>
void shopInfo<Type>::returnItems(const Type& listItem, const Type& amountToReturn) {
	current = findItem(listItem);
	current->shopInfo += amountToReturn;
}

template<typename Type>
void shopInfo<Type>::moveItemEnd(const Type& listItem) {
	itemNode<Type>* newItem;

	newItem = new itemNode<Type>;
	newItem->shopInfo = listItem;

	if (first == nullptr) {
		first = newItem;
		last = newItem;
	}
	else {
		last->next = newItem;
		newItem->prev = last;
		last = newItem;
	}
}

template<typename Type>
void shopInfo<Type>::moveItemStart(const Type& listItem) {
	itemNode<Type>* newItem;

	newItem = new itemNode<Type>;
	newItem->shopInfo = listItem;

	if (first == nullptr) {
		first = newItem;
		last = newItem;
	}
	else {
		newItem->next = first;
		first->prev = newItem;
		first = newItem;
	}
}

template<typename Type>
void shopInfo<Type>::moveItemAfter(itemNode<Type>* prevItem, const Type& listItem) {
	itemNode<Type>* newItem;

	newItem = new itemNode<Type>;
	newItem->shopInfo = listItem;

	newItem->next = prevItem->next;
	prevItem->next = newItem;
	newItem->prev = prevItem;

	if (newItem->next != nullptr) {
		newItem->next->prev = newItem;
	}
}

template<typename Type>
void shopInfo<Type>::removeItem(const Type& itemToRemove) {
	itemNode<Type>* nextItem;
	itemNode<Type>* prevItem;

	nextItem = new itemNode<Type>;
	nextItem = current->next;

	prevItem = new itemNode<Type>;
	prevItem = current->prev;

	current = new itemNode<Type>;
	current->shopInfo = itemToRemove;

	if (nextItem != nullptr) {
		nextItem->prev = prevItem;
	}

	if (prevItem != nullptr) {
		prevItem->next = nextItem;
	}

	if (current == first) {
		first = nextItem;
	}

	if (current == last) {
		last = prevItem;
	}

	count--;
}

template<typename Type>
void shopInfo<Type>::checkoutItems(const Type& listItem, const Type& amountBought) {
	current = findItem(listItem);

	if (amountBought < current->shopInfo) {
		current->shopInfo -= amountBought;
	}
}

template<typename Type>
void shopInfo<Type>::print() {
	string todaysDate;
	string todaysTime;

	current = first;
	cout << "Enter today's date: ";
	cin >> todaysDate;
	cout << "Enter the time: ";
	getline(cin, todaysTime);
	getline(cin, todaysTime);

	while (current != nullptr) {
		cout << "Item: " << current->shopInfo << endl;
		cout << "-------------------------------------------" << endl;
		current = current->next;
	}

	cout << "Amount total: " << count << endl;
	cout << "Today's date: " << todaysDate << endl;
	cout << "Time: " << todaysTime << endl;
	cout << "***************************************************" << endl;
}

template<typename Type>
void shopInfo<Type>::printItem(const Type& listItem) {
	current = findItem(listItem);
	cout << current->shopInfo << endl;
}

template<typename Type>
void shopInfo<Type>::sort() {
	current = first->next;
	itemNode<Type>* prevItem;
	itemNode<Type>* nextItem;

	prevItem = new itemNode<Type>;
	nextItem = new itemNode<Type>;

	while (current != nullptr) {
		nextItem = current->next;
		prevItem = current->prev;

		while (prevItem != nullptr && prevItem->shopInfo > current->shopInfo) {
			prevItem = prevItem->prev;
		}

		removeItem(current->shopInfo);
		count++;

		if (prevItem == nullptr) {
			current->prev = nullptr;
			moveItemStart(current->shopInfo);
		}
		else {
			moveItemAfter(prevItem, current->shopInfo);
		}

		current = nextItem;
	}
}

#endif 
