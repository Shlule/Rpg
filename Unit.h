#pragma once
#include "Item.h"
#include"Dice.h"
#include"Abilitie.h"
#include"Supply.h"
#include <string>
#include <vector>
class Unit {
public:
	Unit();
	Unit(std::string name, int maxHp, int str, int dex, int cons, int intel, int wis, int cha);
	~Unit();
private:
	bool dead=false;
	int mMaxHp=1;
	std::string mName;
	int mMoney=1;
	int mCurrentHp=1;
	int mMaxMp=1;
	int mCurrentMp=1;
	float bourse=1;

	int mStrenth, mConstitution, mDexterity, mIntelligence, mWisdom, mCharisma;

	void Heal(int points);
	void levelUp();

	
public:

	std::vector<Abilitie> mAbilitieLearned;
	std::vector<Item> mInventory;
	Dice mDiceTwenty;
	Dice mDiceHundred;

	bool operator<(Unit& other);
	
	

	// get variable

	float GetBourse();
	std::string GetName();
	int GetStrength();
	int GetDexterity();
	int GetConstitution();
	int GetIntelligence();
	int GetWisdom();
	int GetCharisma();
	bool GetDead();
	int GetMaxHp();
	int GetCurrentHp();
	int GetMaxMp();
	int GetCurrentMp();

	// get Characteristic modifier

	int GetCharacModifier(int charac);
	



	// set variable

	void SetMoney(int value);
	void SetMaxHp(int value);
	void SetCurrentHp(int value);
	void SetMaxMp(int value);
	void SetCurrentMp(int value);

	// testing function

	void DisplaySumUp();
	void DisplayLife();
	void DisplayInventory();

	// battle function 

	int RollInitiative(Dice de);

	void TakeDammage(int damage);
	void isDead();
	void basicAttack(int damage);
	void AddItem(Item item);

	// trade function
	// buy and sell is in relation with Unit a
	float AddMoney(float value);
	float RemoveMoney(float value);
	void RemoveItem(std::string item);
	bool IsInIventory(std::string Item);

	// Abilitie fonction

	void AddAbilitie(Abilitie abilitie);
	bool IsKnowedAbilitie(std::string abilitie);
	int ResolutionAbilitieEffect(Abilitie& abilitie);
	int GetAbilitieDamage (Abilitie& abilitie);

	// Supply Function
	
	int UseSupply(Supply choosenSupply);
	


};
