#pragma once
#include"Unit.h"
#include<vector>
#include<string>
class RoundManager
{
public:
	//constructor and destructor
	RoundManager();
	~RoundManager();
	int GetCurrentUnit();
	int GetNumberUnit();
	void SetCurrentUnit(int value);
	void SetNumberUnit(int value);
	void NewRound();
	void AddUnit(Unit* unit);
	void DisplayRoundlist();
	void RemoveUnit(std::string unit);
	static std::vector<Unit*> roundList;
private:
	int mCurrentUnit;
	int mNumberUnit;
	
};

