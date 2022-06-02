#include<iostream>
#include<list>
#include <iomanip>
using namespace std;

void printmenu() {
	cout << "1. Burger       $2.00  2. Milkshake $2.50\n";
	cout << "3. Cheeseburger $3.00  4. Chic Nugg $2.00\n";
	cout << "5. Fries        $1.00  6. Soda      $1.00\n";
}



int main()
{   
	int choise = 1;
	cout << "Welcome to Burger Place!\nplease place your order\n\n";
	list<string> choiseitems = {};
	list<float> cost = {};
	list<string> recipt = {};

	while (choise != 6) {
		cout << "1. View Menue\n2. Add Items\n3. View Basket\n4. Check Out\n5. Exit\nChoise: ";
		cin >> choise;
		cout << "\n";

		if (choise == 1) { // View Menue
			cout << "-----------------------------------------\n";
			printmenu();
			cout << "-----------------------------------------\n";
			cout << "\n";
		}
		else if (choise == 2) { // Add Items
			int menuitem = 0;
			while (menuitem != 8) {
				for (string item : choiseitems) { // for item in list
					cout << item << " "; // print item
				}
				cout << "\n\n";
				printmenu();
				cout << "7. Remove Last Item    8. Exit\n";
				cout << "Pick an item: ";
				cin >> menuitem;
				if (menuitem == 1) {
					choiseitems.push_back("Burger");
					recipt.push_back("$2.00 Burger");
					cost.push_back(2.00);
				}
				else if (menuitem == 2) {
					choiseitems.push_back("Milkshake");
					recipt.push_back("$2.50 Milkshake");
					cost.push_back(2.50);
				}
				else if (menuitem == 3) {
					choiseitems.push_back("Cheeseburger");
					recipt.push_back("$3.00 Cheeseburger");
					cost.push_back(3.00);
				}
				else if (menuitem == 4) {
					choiseitems.push_back("Chic Nugg");
					recipt.push_back("$2.00 Chic Nugg");
					cost.push_back(2.00);
				}
				else if (menuitem == 5) {
					choiseitems.push_back("Fries");
					recipt.push_back("$1.00 Fries");
					cost.push_back(1.00);
				}
				else if (menuitem == 6) {
					choiseitems.push_back("Soda");
					recipt.push_back("$1.00 Soda");
					cost.push_back(1.00);
				}
				else if (menuitem == 7) {
					choiseitems.pop_back(); // using on empty list crashes it
					recipt.pop_back();
					cost.pop_back();
				}
				else if (choise > 8 or choise < 1) {
					cout << "Invalid Selection";
				}
				cout << "\n\n";
			}
			
		}
		else if (choise == 3) { // View Basket
			//print chosen items and their cost
			for (string item : recipt) { // for item in list
				cout << item << "\n"; // print item
			}
			cout << "\n";
		}
		else if (choise == 4) { //Check Out
			cout << "-----Recipt-----\n";
			for (string item : recipt) { // for item in list
				cout << item << "\n"; // print item
			}
			float total = 0.00;
			for (float item : cost) {
				total += item;
			}
			cout << "Total: ";
			cout << fixed << setprecision(2) << total << "\n";
			cout << "----------------\n";
			cout << "\n";
			break;
		}
		else if (choise > 6 or choise < 1) {
			cout << "Invalid Selection\n";
		}
	}
}
