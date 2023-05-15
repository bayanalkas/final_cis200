#include "shopInfo.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	shopInfo<string> shoppingItem;
	shopInfo<float> itemPrice;
	shopInfo<int> itemAmount;
	shopInfo<string> customerNames;
	shopInfo<string> daysTimesVisited;
	shopInfo<string> itemsBought;
	shopInfo<float> moneySpent;

	cout << "LIST OF ITEMS:" << endl;
	shoppingItem.insertItemStart("Milk");
	shoppingItem.insertItemEnd("Eggs");
	shoppingItem.insertItemEnd("Apples");
	shoppingItem.insertItemEnd("Paneer");
	shoppingItem.insertItemAfter(shoppingItem.findItem("Paneer"), "Naan");
	shoppingItem.removeItem("Paneer");

	shoppingItem.sort();
	shoppingItem.print();

	cout << "LIST OF PRICES:" << endl;
	itemPrice.insertItemStart(2.31);
	itemPrice.insertItemEnd(8.99);
	itemPrice.insertItemEnd(3.45);
	itemPrice.insertItemEnd(5.99);
	itemPrice.insertItemAfter(itemPrice.findItem(5.99), 6.31);
	itemPrice.removeItem(5.99);

	itemPrice.sort();
	itemPrice.print();

	map<string, float> itemAndPrice;
	itemAndPrice.emplace("Apples", 2.31);
	cout << "Apples are $" << itemAndPrice.at("Apples") << endl;
	itemAndPrice.emplace("Eggs", 3.45);
	cout << "Eggs are $" << itemAndPrice.at("Eggs") << endl;
	itemAndPrice.emplace("Milk", 6.31);
	cout << "Milk is $" << itemAndPrice.at("Milk") << endl;
	itemAndPrice.emplace("Naan", 8.99);
	cout << "Naan is $" << itemAndPrice.at("Naan") << endl;

	cout << "LIST OF AMOUNTS:" << endl;
	itemAmount.insertItemStart(10);
	itemAmount.insertItemEnd(8);
	itemAmount.insertItemEnd(30);
	itemAmount.insertItemEnd(5);
	itemAmount.insertItemAfter(itemAmount.findItem(5), 15);
	itemAmount.removeItem(5);
	itemAmount.checkoutItems(30, 5);
	itemAmount.returnItems(25, 5);

	itemAmount.sort();
	itemAmount.print();

	map<string, int> itemAndAmount;
	itemAndAmount.emplace("Apples", 8);
	cout << "There are " << itemAndAmount.at("Apples") << " apples in stock." << endl;
	itemAndAmount.emplace("Eggs", 10);
	cout << "There are " << itemAndAmount.at("Eggs") << " eggs in stock." << endl;
	itemAndAmount.emplace("Milk", 15);
	cout << "There are " << itemAndAmount.at("Milk") << " cartons of milk in stock." << endl;
	itemAndAmount.emplace("Naan", 30);
	cout << "There are " << itemAndAmount.at("Naan") << " pieces of naan in stock." << endl;

	cout << "LIST OF CUSTOMERS:" << endl;
	customerNames.insertItemStart("Rhea");
	customerNames.insertItemEnd("Rhonda");
	customerNames.insertItemEnd("Byan");
	customerNames.insertItemEnd("Amal");
	customerNames.insertItemAfter(customerNames.findItem("Amal"), "Kareem");
	customerNames.removeItem("Amal");

	customerNames.sort();
	customerNames.print();

	cout << "LIST OF CUSTOMER VISITS:" << endl;
	daysTimesVisited.insertItemStart("3/26/2022, 4:30 PM");
	daysTimesVisited.insertItemEnd("2/15/2022, 2:45 PM");
	daysTimesVisited.insertItemEnd("1/5/2022, 10:00 AM");
	daysTimesVisited.insertItemEnd("4/10/2022, 1:00 PM");
	daysTimesVisited.insertItemAfter(daysTimesVisited.findItem("4/10/2022, 1:00 PM"), "3/31/2022, 2:00 PM");
	daysTimesVisited.removeItem("4/10/2022, 1:00 PM");

	daysTimesVisited.sort();
	daysTimesVisited.print();

	map<string, string> nameAndVisit;
	nameAndVisit.emplace("Byan", "1/5/2022, 10:00 AM");
	cout << "Byan visited the store on " << nameAndVisit.at("Byan") << endl;
	nameAndVisit.emplace("Kareem", "2/15/2022, 2:45 PM");
	cout << "Kareen visited the store on " << nameAndVisit.at("Kareem") << endl;
	nameAndVisit.emplace("Rhea", "3/26/2022, 4:30 PM");
	cout << "Rhea visited the store on " << nameAndVisit.at("Rhea") << endl;
	nameAndVisit.emplace("Rhonda", "3/31/2022, 2:00 PM");
	cout << "RHonda visited the store on " << nameAndVisit.at("Rhonda") << endl;

	cout << "LIST OF ITEMS BOUGHT:" << endl;
	itemsBought.insertItemStart("5 Apples");
	itemsBought.insertItemEnd("12 Eggs");
	itemsBought.insertItemEnd("7 Paneer");
	itemsBought.insertItemEnd("2 Milk");
	itemsBought.insertItemAfter(itemsBought.findItem("2 Milk"), "5 Naan");
	itemsBought.removeItem("2 Milk");

	itemsBought.sort();
	itemsBought.print();

	map<string, string> nameAndItems;
	nameAndItems.emplace("Byan", "5 Apples");
	cout << "Byan bought " << nameAndItems.at("Byan") << endl;
	nameAndItems.emplace("Kareem", "5 Naan");
	cout << "Kareem bought " << nameAndItems.at("Kareem") << endl;
	nameAndItems.emplace("Rhea", "7 Paneer");
	cout << "Rhea bought " << nameAndItems.at("Rhea") << endl;
	nameAndItems.emplace("Rhonda", "12 Eggs");
	cout << "Rhonda bought " << nameAndItems.at("Rhonda") << endl;

	cout << "LIST OF MONEY SPENT:" << endl;
	moneySpent.insertItemStart(5.45);
	moneySpent.insertItemEnd(10.01);
	moneySpent.insertItemEnd(6.33);
	moneySpent.insertItemEnd(12.99);
	moneySpent.insertItemAfter(moneySpent.findItem(12.99), 6.31);
	moneySpent.removeItem(12.99);

	moneySpent.sort();
	moneySpent.print();

	map<string, float> nameAndPayment;
	nameAndPayment.emplace("Byan", 5.45);
	cout << "Byan paid $" << nameAndPayment.at("Byan") << "total." << endl;
	nameAndPayment.emplace("Kareem", 6.31);
	cout << "Kareem paid $" << nameAndPayment.at("Kareem") << "total." << endl;
	nameAndPayment.emplace("Rhea", 6.33);
	cout << "Rhea paid $" << nameAndPayment.at("Rhea") << "total." << endl;
	nameAndPayment.emplace("Rhonda", 10.01);
	cout << "Rhonda paid $" << nameAndPayment.at("Rhonda") << "total." << endl;

	return 0;
}
