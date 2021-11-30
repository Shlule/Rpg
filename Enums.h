#pragma once
namespace EffectSupply {
	enum Effect {
		Heal = 1 << 0,
		MajorHeal = 1 << 1,
		Cure = 1 << 2,
		Feed = 1 << 3,
		Arcana = 1 << 4,
		Buff = 1 << 5,
		Debuff = 1 << 6,

	};
}
namespace UnitType {
	enum Type {
		Ally=1<<0,
		Ennemie=1<<1,
		Player=1<<2,
		Beast=1<<3,
		Aberation=1<<4,
		Fielon=1<<5,
		Mecha=1<<6,
		Celeste=1<<7,

	};
}

enum class ChooseSpellStateMachine {
	Waiting,Init,DispSumUp
};
// version avec des map similaire abilitie
enum class SupplyEffect {
	Heal, majorHeal, Cure, Feed, Buff, Arcana, Debuff,

};
enum class Effect {
	Burn, Blinded, AcidSolving, Freeze, Paralized, Grounded, Charmed, Scared, Enraged, Bleed, Cure,
};

enum class TargettingType {
	Self, AllAllies, AllEnemie, AllExceptMe, MeAndOneAlly, OneEnnemie, OneAlly, OneUnit,
};
enum class AbilitieType {
	Offensive,Heal,Defencive,support
};
enum class ResistanceType {
	
	Poison,Cold,Fire,Bleeding,Stun,Malus,Death

};

