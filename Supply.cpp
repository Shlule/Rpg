#include "Supply.h"
#include<iostream>

using namespace std;

Supply::Supply(std::string name, int price, uint8_t effects , int diceCount, int diceFaces, int weight) : Item(name, price, true ,true ,weight) {

	mSupplyEffects = effects;
	mDiceCount = diceCount;
	mDiceFaces = diceFaces;
}
Supply::~Supply() {};



int Supply::ResolutionSupplyEffect(uint8_t effectSupply) {
	switch (effectSupply)
	{
	case EffectSupply::Heal:
		cout << "heal" << endl;
		return 0;
		break;
	case EffectSupply::MajorHeal:
		cout << "heal" << endl;
		return 1;
		break;
	case EffectSupply::Feed:
		cout << "heal" << endl;
		return 2;
		break;
	case EffectSupply::Buff:
		cout << "heal" << endl;
		break;
	case EffectSupply::Debuff:
		cout << "heal" << endl;
		return 3;
		break;
	case EffectSupply::Cure:
		cout << "heal" << endl;
		return 4;
		break;
	case EffectSupply::Arcana:
		cout << "heal" << endl;
		return 5;
		break;

	default:
		cout << "je ne marche pas" << endl;
		return 6;
		break;
	}
	
}



int Supply::SupplyHeal(int diceCount, int diceFace) {
	int totalHeal = 0;
	Dice tempDice(diceFace);
	for (int i = 0; i < diceCount; i++) {
		totalHeal += tempDice.roll();

	}
	return totalHeal;
}
int Supply::SupplyDamage(int diceCount, int diceFace) {
	int totalDamage = 0;
	Dice tempDice(diceFace);
	for (int i = 0; i < diceCount; i++) {
		totalDamage += tempDice.roll();
	}
	return totalDamage;
}
void Supply::SetEffect(uint8_t effect){
	mSupplyEffects = effect;

}
uint8_t Supply::GetEffect() {
	cout << (int)mSupplyEffects;
	return mSupplyEffects;
}