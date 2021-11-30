#pragma once
#include"Unit.h"
#include<vector>
#include<string>
class RoundManager
{
private:
	
	int nbEnnemyUnit=0;
	int nbAllyUnit=0;

public:
	//constructor and destructor
	RoundManager();
	~RoundManager();

	int GetNbAllyUnit();
	int GetNbEnnemyUnit();
	void NewRound();
	void AddUnit(Unit* unit);
	void DisplayRoundlist();
	void RemoveUnit(std::string unit);
	void PlayEncounter();
	static std::vector<Unit*> roundList;

	
};

