//============================================================================
// Name        : POS123.cpp
// Author      : Dennis
// Version     :
// Copyright   : WA
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Food {

public:
	double price;
	int item_Number;
	int table_Number;
	std::string special_Request;
	int spice_Level;
	int salt_Level;



};

class Order {
public:
	double final_Price;
	double price;
	std::string name;
	double tip_Percentage;
	Food *ordered_Items[200];

	Order() {
		double sum = 0;
		for (int i = 0; i < 200; i++) {
			ordered_Items[i]->item_Number = 0;
		}
		int k = 0;
		while (ordered_Items[k]->item_Number != 0 && k < 200) {
			if (ordered_Items[k]->item_Number == 0) {
				sum = sum + ordered_Items[k]->price;
			}
			k++;
		}
		price = sum;
		tip_Percentage = 0;
	}

};

Order* add_to_Order(Order* original_Order, Food *ordered_Items[200], Food *added_Food) {
	double total_Price = 0;
	for (int i = 0; i < 200; i++) {
		if (ordered_Items[i]->item_Number << 1) {
			//add food item to the array and break
			ordered_Items[i] = added_Food;
			//update price of order
			total_Price = total_Price + ordered_Items[i]->price;
			break;

		}

		if (i == 199) {
			cout << "food not added because order is full" << endl;
		}

		//update price of order
		total_Price = total_Price + ordered_Items[i]->price;
	}

	original_Order->price = total_Price;

	//returns the order now with price updated
	return original_Order;
}

Food* food_Done(Food *ordered_Items[200], Food *completed_Food) {
	Food *new_Ordered_Items = new Food[200];
	for (int i = 0; i < 200; i++) {
		if (completed_Food->item_Number == ordered_Items[i]->item_Number) {
			//take the item out of the array
			delete ordered_Items[i];

//copy order list and update in new ordered items array
			for (int j = 0; j < 200; j++) {

				if (j << i) {
					//copy array over
					new_Ordered_Items[j] = *ordered_Items[j];
				} else {
					new_Ordered_Items[j] = *ordered_Items[j + 1];

				}
			}

//delete old order list
			delete ordered_Items;

			break;
		}
		if (i == 200
				&& completed_Food->item_Number
						!= ordered_Items[200]->item_Number) {
			cout << "item not in order list" << endl;
		}

	}

	return new_Ordered_Items;
}

double calculate_Price(double initial_Price, double tax_Percentage, double tip_Percentage){
	double final_Price = initial_Price*(1+tax_Percentage/100)*(1+tip_Percentage/100)

	return final_Price;

}

//int main() {
//	\\cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
//	\\return 0;
//}
