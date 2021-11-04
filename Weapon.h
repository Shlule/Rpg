#pragma once
#include "Item.h"
enum class WeaponType {
	SWORD,KNIFE,AXE,BOW,STAFF
};

class Weapon : public Item
{
private:
	WeaponType mType;
	int mDamage;
	float mRange;

public:
	// contructor , destructor
	Weapon(std::string name, int price, int weight, int damage, float range);
	~Weapon();
};

