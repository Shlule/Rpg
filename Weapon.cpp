#include "Weapon.h"
#include <iostream>
using namespace std;

// constructor and destructor

Weapon::Weapon(string name, int price, int weight, int damage, float range) :Item(name, price, weight, false, true) {
	
	mDamage = damage;
	mRange = range;
}

Weapon::~Weapon() {};

//void Drop() {
//	cout << "that make a metallic sound" << endl;
//}