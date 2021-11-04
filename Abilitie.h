#pragma once
#include"Dice.h"
#include"Enums.h"
#include<string>
#include <map>


class Abilitie
{
public:
	//constructor and destructor
	Abilitie(std::string name , std::map<Effect, int> effects,int manacost, int diceCount = 0, int diceFaces = 6, TargettingType targetType = TargettingType::AllExceptMe, AbilitieType abilitieType = AbilitieType::MagicalRanged);
	~Abilitie();
	
	int GetChanceEffectWork(Effect choosenEffect);


	std::map<Effect, int> GetmEffects();
	int GetDiceCount();
	int GetDiceFaces();
	int GetManacost();
	std::string GetName();
	bool TestingChanceResolutionEffect(int value);
	int ResolutionEffect(Effect effect);
	int DotDamage(int damage);
	void DispmEffects();
	

private:
	int mManacost;
	int mDiceCount;
	int mDiceFaces;
	std::string mName;
	TargettingType mTargetType;
	AbilitieType mType;
	// je creer un dictionnaire qui associe un effet a un entier, l'entier represente le pourcentage de chance de faire l'effet;
	std::map<Effect, int> mEffects;
};

