#include "Dice.h"
#include<iostream>

using namespace std;

Dice::Dice(int etendue) {
	mEtendue = etendue;
}

Dice::~Dice(){}

int Dice::roll() {

	unsigned seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	int a;
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> distribution(1, mEtendue);
	a = distribution(generator);
	return a;
}