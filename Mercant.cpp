#include "Mercant.h"
#include <iostream>
using namespace std;

// constructor and Destructor


Mercant::Mercant(string name, int maxHp, int str, int dex, int cons, int intel, int wis, int cha):Unit( name, maxHp, str, dex, cons, intel, wis, cha) {

}
Mercant::Mercant() {}
Mercant::~Mercant() {}

// le marcahnt qui vend un item
void Mercant::SellItem(Unit& buyer, Item item)
{
	float mercantPrice = item.GetPrice() + (item.GetPrice() * (coefTrade / 100));

	if (buyer.GetBourse() < mercantPrice) {
		cout << "vous n'avez pas assez d'argent" << endl;
	}
	else {
		buyer.RemoveMoney(mercantPrice);
		buyer.AddItem(item);
		AddMoney(mercantPrice);
		RemoveItem(item.GetName());
	}
	
}
void Mercant::BuyItem(Unit& seller, Item item) {
	float mercantPrice = item.GetPrice() - (item.GetPrice() * (coefTrade / 100));

	if (GetBourse() < mercantPrice) {
		cout << "je suis desole je ne peux pas vous l'acheter" << endl;
	}
	else {
		AddItem(item);
		RemoveMoney(mercantPrice);
		seller.RemoveItem(item.GetName());
		seller.AddMoney(mercantPrice);

	}

}

float Mercant::GetCoefTrade() {
	return coefTrade;
	
}