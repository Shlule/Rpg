#include "RoundManager.h"
#include "Enums.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// puisque que roundlist est static il est instancier avant meme qu'un Roundmanager peut etre intancier donc creer au lancement du code il faut donc lui attribuer une valeur de base pour ca creation
vector<Unit*> RoundManager::roundList;

RoundManager::RoundManager(){

}
RoundManager::~RoundManager(){}

int RoundManager::GetCurrentUnit() {
	return mCurrentUnit;
}
int RoundManager::GetNumberUnit() {
	return mNumberUnit;
}
void RoundManager::SetCurrentUnit(int value) {
	 mCurrentUnit = value;
}
void RoundManager::SetNumberUnit(int value) {
	mNumberUnit = value;
}
void RoundManager::AddUnit(Unit* unit){
	roundList.push_back(unit);
}
// elle eface par le nom de l'unit� , si deux unite s'appelle pareil elle efface la premiere
void RoundManager::RemoveUnit(string unit) {
	int index;
	for (int i = 0; i < roundList.size(); i++) {
		if (unit == roundList[i]->GetName()) {
			index = i;
			break;
		}
	}
	roundList.erase(roundList.begin() + index);
}

void RoundManager::DisplayRoundlist() {
	string tempName;
	if (roundList.size() <= 0) {
		cout << "Il n'y a personne dans la rencontre" << endl;
	}
	else {
		for (int i = 0; i < roundList.size(); i++) {
			tempName = roundList[i]->GetName();
			cout << tempName << endl;
		}
	}
}

void RoundManager::NewRound() {
	if (roundList.size() == 0) {
		cout << "il n'y a pas d'unit� dans la liste" << endl;
	}
	else {
			// la Fonction vas juste trier avec l'oprateur< que j'ai surcharg� pour trier des membre class Unit
		sort(roundList.begin(), roundList.end());
		
	}
}