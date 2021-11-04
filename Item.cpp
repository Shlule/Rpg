#include "Item.h"
#include<iostream>

using namespace std;

//contrustor and destructor

Item::Item() {

}

Item::Item(std::string name, int price, bool stackable, bool sellable,int weight ) {
	mName = name;
	mPrice = price;
	mWeight = weight;
	mSellable = sellable;
	mStackable = stackable;
}

Item::~Item() { }

// Getter

string Item::GetName() {
	return mName;
}

string Item::GetDescription() {
	return mDescription;
}

int Item::GetPrice() {
	return mPrice;
}

float Item::GetWeight() {
	return mWeight;
}

bool Item::IsSellable() {
	return mSellable;
}

bool Item::IsStackable() {
	return mSellable;
}

// testing function

// permet d'afficher le nom de l'item
void Item::InfoItem() {
	cout << mName;
}
