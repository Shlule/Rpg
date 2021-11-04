#pragma once
#include"Item.h"
#include"Dice.h"
#include"Enums.h"
#include<map>
#include<string>
// le faire avec des tags




class Supply : public Item
{
public:
	// constructor and destructor
	Supply(std::string name, int price,uint8_t  effects, int weight=0);
	~Supply();
	std::map<SupplyEffect,int> GetSupplyEffect();
	int SupplyHeal(int dicecount, int diceFaces);
	int ResolutionSupplyEffect(SupplyEffect supplyEffect);
	void SetEffect(std::uint8_t effect);
	std::uint8_t GetEffect();

private:
	std::uint8_t mSupplyEffects;
	std::map<SupplyEffect, int> mSupplyEffect;

};

