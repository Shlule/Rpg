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
	Supply(std::string name, int price,uint8_t  effects,int diceCount,int diceFaces, int weight=0);
	~Supply();
	int SupplyHeal(int diceCount, int diceFaces);
	int SupplyDamage(int diceCount, int diceFaces);
	void ResolutionSupplyEffect();
	void SetEffect(std::uint8_t effect);
	std::uint8_t GetEffect();
	void RemoveSupplyEffect();

private:
	int mDiceCount;
	int mDiceFaces;
	std::uint8_t mSupplyEffects;
	

};

