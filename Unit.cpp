#include "Unit.h"
#include<iostream>
#include<vector>
using namespace std;
typedef std::map<Effect, int>::iterator it_type;


Unit::Unit(string name, int maxHp, int str, int dex, int cons, int intel, int wis, int cha) {
	mName = name;
	mMaxHp = maxHp;
	mCurrentHp = maxHp;
	mStrenth = str;
	mDexterity = dex;
	mConstitution = cons;
	mIntelligence = intel;
	mWisdom = wis;
	mCharisma = cha;
	mDiceTwenty = Dice(20);


}
Unit::Unit() {
	mDiceTwenty = Dice(20);
}

Unit::~Unit() 
{
	mInventory.~vector();
};
// Dice initialization




//getter

string Unit::GetName() {
	return mName;
}
int Unit::GetStrength() {
	return mStrenth;
}
int Unit::GetDexterity() {
	return mDexterity;
}
int Unit::GetConstitution() {
	return mConstitution;
}
int Unit::GetIntelligence() {
	return mIntelligence;
}
int Unit::GetWisdom() {
	return mWisdom;
}
int Unit::GetCharisma() {
	return mCharisma;
}
int Unit::GetMaxHp() {
	return mMaxHp;
}
float Unit::GetBourse() {
	return bourse;
}
// modifier getter Il lui faut le getter d'une caracteristique  GetCharacModifier(GetDexterity())

int Unit::GetCharacModifier(int charac) {
	return(charac - 10) / 2;
}

// surchage operator
bool Unit::operator<(Unit& other) {
	return RollInitiative(mDiceTwenty) < other.RollInitiative(other.mDiceTwenty);
}



// set variable

void Unit::SetMoney(int value) { mMoney = value; }

// Game fonction

// permet de soigner l'unite elle meme ou  une autre unite

void Unit::Heal(int points) {
	mCurrentHp = min((mCurrentHp + points), mMaxHp);
	DisplayLife();
}

void Unit::TakeDammage(int damage) {
	mCurrentHp = max((mCurrentHp - damage), 0);
	if (mCurrentHp == 0) {
		cout << "You're dead " << mName << '\n';
	}
	else {
		DisplayLife();
	}
}

void Unit::DisplaySumUp() {
	cout << mName << "has the following characteristics\n";
	cout << "Force : " << mStrenth << '\n';
	cout << "Dexterity : " << mDexterity << '\n';
	cout << "Constitution : " << mConstitution << '\n';
	cout << "Int : " << mIntelligence << '\n';
	cout << "Wisdom : " << mWisdom << '\n';
	cout << "Charisma : " << mCharisma << '\n';
}

void Unit::DisplayLife() {
	cout << mName << "has" << mCurrentHp << "life points\n";

}

// item manager

void Unit::AddItem(Item item) {
	mInventory.push_back(item);
}

// debugging function

void Unit::DisplayInventory() {
	string tempName;
	if (mInventory.size() <= 0) {
		cout << "l'inventaire est vide" << endl;
	}
	else {
		for (int i = 0; i < mInventory.size(); i++) {
			tempName = mInventory[i].GetName();
			cout << tempName << endl;
		}
	}
	

}
float Unit::AddMoney(float value) {

	return bourse += value;

}
float Unit::RemoveMoney(float value) {
	if (bourse > 0) {
		return bourse -= value;

	}

}
bool Unit::IsInIventory(string item) {
	if (mInventory.size() <= 0) {
		cout << "l'inventaire est vide" << endl;
	}
	else {
		for (int i = 0; i < mInventory.size(); i++) {
			if (item == mInventory[i].GetName()) {
				cout << "I have this item" << endl;
				return true;
			}
			else {
				cout << "I haven't this item" << endl;
				return false;
			}
		}
	}
}


void Unit::RemoveItem(string item) {
	int index;
	for (int i = 0; i < mInventory.size(); i++) {
		if (item == mInventory[i].GetName()) {
			index = i;
			break;
		}
	}
	mInventory.erase(mInventory.begin()+index);
}


int Unit::RollInitiative(Dice de) {
	return de.roll()+ GetCharacModifier(GetDexterity());


}
void Unit::AddAbilitie(Abilitie abilitie) {
	mAbilitieLearned.push_back(abilitie);
}
bool Unit::IsKnowedAbilitie(string abilitie) {
	for (int i = 0; i < mAbilitieLearned.size(); i++) {
		if (abilitie == mAbilitieLearned[i].GetName()) {
			cout << "je suis connu" << endl;
			return true;
			
		}
		else {
			return false;
			cout << "connard" << endl;
		}
	}
}

int Unit::GetAbilitieDamage(Abilitie& abilitie) {
	// testing if abilitie is know or current mp > manacost
	if (IsKnowedAbilitie(abilitie.GetName()) == false || mCurrentMp < abilitie.GetManacost()) {
		return-1;
	}
	else {
		int effectDamage = 0;
		int totalDamage = 0;
		Dice tempDice(abilitie.GetDiceFaces());
		effectDamage = ResolutionAbilitieEffect(abilitie);
		for (int i = 0; i < abilitie.GetDiceCount(); i++) {
			totalDamage += tempDice.roll();
		}
		totalDamage += effectDamage;
		cout << totalDamage << endl;
		return totalDamage;
	}
}

int Unit::ResolutionAbilitieEffect(Abilitie& abilitie) {
	it_type iterator;
	// getmEffect revoie une copie de la map donc obligatoire de faire une variable temporaire pour faire la comparason por le for car sinon il compare deux copie 
	map<Effect, int> tempMapEffect = abilitie.GetmEffects();
	int totalDamage = 0;

	for (iterator = tempMapEffect.begin(); iterator != tempMapEffect.end(); iterator++) {
		if (abilitie.TestingChanceResolutionEffect(iterator->second)) {
			totalDamage += abilitie.ResolutionEffect(iterator->first);
		}
	}
	cout << totalDamage << endl;
	return totalDamage;
}

// Suplly Function

int Unit::UseSupply(Supply choosenSupply) {
	if (!IsInIventory(choosenSupply.GetName())) {
		cout << "i can't use this supply" << endl;
	}
	else {
		if (choosenSupply.GetEffect() & EffectSupply::Heal) {
			cout << choosenSupply.SupplyHeal(4, 6) << endl;
			return choosenSupply.SupplyHeal(4, 6);
		}
	}
}
