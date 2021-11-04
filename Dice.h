#pragma once
#include <random>
#include<iostream>
#include<functional>
#include<chrono>
#include<ctime>
class Dice
{
public:
	Dice(int etendue = 20);
	~Dice();
	int roll();
private:
	int mEtendue;
	
};

