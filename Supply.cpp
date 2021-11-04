#include "Supply.h"
#include<iostream>

using namespace std;

Supply::Supply(std::string name, int price, uint8_t effects , int weight) : Item(name, price, true ,true ,weight) {

	mSupplyEffects = effects;
}
Supply::~Supply() {};


map<SupplyEffect, int> Supply::GetSupplyEffect() {
	return mSupplyEffect;
}
int Supply::ResolutionSupplyEffect(SupplyEffect supplyEffect) {
	switch (supplyEffect) {
	case SupplyEffect::Heal:
		return SupplyHeal(4,8);
		break;
	case SupplyEffect::majorHeal:
		return SupplyHeal(6, 10);
		break;
	case SupplyEffect::Feed:
		return 0;
		break;
	case SupplyEffect::Debuff:
		return 0;
		break;
	case SupplyEffect::Cure:
		return 0;
		break;
	case SupplyEffect::Buff:
		return 0;
		break;
	case SupplyEffect::Arcana:
		return 0;
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
void Supply::SetEffect(uint8_t effect){
	mSupplyEffects = effect;

}
uint8_t Supply::GetEffect() {
	return mSupplyEffects;
}