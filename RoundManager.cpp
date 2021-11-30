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


int RoundManager::GetNbAllyUnit() {
	return nbAllyUnit;
}
int RoundManager::GetNbEnnemyUnit() {
	return nbEnnemyUnit;
}

void RoundManager::AddUnit(Unit* unit){
	if (unit->GetUnitType() & UnitType::Ally) {
		nbAllyUnit+=1;
	}
	if (unit->GetUnitType() & UnitType::Ennemie) {
		nbEnnemyUnit+=1;
	}
	roundList.push_back(unit);
}
// elle eface par le nom de l'unité , si deux unite s'appelle pareil elle efface la premiere
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
		cout << "il n'y a pas d'unité dans la liste" << endl;
	}
	else {
			// la Fonction vas juste trier avec l'oprateur< que j'ai surchargé pour trier des membre class Unit
		sort(roundList.begin(), roundList.end());
		
	}
}

void RoundManager::PlayEncounter() {
	int nbEnnemiesDead=0;
	int nbAlliesDead=0;
	bool haveEnnemy=false;
	bool haveAlly=false;
	bool endEncounter = false;
	if (roundList.size() < 2) {
		cout << "il n'y a pas asser de personne pour faire une Rencontre il faut etre deux" << endl;

	}
	for (int i = 0; i < roundList.size(); i++) {
		if (roundList[i]->GetUnitType() == UnitType::Ennemie) {
			haveEnnemy = true;
		}
		
		if (roundList[i]->GetUnitType() == UnitType::Ally) {
			haveAlly = true;
		}

	
	}
	
	
	if (haveEnnemy && haveAlly) {
		NewRound();
		while (!endEncounter) {
			if (nbAlliesDead == nbAllyUnit) {
				cout << " game over you dead" << endl;
				endEncounter = true;
				break;
				
			}
			if (nbEnnemiesDead == nbEnnemyUnit) {
				cout << "congratulation you win this battle" << endl;
				endEncounter = true;
				break;
			}
			else
			{
				nbAlliesDead = 0;
				nbEnnemiesDead = 0;
				for (int i = 0; i < roundList.size(); i++) {
					if (roundList[i]->IsDead() == false && roundList[i]->havePlayedThisTurn() == false) {
						roundList[i]->Play();
					}
					if (roundList[i]->IsDead() == true) {
						if (roundList[i]->GetUnitType() & UnitType::Ally){
							nbAlliesDead++;
						}
						if (roundList[i]->GetUnitType() & UnitType::Ennemie) {
							nbEnnemiesDead++;
						}
					}
				}
			}
			

		}
	}
}