#pragma once
#include "Unit.h"

enum class mercantType {
	DRUGSTORE,ARMURIER,FORGERON
};

class Mercant:public Unit{

	
	// variable independante a la classe Mercant

private:
	// varible represnetant le coeficient auxquelle il rachete un objet si il est egal a 80 il achete a 80% de sa valeur
	float coefTrade = 20;

public:

	float GetCoefTrade();

	// constructor and destructor
	Mercant();
	Mercant(std::string name, int maxHp, int maxMp, int str, int dex, int cons, int intel, int wis, int cha, std::uint8_t unitType);
	~Mercant();

	void SellItem(Unit& buyer, Supply item);
	void BuyItem(Unit& Seller, Supply item);

};

