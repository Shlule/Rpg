#include "Supply.h"
#include<iostream>

using namespace std;

Supply::Supply(std::string name, int price, uint8_t effects , int diceCount, int diceFaces, int weight) : Item(name, price, true ,true ,weight) {

	mSupplyEffects = effects;
	mDiceCount = diceCount;
	mDiceFaces = diceFaces;
}
Supply::~Supply() {};


// si je veux plusieyrur tage pas possible de le faire dans un switch regarde diapo68 de New concept c++
void Supply::ResolutionSupplyEffect() {
	uint8_t effectSupply = GetEffect();
	while (effectSupply != 0) {
		if (effectSupply & EffectSupply::Heal) {
			cout << "Heal" << endl;
			effectSupply^= EffectSupply::Heal;

		}
		else if (effectSupply & EffectSupply::Cure) {
			cout << "Cure" << endl;
			effectSupply^= EffectSupply::Cure;
		}
		else if (effectSupply & EffectSupply::Buff)
		{
			cout << "Buff" << endl;
			effectSupply^= EffectSupply::Buff;
		}
		else if (effectSupply & EffectSupply::Debuff)
		{
			cout << "Debuff" << endl;
			effectSupply^= EffectSupply::Debuff;
		}
		else if (effectSupply & EffectSupply::Arcana)
		{
			cout << "Arcana" << endl;
			effectSupply^= EffectSupply::Arcana;
		}
		else if (effectSupply & EffectSupply::Feed)
		{
			cout << "Feed" << endl;
			effectSupply^= EffectSupply::Feed;
		}
		else if (effectSupply & EffectSupply::MajorHeal)
		{
			cout << "Major Heal" << endl;
			effectSupply^= EffectSupply::MajorHeal;
		}
		else {
			cout << "je ne fais rien" << endl;
		}
	}
}

void Supply::RemoveSupplyEffect() {
	mSupplyEffects ^= EffectSupply::Heal;
	cout << (int)mSupplyEffects << endl;
}
	

//void Drop(){ 
//	cout << "the potion cracke on the ground" << endl;
//}



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
	return mSupplyEffects;
}