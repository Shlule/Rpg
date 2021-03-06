#include "Mercant.h"
#include <iostream>
using namespace std;

// constructor and Destructor


Mercant::Mercant(string name, int maxHp,int maxMp ,int str, int dex, int cons, int intel, int wis, int cha ,uint8_t unitType):Unit( name, maxHp,maxMp, str, dex, cons, intel, wis, cha,unitType) {

}
Mercant::Mercant() {}
Mercant::~Mercant() {}

// le marcahnt qui vend un item
void Mercant::SellItem(Unit& buyer, Supply item)
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
void Mercant::BuyItem(Unit& seller, Supply item) {
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