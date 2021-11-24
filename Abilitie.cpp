#include "Abilitie.h"
#include<iostream>
using namespace std;
typedef std::map<Effect, int>::iterator it_type;


//constructor and destructor

Abilitie::Abilitie(string name, std::map<Effect, int> effects ,int manacost, int diceCount, int diceFaces,TargettingType targetType , AbilitieType abilitieType ) {
	mName = name;
	mEffects = effects;
	mDiceCount = diceCount;
	mDiceFaces = diceFaces;
	mManacost = manacost;
	mAbilitieType = abilitieType;
	mTargetType = targetType;

	
}
Abilitie::~Abilitie() {  }


int Abilitie::GetChanceEffectWork(Effect choosenEffect) {
	// check if the choosen effect exist in the ability, return -1 if he don't find
	if (mEffects.find(choosenEffect) == mEffects.end()) {
		cout << mName << " doesn't have this effect\n";
		return -1;
	}
	else {
		//return the value of the key if he find it 
		return mEffects[choosenEffect];
	}
	
}

//getter

string Abilitie::GetName() {
	return mName;
}
int Abilitie::GetDiceCount() {
	return mDiceCount;
}
int Abilitie::GetDiceFaces() {
	return mDiceFaces;
}
int Abilitie::DotDamage(int damage) {
	return damage;
}
int Abilitie::GetManacost() {
	return mManacost;
}
AbilitieType Abilitie::GetAbilitieType() {
	return mAbilitieType;
}

map<Effect, int> Abilitie::GetmEffects() {
	return mEffects;
}
// next etape faire en sorte que les effect affecte l'unite blesse pendant un nombre de tour (une mecanique comme darkest dungeon)
int Abilitie::ResolutionEffect(Effect effect) {
	switch (effect) {
	case Effect::Burn:
		cout << "tu brule" << endl;
		return DotDamage(12);
		break;
	case Effect::AcidSolving:
		cout << "tu fond" << endl;
		return 0;
		break;

	case Effect::Freeze:
		cout << "tu gele" << endl;
		return 0;
		break;
	case Effect::Paralized:
		cout << "tu est paralyzed" << endl;
		return 0;
		break;

	case Effect::Blinded:
		cout << "tu est aveugle" << endl;
		return 0;
		break;

	case Effect::Grounded:
		cout << "tu est immobiliser" << endl;
		return 0;
		break;

	case Effect::Enraged:
		cout << "tu est enrage" << endl;
		return 0;
		break;

	case Effect::Charmed:
		cout << "tu est beau" << endl;
		return 0;
		break;

	case Effect::Scared:
		cout << "tu est appeuré" << endl;
		return 0;
		break;
	case Effect::Bleed:
		cout << "tu saigne" << endl;
		return DotDamage(12);
		break;
	case Effect::Cure:
		cout << "tu ne souffre plus" << endl;
		return 0;
		break;

	}
}
void Abilitie::DispmEffects() {
	it_type iterator;
	for (iterator = mEffects.begin(); iterator != mEffects.end(); iterator++) {
		cout << "mon pourcentage effet :  " << iterator->second << "\n";
	}
}
void Abilitie::DisplayAbilitieSumUp() {
	string target;
	string effectType;
	switch (mTargetType)
	{
	case TargettingType::Self:
		target = " self";
		break;
	case TargettingType::AllAllies:
		target = " all allies";
		break;
	case TargettingType::AllEnemie:
		target = " all ennemies";
		break;
	case TargettingType::AllExceptMe:
		target = " all unit expect me";
		break;
	case TargettingType::MeAndOneAlly:
		target = " me and one ally";
		break;
	case TargettingType::OneEnnemie:
		target = " oneEnnemy";
		break;
	case TargettingType::OneAlly:
		target = " one Ally";
		break;
	case TargettingType::OneUnit:
		target = " one Unit";
		break;
	default:
		cout << " no targetting type";
		break;
	}
	switch (mAbilitieType)
	{
	case AbilitieType::Offensive:
		effectType = " dammage";
		break;
	case AbilitieType::Heal:
		effectType = " heal";
		break;
	case AbilitieType::Defencive:
		effectType = " dammage";
		break;
	case AbilitieType::support:
		effectType = " heal";
		break;
	default:
		break;
	}
	cout << "this spell cost " << mManacost<< endl;
	cout << "make " << mDiceCount << " de(s) " << mDiceFaces <<" of "<< effectType << endl;
	cout << "and targeting" << target << endl;
}

TargettingType Abilitie::GetTargetType()
{
	return mTargetType;
}

bool Abilitie::TestingChanceResolutionEffect(int value) {
	Dice mDice = Dice(100);
	return (value >= mDice.roll());

}

