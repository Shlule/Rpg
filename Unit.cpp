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
		int playerChoice;
		Abilitie abilitieChoice;
		cout << "please select an action\n1 :Basic Attack\n2 :Use Abilities\n3 :Use Supply"<<endl;
		playerChoice = CheckChoice(1, 3);
		switch (playerChoice)
		{
		case 1:
			BasicAttack(2, 8);
			break;
		case 2:
			cout << "please select abilitie" << endl;
			for (int i = 0; i < mAbilitieLearned.size(); i++) {
				cout << i + 1 << " :" << mAbilitieLearned[i].GetName() << endl;
			}
			// demande au player qu'elle sort lancer
			playerChoice = CheckChoice(1, mAbilitieLearned.size());
			abilitieChoice = mAbilitieLearned[playerChoice - 1];
			cout << " Are you sure to Use This?\n1 :Yes\n2 : No";
			playerChoice = CheckChoice(1, 2);
			if (playerChoice == 1) {
				UseAbility(abilitieChoice);
			}
			else
			{
				Play();
			}
			break;
		case 3:
			cout << "please select Supply" << endl;
			for (int i = 0; i < mInventory.size(); i++) {
				cout << i + 1 << " :" << mInventory[i].GetName() << endl;
			}
			// demande au player qu'elle sort lancer
			playerChoice = CheckChoice(1, mInventory.size());
			cout << " Are you sure to Use This?\n1 :Yes\n2 : No";
			playerChoice = CheckChoice(1, 2);
			if (playerChoice == 1) {
				UseSupply(mInventory[playerChoice - 1]);
				RemoveItem(mInventory[playerChoice - 1].GetName());
			}
			else
			{
				Play();
			}
			break;
			break;
		default:
			break;
		}

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
int Unit::CheckChoice(int bornInf, int bornSup){
	int playerChoice;
	cin >> playerChoice;
	if (playerChoice<bornInf || playerChoice>bornSup) {
		cout << " please enter a number between " << bornInf << " and " << bornSup << endl;
		CheckChoice(bornInf, bornSup);

	}
	else {
		
		return playerChoice;
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
void Unit::BasicAttack(int diceCount , int diceFaces) {
	int totalDamage=0;
	int playerChoice;
	vector<Unit*> affectableUnits = GetAllUnitsFromType(TargettingType::OneEnnemie);
	Dice tempDice(diceFaces);
	for (int i = 0; i < diceCount; i++) {
		totalDamage += tempDice.roll();
	}

	for (int i = 0; i < affectableUnits.size(); i++) {
		cout << i + 1 << " :" << affectableUnits[i]->GetName();
	}
	playerChoice = CheckChoice(1, affectableUnits.size());
	affectableUnits[playerChoice - 1]->TakeDammage(totalDamage);

}
void Unit::Heal(int heal) {
	if (mCurrentHp + heal > mMaxHp) {
		mCurrentHp = mMaxHp;
	}
	else {
		mCurrentHp += heal;

	}
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

void Unit::AddItem(Supply item) {
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
			return true;	
		}
		else {
			return false;
		}
	}
}
// this function Make the resolution of an abilitie return the total value of an heal or total value of damage
int Unit::AbilitieResolution(Abilitie& abilitie) {
	// testing if abilitie is know or current mp > manacost
	if (IsKnowedAbilitie(abilitie.GetName()) == false || mCurrentMp < abilitie.GetManacost()) {
		// normalement le seul ca ou c'est vrai n'est que qunad le player a plus de mana.
		cout << " je n'ai plus de mana" << endl;
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
	int playerChoice;
	// je creer un vector qui contient toutes les unit? concerne par le targetType de l'abilitie
	vector<Unit*> affectableUnits = GetAllUnitsFromType(abilitie.GetTargetType());
	// je regarde si le sort est offensif ou pas
	if (abilitie.GetAbilitieType() == AbilitieType::Offensive) {
		// je regarde Le TagetType de l'abilit?
	// si le TargetType est OneEnnemie  Je dois choisir un Element dans affectableUnits
		if (abilitie.GetTargetType() == TargettingType::OneAlly || abilitie.GetTargetType() == TargettingType::MeAndOneAlly || abilitie.GetTargetType() == TargettingType::OneEnnemie || abilitie.GetTargetType() == TargettingType::OneUnit) {
			cout << "choisi une cible" << endl;
			for (int i = 0; i < affectableUnits.size(); i++) {
				cout << i + 1 << " :" << affectableUnits[i]->GetName();
			}
			playerChoice = CheckChoice(1, affectableUnits.size());
			affectableUnits[playerChoice-1]->TakeDammage(AbilitieResolution(abilitie));
			mCurrentMp -= abilitie.GetManacost();
		}
		else {
			for (int i = 0; i < affectableUnits.size(); i++) {
				affectableUnits[i]->TakeDammage(AbilitieResolution(abilitie));
				mCurrentMp -= abilitie.GetManacost();

			}

		}
	}
	else
	{
		// je regarde Le TagetType de l'abilit?
	// si le TargetType est OneEnnemie  Je dois choisir un Element dans affectableUnits
		if (abilitie.GetTargetType() == TargettingType::OneAlly || abilitie.GetTargetType() == TargettingType::MeAndOneAlly || abilitie.GetTargetType() == TargettingType::OneEnnemie || abilitie.GetTargetType() == TargettingType::OneUnit) {
			cout << "choisi une cible" << endl;
			for (int i = 0; i < affectableUnits.size(); i++) {
				cout << i + 1 << " :" << affectableUnits[i]->GetName();
			}
			playerChoice = CheckChoice(1, affectableUnits.size());
			affectableUnits[playerChoice-1]->Heal(AbilitieResolution(abilitie));
			mCurrentMp -= abilitie.GetManacost();
		}
		else {
			for (int i = 0; i < affectableUnits.size(); i++) {
				affectableUnits[i]->Heal(AbilitieResolution(abilitie));
				mCurrentMp -= abilitie.GetManacost();

			}

		}
	}
	
	
	// pareil pour TargetType OneAlly and OneUnit, MeAndOneAlly 
	//creer une fonction qui permet de selection une unit? dans le vecteur
	//Resoude l'abilit? sur la target choisi
	//Sinon Resoudre l'abilitie Sur tout le vecteur affectableUnits	
}
// permet de stocker dans une vector<Unit*> tout les Unite qui peuvent etre cible par le Targetting Type de l'abilitt? ou supply
vector<Unit*> Unit::GetAllUnitsFromType(TargettingType type) {
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
			mask = UnitType::Aberation| UnitType::Ally| UnitType::Beast| UnitType::Celeste| UnitType::Ennemie| UnitType::Fielon| UnitType::Mecha;
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
			mask = 256;
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

