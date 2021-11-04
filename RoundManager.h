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
private:
	int currentUnit;
	int numberUnit;
	std::vector<Unit> roundList;
};

