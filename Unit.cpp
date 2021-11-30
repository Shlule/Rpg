#include "Unit.h"
#include<iostream>
#include<vector>
#include "RoundManager.h"
using namespace std;
typedef std::map<Effect, int>::iterator it_type;


Unit::Unit(string name, int maxHp,int maxMp, int str, int dex, int cons, int intel, int wis, int cha,uint8_t unitType) {
	mName = name;
	mMaxHp = maxHp;
	mMaxMp = maxMp;
	mCurrentMp = maxMp;
	mCurrentHp = maxHp;
	mStrenth = str;
	mDexterity = dex;
	mConstitution = cons;
	mIntelligence = intel;
	mWisdom = wis;
	mCharisma = cha;
	mUnitType = unitType;
	mDiceTwenty = Dice(20);


}
Unit::Unit() {
	
}

Unit::~Unit() 
{
	mInventory.~vector();
};
// Dice initialization
// main fonction 

void Unit::Play() {
	if (mUnitType & UnitType::Player) {
		cout << "a moi de jouer" << endl;
	}
	else if(mUnitType & UnitType::Ally)
	{
		cout << "je vais t'assister" << endl;
	}
	else
	{
		cout << "je vais te tapper" << endl;
	}
	
}

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
int Unit::GetCurrentHp() {
	return mCurrentHp;
}
float Unit::GetBourse() {
	return bourse;
}
uint8_t Unit::GetUnitType() {
	return mUnitType;
}
bool Unit::IsDead(){
	return dead;
}
bool Unit::havePlayedThisTurn() {
	return playedTurn;
}
void Unit::LearnAbilitie(Abilitie abilitie) {
	mAbilitieLearned.push_back(abilitie);
}
void Unit::ForgetAbilitie(string abilitie) {
	int index = -1;
	for (int i = 0; i < mAbilitieLearned.size(); i++) {
		if (abilitie == mAbilitieLearned[i].GetName()) {
			index = i;
			break;
		}
	}
	if (index != -1) {
		mAbilitieLearned.erase(mAbilitieLearned.begin() + index);
	}
	else {
		cout << "You tried to erase an ability " << abilitie << ", that didn't exit in the inventory of unit " << mName << '\n';
	}

}
void Unit::SetUnitType(uint8_t unitType) {
	mUnitType = unitType;
}
void Unit::DisplayAbilitieLearned() {
	string tempName;
	if (mAbilitieLearned.size() <= 0) {
		cout << "le spellBook est vide" << endl;
	}
	else {
		for (int i = 0; i < mAbilitieLearned.size(); i++) {
			tempName = mAbilitieLearned[i].GetName();
			cout << tempName << endl;
		}
	}
}
// modifier getter Il lui faut le getter d'une caracteristique  GetCharacModifier(GetDexterity())

int Unit::GetCharacModifier(int charac) {
	return(charac - 10) / 2;
}

// voici maintenant les tant attendu Setter

void Unit::SetMoney(int value) { mMoney = value; }
void Unit::SetCurrentHp(int value) { mCurrentHp = value; }
void Unit::SetMaxHp(int value) { mMaxHp = value; }
void Unit::SetCurrentMp(int value) { mCurrentMp = value; }
void Unit::SetMaxMp(int value) { mMaxMp = value; }

// surchage operator je mais un > pour trier dans l'odre decroissant pour le sort()
bool Unit::operator<(Unit& other) {
	return RollInitiative(mDiceTwenty) > other.RollInitiative(other.mDiceTwenty);
}

// Game fonction

// permet de soigner l'unite elle meme ou  une autre unite

void Unit::Heal(int points) {
	mCurrentHp = min((mCurrentHp + points), mMaxHp);
	DisplayLife();
}

void Unit::TakeDammage(int damage) {
	mCurrentHp = max((mCurrentHp - damage), 0);
	cout << max((mCurrentHp-damage), 0) << endl;
	if (mCurrentHp == 0) {
		cout << mName <<" is dead"<< '\n';
		dead = true;
	}
	else {
		DisplayLife();
	}
}

void Unit::DisplaySumUp() {
	cout << mName << " you have the following characteristics\n";
	cout << "Force : " << mStrenth << '\n';
	cout << "Dexterity : " << mDexterity << '\n';
	cout << "Constitution : " << mConstitution << '\n';
	cout << "Int : " << mIntelligence << '\n';
	cout << "Wisdom : " << mWisdom << '\n';
	cout << "Charisma : " << mCharisma << '\n';
}

void Unit::DisplayLife() {
	cout << mName << " has " << mCurrentHp << " life points\n";

}

// item manager

void Unit::AddItem(Item item) {
	mInventory.push_back(item);
}

// debugging function
void Unit::DisplayUnitType() {
	if (mUnitType & UnitType::Ally) {
		cout << "je suis ton copain" << endl;
	}
	else {
		cout << "je vais te tuer" << endl;
	}
}

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
		return false;
	}
	else {
		for (int i = 0; i < mInventory.size(); i++) {
			if (item == mInventory[i].GetName()) {
				cout << "I have this item" << endl;
				return true;
			}
		}
	}
	cout << "i haven't this item" << endl;
	return false;
}


void Unit::RemoveItem(string item) {
	int index = -1;
	for (int i = 0; i < mInventory.size(); i++) {
		if (item == mInventory[i].GetName()) {
			index = i;
			break;
		}
	}
	if (index != -1) {
		mInventory.erase(mInventory.begin() + index);
	}
	else {
		cout << "You tried to erase an item "<<item<<", that didn't exit in the inventory of unit " << mName<<'\n';
	}
}


int Unit::RollInitiative(Dice de) {
	return de.roll()+ GetCharacModifier(GetDexterity());


}

bool Unit::IsKnowedAbilitie(string abilitie) {
	for (int i = 0; i < mAbilitieLearned.size(); i++) {
		if (abilitie == mAbilitieLearned[i].GetName()) {
			cout << "je suis connu" << endl;
			return true;	
		}
		else {
			return false;
			cout << "je ne connais pas ce sort" << endl;
		}
	}
}

int Unit::AbilitieResolution(Abilitie& abilitie) {
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

void Unit::UseAbility(Abilitie& abilitie) {
	// je creer un vector qui contient toutes les unité concerne par le targetType de l'abilitie
	vector<Unit*>& affectableUnits = GetAllUnitsFromType(abilitie.GetTargetType());

	cout << affectableUnits.size() << endl;
	// je regarde Le TagetType de l'abilité
	// si le TargetType est OneEnnemie  Je dois choisir un Element dans affectableUnits
	if (abilitie.GetTargetType()== TargettingType::OneAlly || abilitie.GetTargetType() == TargettingType::MeAndOneAlly || abilitie.GetTargetType() == TargettingType::OneEnnemie || abilitie.GetTargetType() == TargettingType::OneUnit){
		cout << "choisi une cible" << endl;
		for (int i = 0; i < affectableUnits.size(); i++) {
			cout << "caca" << endl;
		}

	}
	// pareil pour TargetType OneAlly and OneUnit, MeAndOneAlly 
	//creer une fonction qui permet de selection une unité dans le vecteur
	//Resoude l'abilité sur la target choisi
	//Sinon Resoudre l'abilitie Sur tout le vecteur affectableUnits
	


	
	
}
// permet de stocker dans une vector<Unit*> tout les Unite qui peuvent etre cible par le Targetting Type de l'abilitté ou supply
vector<Unit*>& Unit::GetAllUnitsFromType(TargettingType type) {
	vector<Unit*> units= RoundManager::roundList;
	vector<Unit*> compatibleUnits;
	uint8_t mask;
	switch (type)
	{
		case TargettingType::AllAllies:
			//Find all allies
			mask = UnitType::Ally;
			break;
		case TargettingType::AllEnemie:
			mask = UnitType::Ennemie;
			break;
		case TargettingType::AllExceptMe:
			mask = 256^UnitType::Player;
			break;
		case TargettingType::MeAndOneAlly:
			mask = UnitType::Player | UnitType::Ally;
			break;
		case TargettingType::OneAlly:
			mask = UnitType::Ally;
			break;
		case TargettingType::OneEnnemie:
			mask = UnitType::Ennemie;
			break;
		case TargettingType::OneUnit:
			mask = 0;
			break;
		default:
		break;
	}

	for (int u = 0; u < units.size(); u++) {
		if (units[u]->GetUnitType() & mask) {
			compatibleUnits.push_back(units[u]);
			
		}
	
	}
	
	cout <<compatibleUnits.size() << endl;
	return compatibleUnits;
	
}



// Suplly Function

void Unit::UseSupply(Supply choosenSupply) {
	if (IsInIventory(choosenSupply.GetName()) == false) {
		cout << "i can't use this supply" << endl;
	}
	else {
		if (choosenSupply.GetEffect() & EffectSupply::Heal) {
			if (mCurrentHp == mMaxHp) {
				cout << "i'm full life" << endl;
			}
			else {
				int x;
				 x=choosenSupply.SupplyHeal(4, 6);
				 if (x += mCurrentHp > mMaxHp) {
					 mCurrentHp = mMaxHp;
				 }
				 else { mCurrentHp += x; }
			}
			
		}
	}
}

