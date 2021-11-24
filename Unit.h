#pragma once
#include "Item.h"
#include"Dice.h"
#include"Abilitie.h"
#include"Supply.h"
#include <string>
#include <vector>
class RoundManager;
class Unit {
public:
	Unit();
	Unit(std::string name, int maxHp,int maxMp, int str, int dex, int cons, int intel, int wis, int cha, std::uint8_t unitType=0);
	~Unit();
private:
	std::string mName;
	bool dead=false;
	int mMaxHp=1;
	int mMoney=1;
	int mCurrentHp=1;
	int mMaxMp=1;
	int mCurrentMp=1;
	float bourse=1;

	int mStrenth, mConstitution, mDexterity, mIntelligence, mWisdom, mCharisma;
	std::uint8_t mUnitType;

	void Heal(int points);
	void levelUp();
	std::vector<Abilitie> mAbilitieLearned;
	std::vector<Item> mInventory;
	std::map<ResistanceType, int> mResistance;
	Dice mDiceTwenty;
	Dice mDiceHundred;

	
public:
	
	


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
	std::uint8_t GetUnitType();
	std::vector<Unit*>& GetAllUnitsFromType(TargettingType type);
	void UseAbility(Abilitie& abilitie);

	

	// get Characteristic modifier

	int GetCharacModifier(int charac);
	



	// set variable

	void SetMoney(int value);
	void SetMaxHp(int value);
	void SetCurrentHp(int value);
	void SetMaxMp(int value);
	void SetCurrentMp(int value);

	// testing function
	void DisplayUnitType();
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

	
	bool IsKnowedAbilitie(std::string abilitie);
	int ResolutionAbilitieEffect(Abilitie& abilitie);
	int AbilitieResolution (Abilitie& abilitie);
	void SetUnitType(std::uint8_t unitType);
	void LearnAbilitie(Abilitie abilitie);
	void ForgetAbilitie(std::string abilitie);
	void DisplayAbilitieLearned();

	// target selection



	// Supply Function
	
	void UseSupply(Supply choosenSupply);
	


};
