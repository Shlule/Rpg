#pragma once
#include<iostream>


class Item
{
private:
	std::string mName;
	std::string mDescription;
	int mPrice;
	float mWeight;
	bool mStackable;
	bool mSellable;


public:
	// constructor , destructor
	Item();
	Item(std::string name, int price, bool stackable, bool sellable ,int weight=0);
	~Item();

	// getter
	//virtual void Drop()=0;
	float GetWeight();
	int GetPrice();
	std::string GetName();
	std::string GetDescription();
	bool IsStackable();
	bool IsSellable();

	//testing fonction

	void InfoItem();


	// pas de setter car on ne peux pas changer un objet on a pas de mechanic  de durabilite





};

